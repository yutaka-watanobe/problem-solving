// 11518:Dominos 2:1.5:DFS
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<cassert>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)

#define MAX 10000

int n;
vector<int> adj[MAX];
bool visited[MAX];

void dfs(int u){
  visited[u] = true;
  for ( int i = 0; i < adj[u].size(); i++ ){
    int v = adj[u][i];
    if ( !visited[v] ) dfs(v);
  }
}

void compute(){
  int m, l, s, d;
  cin >> n >> m >> l;
  rep(i, n) adj[i].clear();
  rep(i, n) visited[i] = false;
  rep(i, m){
    cin >> s >> d;
    s--; d--;
    adj[s].push_back(d);
  }
  
  rep(i, l){
    cin >> s; 
    s--;
    dfs(s);
  }

  int cnt = 0;
  rep(i, n) if ( visited[i] ) cnt++;
  cout << cnt << endl;
}

main(){
  int t; cin >> t;
  rep(i, t) compute();
}
