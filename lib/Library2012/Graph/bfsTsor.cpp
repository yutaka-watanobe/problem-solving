// uva 10305
#include<iostream>
#include<vector>
#include<queue>
#include<cassert>
using namespace std;
#define MAX 100
vector<int> G[MAX];
int n, m;

void tsort(){
  int indeg[MAX];
  int order[MAX];
  for ( int i = 0; i < n; i++ ) {
    indeg[i] = 0;
    order[i] = -1;
  }
  for ( int u = 0; u < n; u++ ){
    for ( int i = 0; i < G[u].size(); i++ ){
      int v = G[u][i];
      indeg[v]++;
    }
  }

  int pos = 0;
  queue<int> q;
  for ( int i = 0; i < n; i++ )
    if ( indeg[i] == 0 ) q.push(i);

  for (; !q.empty(); ){
    int u = q.front(); q.pop();
    order[u] = pos;
    pos++;
    for ( int i = 0; i < G[u].size(); i++ ){
      int v = G[u][i];
      indeg[v]--;
      if ( indeg[v] == 0 ){
	q.push(v);
      }
    }
  }

  assert( pos == n );

  int ans[MAX];
  for  (int i = 0; i < n; i++ ) ans[order[i]] = i+1;

  for ( int i = 0; i < n; i++ ){
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;

}

main(){
  while(1){
    cin >> n >> m;
    if ( n == 0 && m == 0 ) break;
    for ( int i = 0; i < n; i++ ) G[i].clear();
    for ( int i = 0; i < m; i++ ){
      int s, t;
      cin >> s >> t;
      s--; t--;
      G[s].push_back(t);
    }
    tsort();
  }
  
}
