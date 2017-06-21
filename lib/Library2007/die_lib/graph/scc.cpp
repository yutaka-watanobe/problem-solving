#include <iostream>
#include <algorithm>

using namespace std;

const int GMAX = 100;

int n;               // 頂点数
bool g[GMAX][GMAX];  // グラフ

int group[GMAX];     // 頂点 i が属するグループの id
bool vis[GMAX];
int id[GMAX];

// 逆トポロジカル dfs
void rtopdfs(int curr, int &cnt){
  vis[curr] = true;
  for(int i = 0; i < n; ++i)
    if(g[curr][i] && !vis[i])
      rtopdfs(i, cnt);
  id[cnt++] = curr;
}

void rdfs(int curr, int gid){
  group[curr] = gid;
  for(int i = 0; i < n; ++i)
    if(g[i][curr] && group[i] == -1)
      rdfs(i, gid);
}

void clear(void){
  fill(vis, vis+n, false);
  fill(id, id+n, -1);
  fill(group, group+n, -1);
}

// 強連結成分分解
// 強連結成分の個数を返す
int scc(void){
  clear();

  int cnt = 0;
  for(int i = 0; i < n; ++i)
    if(!vis[i])
      rtopdfs(i, cnt);

  int gnum = 0;
  while(--cnt >= 0)
    if(group[id[cnt]] == -1)
      rdfs(id[cnt], gnum++);
  return gnum;
}

void init(void){
  for(int i = 0; i < n; ++i)
    fill(g[i], g[i]+n, false);
}

int main(void){
  int m;
  while(cin >> n >> m){
    init();
    for(int i = 0; i < m; ++i){
      int f, t;
      cin >> f >> t;
      g[f][t] = true;
    }

    int gnum = scc();
    cout << gnum << endl;
    for(int i = 0; i < gnum; ++i){
      for(int j = 0; j < n; ++j)
        if(group[j] == i)
          cout << j << ' ';
      cout << endl;
    }
  }
  
  return 0;
}
