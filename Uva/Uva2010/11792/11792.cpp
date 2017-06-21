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
int Q[MAX*2];
int head, tail;

void bfs(int s, int d[MAX]){
  //queue<int> Q;
  rep(i, N) d[i] = INFTY;
  head = tail = 0;
  //Q.push(s);
  Q[tail++] = s;
  d[s] = 0;
  
  int u, v;
  //  while( !Q.empty() ){
  while( head != tail ){
    //u = Q.front(); Q.pop();
    u = Q[head++];
    for ( int i = 0; i < adj[u].size(); i++ ){
      int v = adj[u][i];
      if ( d[v] == INFTY ){
	d[v] = d[u] + 1;
	//Q.push(v);
	Q[tail++] = v;
      }
    }
  }
}

int compute(){
  int S, pre, p;
  scanf("%d %d", &N, &S);

  rep(i, N) adj[i].clear();

  int cnt[MAX];
  rep(i, N) cnt[i] = 0;

  rep(i, S){
    scanf("%d", &pre);
    pre--;
    cnt[pre]++;
    if ( pre == -1 ) continue;
    while(1){
      scanf("%d", &p);
      p--;
      if ( p == -1 ) break;
      adj[pre].push_back(p);
      adj[p].push_back(pre);
      pre = p;
      cnt[pre]++;
    }
  }

  //vector<int> imp;
  int imp[101];
  int nimp = 0;

  //  rep(i, N) if ( cnt[i] > 1 ) imp.push_back(i);
  rep(i, N) if ( cnt[i] > 1 ) imp[nimp++] = i;
  
  int d[MAX];
  int minv = INFTY;
  int mini = 0;
  for ( int i = 0; i < nimp; i++ ){
    bfs(imp[i], d);
    
    int sum = 0;
    for ( int j = 0; j < nimp; j++ ){
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
  int tcase; scanf("%d", &tcase);
  rep(i, tcase){
    printf("Krochanska is in: %d\n", compute()+1);
  }
}
