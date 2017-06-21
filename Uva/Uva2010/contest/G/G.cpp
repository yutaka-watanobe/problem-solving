#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<cmath>
#include<cassert>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)

#define MAX 10000
#define INFTY (1<<21)

vector<int> adj[MAX];
int N;

void bfs(int s, int d[MAX]){
  queue<int> Q;
  rep(i, N) d[i] = INFTY;
  Q.push(s);
  d[s] = 0;
  
  int u, v;
  while( !Q.empty() ){
    u = Q.front(); Q.pop();
    for ( int i = 0; i < adj[u].size(); i++ ){
      int v = adj[u][i];
      if ( d[v] == INFTY ){
	d[v] = d[u] + 1;
	Q.push(v);
      }
    }
  }
}

int compute(){
  int S, pre, p;
  cin >> N >> S;
  rep(i, N) adj[i].clear();

  int cnt[MAX];
  rep(i, N) cnt[i] = 0;

  rep(i, S){
    cin >> pre; pre--;
    cnt[pre]++;
    if ( pre == -1 ) continue;
    while(1){
      cin >> p; p--;
      if ( p == -1 ) break;
      adj[pre].push_back(p);
      adj[p].push_back(pre);
      pre = p;
      cnt[pre]++;
    }
  }

  vector<int> imp;

  rep(i, N) if ( cnt[i] > 1 ) imp.push_back(i);
  
  int d[MAX];
  int minv = INFTY;
  int mini = 0;
  for ( int i = 0; i < imp.size(); i++ ){
    bfs(imp[i], d);
    
    int sum = 0;
    for ( int j = 0; j < imp.size(); j++ ){
      if ( j == i ) continue;
      sum += d[imp[j]];
    }

    if ( sum < minv ){
      minv = sum;
      mini = imp[i];
    }
  }

  return mini;


}

main(){
  int tcase; cin >> tcase;
  rep(i, tcase){
    cout << "Krochanska is in: " << compute()+1 << endl;
  }
}
