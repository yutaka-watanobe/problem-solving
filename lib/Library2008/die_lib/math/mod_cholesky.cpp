#include <iostream>

using namespace std;

// M = T(R) * D * R
void mCholesky(double **m, int row, int col, double **d, double **r){
  if(row == col){
    for(int i = 0; i < row; ++i){
      d[i][i] = m[i][i];
      for(int k = 0; k < i; ++k)
        d[i][i] -= r[k][i] * r[k][i] * d[k][k];
      for(int j = i+1; j < row; ++j){
        r[i][j] = a[i][j];
        for(int k = 0; k < i; ++k)
          r[i][j] -= r[k][i] * r[k][j] * d[k][k];
        r[i][j] /= d[i][i];
      }
    }
  }
  else
    cerr << "not supported" << endl;
}

void output(double **m){
  for(int i = 0; i < 3; ++i){
    for(int j = 0; j < 3; ++j)
      cout << m[i][j] << ' ';
    cout << endl;
  }
}

int main(void){
  double **m = new double*[3];
  m[0] = new double[3];
  m[0][0] = 2.5, m[0][1] = 1.4, m[0][2] = 2.8;
  m[1] = new double[3];
  m[1][0] = 1.4, m[1][1] = 3.6, m[1][2] = 5.2;
  m[2] = new double[3];
  m[2][0] = 2.8, m[2][1] = 5.2, m[2][2] = 2.0;

  double **d = new double*[3];
  d[0] = new double[3];
  d[1] = new double[3];
  d[2] = new double[3];
  double **r = new double*[3];
  r[0] = new double[3];
  r[1] = new double[3];
  r[2] = new double[3];
  mCholesky(m, 3, 3, d, r);

  output(m);
  cout << "D --" << endl;
  output(d);
  cout << "R --" << endl;
  output(r);
  
  return 0;
}
