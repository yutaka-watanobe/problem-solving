#include <iostream>
#include <algorithm>

using namespace std;

/*
  check @ uva10498
  
  A : m*n の行列   制約不等式の係数を表す
  x : n 次ベクトル  解を表す
  b : m*1 の行列   制約不等式の右辺
  c : n 次ベクトル  目的関数の係数

  線形計画問題
    A * (transpose x) <= b
    xi >= 0 (i=0..n-1)
    f = (x, c)

    で、f を最大化せよ
*/

// 人工変数導入の罰金
// あまりに大きくしすぎると、桁落ちが発生するので注意
const double AV_PENALTY = 1e+5;

void mul(int m, int n, double **matrix, int target, double d){
  for(int j = 0; j < n; ++j)
    matrix[target][j] *= d;
}

void mulAdd(int m, int n, double **matrix,
            int from, int to, double d){
  for(int j = 0; j < n; ++j)
    matrix[to][j] += matrix[from][j] * d;
}

// (b'| a'| s )
// (--+-------) という感じに変換
// (  | c'    )
void changeOptLP(int m, int n,
                 const double * const *a, const double *b, const double *c,
                 double **ret, int *solID, int *remID){
  int row = m + 1;
  int col = 1 + n + m;
  
  // c をコピー
  fill(ret[row-1], ret[row-1] + col, 0.0);
  copy(c, c+n, ret[row-1]+1);

  int avCnt = 0;
  for(int i = 0; i < row-1; ++i){
    fill(ret[i], ret[i] + col, 0.0);
    ret[i][0] = (b[i] < 0 ? -b[i] : b[i]);
    for(int j = 0; j < n; ++j)
      ret[i][j+1] = (b[i] < 0 ? a[i][j] : -a[i][j]);

    if(b[i] < 0){ // 人工変数を使う
      solID[i] = n+m + avCnt;
      ++avCnt;

      ret[i][1+n + i] = 1.0; // スラック変数
      mulAdd(row, col, ret, i, row-1, -AV_PENALTY); // 目的関数の変換
    }
    else{
      solID[i] = n + i;
    }
  }
  // これは必要？
  for(int j = 0; j < col-1; ++j)
    remID[j] = j;
}

// 0 -> not found  1 -> found  -1 -> divergence
int findAugmentSwap(int m, int n, double **matrix, int &row, int &col){
  row = col = -1;
  double optX = 0;
  for(int j = 1; j < n; ++j){
    if(0 < matrix[m-1][j]){ // 0 < c(j)
      double lowX = 1e+1000;
      int lowID = -1;
      for(int i = 0; i < m-1; ++i){
        if(matrix[i][j] < -EPS){
          // -b(i) / a(i,j)
          double cx = -matrix[i][0] / matrix[i][j];
          if(lowX > cx){
            lowX = cx;
            lowID = i;
          }
        }
      }
      if(lowID == -1)
        return -1;
      
      if(optX <= lowX){
        optX = lowX;
        row = lowID, col = j;
      }
    }
  }
  
  return (row != -1 && col != -1) ? 1 : 0;
}

/*
  単体法で線形計画問題を解く
  解が存在しない場合、false を返す
*/
bool simplex(int arow, int acol,
             const double * const *a, const double *b, const double *c,
             double *res){
  int m = arow + 1, n = acol + arow + 1;
  double *matrix[m];
  for(int i = 0; i < m; ++i) matrix[i] = new double[n];
  int solID[m-1], remID[n-1]; // 変数の index を保持
  // スラック変数、人工変数などを用いて、扱いやすい形に問題を変換する.
  changeOptLP(arow, acol, a, b, c, matrix, solID, remID);

  int tr, tc;
  while(true){
    int ret = findAugmentSwap(m, n, matrix, tr, tc);
    if(ret == 0) break;
    if(ret == -1) return false; // 解が発散

    double tmp[m];
    for(int i = 0; i < m; ++i)
      tmp[i] = (i == tr ? 1.0 : 0.0);

    double div = -1.0 / matrix[tr][tc];
    tmp[tr] *= div;
    mul(m, n, matrix, tr, div);
    for(int i = 0; i < m; ++i)
      if(i != tr){
        tmp[i] += tmp[tr] * matrix[i][tc];
        mulAdd(m, n, matrix, tr, i, matrix[i][tc]);
      }

    // 列の入れ替え
    for(int i = 0; i < m; ++i)
      matrix[i][tc] = -tmp[i];
    swap(solID[tr], remID[tc-1]);
  }

  // 解の代入
  fill(res, res+acol, 0.0);
  for(int i = 0; i < m-1; ++i)
    if(solID[i] < acol)
      res[solID[i]] = matrix[i][0];
    else if(solID[i] >= acol+arow)
      return false; // 人工変数が解の一つになるのは、解がないということ

  for(int i = 0; i < m; ++i)
    delete [] matrix[i];
  
  return true;
}
