#include <iostream>

using namespace std;

const int GMAX = 80;

int n;                     // グラフの頂点数
bool g[GMAX][GMAX];        // グラフ
int id[GMAX], dout[GMAX];  // AP を求める際に使用する領域
bool ap[GMAX];             // 頂点 i が AP かどうか

void clear(void){
  fill(id, id+n, -1);
  fill(dout, dout+n, 0);
  fill(ap, ap+n, false);
}

int dfs(int curr, int &cnt){
  int ret = id[curr] = cnt++;
  for(int i = 0; i < n; ++i){
    if(g[curr][i] || g[i][curr]){ // 有向グラフも無向グラフとみなす
      if(id[i] == -1){
        ++dout[curr];
        
        int upper = dfs(i, cnt);
        ap[curr] |= id[curr] <= upper;
        ret = min(ret, upper);
      }
      else{
        ret = min(ret, id[i]);
      }
    }
  }
  return ret;
}

void calcAP(void){
  clear();

  int cnt = 0;
  for(int i = 0; i < n; ++i)
    if(id[i] == -1){
      dfs(i, cnt);
      ap[i] = dout[i] >= 2;
    }
}

void init(void){
  for(int i = 0; i < n; ++i)
    fill(g[i], g[i]+n, false);
}

int main(void){
  n = 3;
  init();
  g[2][1] = g[1][0] = true;
  calcAP();

  for(int i = 0; i < n; ++i)
    if(ap[i])
      cout << i << " is an articulation point" << endl;
  return 0;
}
