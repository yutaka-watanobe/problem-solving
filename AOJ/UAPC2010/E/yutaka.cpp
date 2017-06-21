#include<iostream>
#include<vector>
#include<cassert>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )
#define MAX 100000
#define M 10007

class Edge{
public:
  int target, cost;
  Edge(int target, int cost):target(target), cost(cost){}
};

vector<Edge> G[MAX];
bool V[MAX];
int n;
int ncomp;

void dfs(int u, vector<int> &maxv){
  V[u] = true;
  ncomp++;

  rep(i, G[u].size()){
    int c = G[u][i].cost;
    if ( maxv[0] < c ){ maxv.clear(); maxv.push_back(c); }
    else if ( maxv[0] == c ) maxv.push_back(c);
  }

  rep(i, G[u].size()){
    int v = G[u][i].target;
    if ( V[v] ) continue;
    dfs(v, maxv);
  }
}

int component(int u){
  vector<int> maxv;
  maxv.push_back(-1);
  ncomp = 0;
  dfs(u, maxv);
  assert( ncomp >= 3 );
  assert( maxv.size()%2 == 0 );
  return maxv.size()/2;
}

void compute(){
  rep(i, n) V[i] = false;
  int p = 1;
  rep(u, n){
    if ( !V[u] ){
      p = (p*component(u))%M;
    }
  }
  cout << p << endl;
}


main(){
  int m, s, t1, t2, b1, b2, c;
  while(1){
    cin >> n;
    if ( n == 0 ) break;
    assert( 3 <= n && n <= 100000);

    rep(i, n) G[i].clear();
    rep(i, n){
      cin >> t1 >> b1 >> t2 >> b2;
      G[i].push_back(Edge(t1, b1));
      G[i].push_back(Edge(t2, b2));
      assert( 0 < b1 );
      assert( 0 < b2 );
    }

    rep(i, n) assert( G[i].size() == 2 );
    rep(i, n) assert( G[i][0].target != G[i][1].target );

    rep(i, n){
      t1 = G[i][0].target;
      t2 = G[i][1].target;
      int c1 = G[i][0].cost;
      int c2 = G[i][1].cost;

      assert( G[t1][0].target == i || G[t1][1].target == i );
      assert( G[t2][0].target == i || G[t2][1].target == i );

      if ( G[t1][0].target == i ) assert( G[t1][0].cost == c1 );
      if ( G[t1][1].target == i ) assert( G[t1][1].cost == c1 );

      if ( G[t2][0].target == i ) assert( G[t2][0].cost == c2 );
      if ( G[t2][1].target == i ) assert( G[t2][1].cost == c2 );
    }



    compute();
  }
}
