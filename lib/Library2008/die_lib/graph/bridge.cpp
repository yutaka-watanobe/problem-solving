#include <iostream>

using namespace std;

const int GMAX = 80;

int n;               // グラフの頂点数
bool g[GMAX][GMAX];  // グラフ
int id[GMAX];        // Bridge を求める際に使用する領域
int bridge[GMAX];    // bridge[i] が -1 でないとき、(bridge[i], i) は橋

void clear(void){
  fill(id, id+n, -1);
  fill(bridge, bridge+n, -1);
}

int dfs(int curr, int &cnt){
  int ret = id[curr] = cnt++;
  for(int i = 0; i < n; ++i){
    if(g[curr][i] || g[i][curr]){ // 有向グラフも無向グラフとみなす
      bool tmp1 = g[curr][i], tmp2 = g[i][curr];
      g[curr][i] = g[i][curr] = false; // 戻ってこれないように辺を消す
      if(id[i] == -1){
        int upper = dfs(i, cnt);
        if(id[i] <= upper)
          bridge[i] = curr;
        ret = min(ret, upper);
      }
      else{
        ret = min(ret, id[i]);
      }
      g[curr][i] = tmp1, g[i][curr] = tmp2;
    }
  }
  return ret;
}

void calcBridge(void){
  clear();

  int cnt = 0;
  for(int i = 0; i < n; ++i)
    if(id[i] == -1)
      dfs(i, cnt);
}

void init(void){
  for(int i = 0; i < n; ++i)
    fill(g[i], g[i]+n, false);
}

int main(void){
  n = 2;
  init();
  g[1][0] = true;

  calcBridge();

  for(int i = 0; i < n; ++i){
    if(bridge[i] != -1)
      cout << bridge[i] << ',' << i << " is a bridge" << endl;
  }
  return 0;
}
