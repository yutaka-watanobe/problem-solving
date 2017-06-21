#include<iostream>
#include<vector>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )
#define MAX 100
#define INFTY (1<<21)

void dijkstra( int n, int G[MAX][MAX],  vector<int> p[MAX] ){
  int d[MAX];
  bool visited[MAX];

  rep(i, n) p[i].clear();

  rep(i, n){
    d[i] = INFTY;
    visited[i] = false;
  }

  d[0] = 0;

  int cnt = 0;
  while(1){
    int minv = INFTY;
    int u = -1;
    rep(i, n){
      if ( !visited[i] && minv > d[i] ) {
	u = i;
	minv = d[i];
      }
    }
    if ( u == -1 ) break;
    visited[u] = true;
    cnt++;

    rep(v, n){
      if ( !visited[v] && G[u][v] != INFTY ){
	int cost = d[u] + G[u][v];
	if ( cost == d[v] ){
	  p[v].push_back(u);
	} else if ( cost < d[v] ){
	  p[v].clear();
	  p[v].push_back(u);
	  d[v] = cost;
	}
      }
    }
  }

  assert( cnt == n );
}

void tsort( int n, int u, bool T[MAX][MAX], vector<int> &order, bool visited[MAX], vector<int> p[MAX] ){
  visited[u] = true;
  rep(v, n) if ( T[u][v] && !visited[v]) tsort(n, v, T, order, visited, p);

  if ( u == 0 || u == n-1 || p[u].size() > 0 ){
    order.push_back(u);
  }
}

void parse( int n, int u, vector<int> p[MAX], bool inpath[MAX]){
  inpath[u] = true;
  for ( int i = 0; i < p[u].size(); i++ ){
    int v = p[u][i];
       if ( !inpath[v] )parse(n, v, p, inpath);
       // parse(n, v, p, inpath);
  }
}

void makeTree(int n, bool T[MAX][MAX], vector<int> p[MAX], int q){
  bool inpath[MAX];
  rep(i, n) inpath[i] = false;
  parse(n, n-1, p, inpath);

  rep(i, n) rep(j, n) T[i][j] = false;
  rep(v, n){
    rep(i, p[v].size()){
      int u = p[v][i];
      if ( inpath[u] && inpath[v] ) T[u][v] = true;
    }
  }

  vector<int> order;
  bool visited[MAX]; 

  rep(i, n) visited[i] = false;
  order.clear();
  tsort(n, 0, T, order, visited, p);
  reverse(order.begin(), order.end());

  double forward[MAX], back[MAX];
  rep(i, n) forward[i] = back[i] = 0.0;

  //rep(i,n) cout << order[i] << " ";
  //cout << endl;

  assert( order[0] == 0 );
  assert( order[order.size()-1] == n-1 );
  forward[order[0]] = 1;
  for ( int i = 0; i < order.size(); i++ ){
    int u = order[i];
    rep(v, n){
      if ( T[u][v] ) forward[v] += forward[u];
    }
  }
  for ( int i = 0; i < n; i++ ){
    if ( 0 == i ) continue;
    //forward[i] /= forward[n-1];
  }
  
  rep(i, n) visited[i] = false;
  order.clear();
  // Tt
  bool tmp[MAX][MAX];
  /*
 rep(i, n){
    rep(j, n) cout << T[i][j] << " ";
    cout << endl;
    }*/
  rep(i, n) rep(j, n) tmp[j][i] = T[i][j];
  rep(i, n) rep(j, n) T[i][j] = tmp[i][j];

  /*
  rep(i, n){
    rep(j, n) cout << T[i][j] << " ";
    cout << endl;
  }
    cout << endl;
  */


  tsort(n, n-1, T, order, visited, p);
  reverse(order.begin(), order.end());

  //  rep(i, n) cout << order[i] << " ";
  //  cout << endl;

  assert( order[0] == n-1 );
  assert( order[order.size()-1] == 0 );
  back[order[0]] = 1.0;
  for ( int i = 0; i < order.size(); i++ ){
    int u = order[i];
    rep(v, n){
      if ( T[u][v] ) back[v] += back[u];
    }
  }

  //  double base = 1.0; // back[0];
  for ( int i = 0; i < n; i++ ){
    if ( i == n-1 ) continue;
    // back[i] = back[i]/back[0];
    //back[i] = back[i]/base;

  }

  double base = forward[n-1];
  assert( base == back[0]);

  /*
  rep(i, n){
    //printf("%.4lf %.4lf %.4lf\n", forward[i], back[i], forward[i]*back[i]);
    printf("%.8lf\n", forward[i]*back[i]);
  }
  cout << endl;
  */

  int req;

  rep(i, q){
    cin >> req;
    printf("%.12lf\n", forward[req]*back[req]/base);
    
	//printf("%.12lf * %.2lf = %.12lf\n", forward[req], back[req], forward[req]*back[req]);
  }

    

}


main(){
  int n, m, q, G[MAX][MAX], s, t, c;
  bool T[MAX][MAX];
  vector<int> p[MAX];
  while(1){
    cin >> n >> m >> q;
    if ( n == 0 && m == 0 && q == 0) break;
    rep(i, n) rep(j, n) G[i][j] = INFTY;
    rep(i, m){
      cin >> s >> t >> c;
      G[s][t] = G[t][s] = c;
    }
    dijkstra(n, G, p);
    makeTree(n, T, p, q);
  }
}
