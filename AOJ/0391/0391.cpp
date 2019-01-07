#include<iostream>
#include<cassert>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define rep(i, n) for ( int i = 0; i < (int)n; i++ )
static const int N_MAX = 100000;
static const int MAX_LOG_V = 17;
static const int INF = 2000000000;

typedef long long ll;

int N;
vector<pair<int, int> > G[N_MAX];
int root;

int parent[MAX_LOG_V][N_MAX];
int depth[N_MAX], W[N_MAX];

void dfs(int v, int p, int d, int w){
  parent[0][v] = p;
  depth[v] = d;
  W[v] = w;
  for ( int i = 0; i < G[v].size(); i++ ){
    if ( G[v][i].first != p ) dfs(G[v][i].first, v, d + 1, w + G[v][i].second);
  }
}

void init(int V){
  root = 0;
  W[root] = 0;
  dfs(root, -1, 0, 0);
  for ( int k = 0; k + 1 < MAX_LOG_V; k++ ){
    for ( int v = 0; v < V; v++ ){
      if ( parent[k][v] < 0 ) parent[k + 1][v] = -1;
      else parent[k + 1][v] = parent[k][parent[k][v]];
    }
  }
}

int lca(int u, int v){
  if (depth[u] > depth[v]) swap(u, v);
  for ( int k = 0; k < MAX_LOG_V; k++ ){
    if ((depth[v] - depth[u]) >> k & 1 ){
      v = parent[k][v];
    }
  }
  if ( u == v ) return u;
  for ( int k = MAX_LOG_V - 1; k >=0 ; k-- ){
    if (parent[k][u] != parent[k][v] ){
      u = parent[k][u];
      v = parent[k][v];
    }
  }
  return parent[0][u];
}

int getDist(int s, int t){
  int l = lca(s, t);
  return W[s] + W[t] - W[l]*2;
}

int getNode(int B, int H){ // start from B and height (node num) = H
  int v = B;
  for ( int k = 0; k < MAX_LOG_V; k++ ){
    if (H >> k & 1) v = parent[k][v];
  }
  return v;
}
int bsearch(int s, int t, int D ){
  //  cout << "bsearch " << s << "-->" << t << "  D = " << D << endl;
  int B = s;
  int H = t;
  int M, left, right;
  int ans = INF;
  for ( int i = 0; i < 20; i++ ){
    M = getNode(s, depth[s] - depth[B] + (depth[B] - depth[H])/2);
    left = W[s] - W[M];
    right = D - left;
    //    cout << "B=" << B << " H=" << H << endl;
    //        cout << "M=" << M+1 << endl;
    //        cout << left << "/" << right << endl;
    ans = min(ans, max(left, right));
    if ( left == right ) return ans;
    else if ( left < right ) B = parent[0][M];
    else if ( left > right) H = M;
  }
  return ans;
}

int search(int s, int t, int D){
  int p = s, w = 0, ans = INF;
  while(1){
    ans = min(ans, max(w, D-w));
    if ( p == t ) break;
    p = parent[0][p];
    w = W[s] - W[p];
  }
  return ans;
}

int solve(int a, int b, int c){
  int S = a;
  int T = b;
  int d, D= getDist(a, b);
  d = getDist(a, c);
  if ( D < d ){
    S = a;
    T = c;
    D = d;
  }
  d = getDist(b, c);
  if ( D < d ){
    S = b;
    T = c;
    D = d;
  }

  // ans is between S and T
  int L = lca(S, T);
  int SL = getDist(S, L);
  int LT = getDist(L, T);
  if ( SL == LT ) return SL;
  if ( SL > LT ){
    return bsearch(S, L, D);
  } else if ( SL < LT ){
    return bsearch(T, L, D);
  }
}

int main(){
  int Q, u, v, w, a, b, c;
  cin >> N >> Q;
  for ( int i = 0; i < N-1; i++ ) {
    cin >> u >> v >> w;
    u--; v--;
    G[u].push_back(make_pair(v, w));
    G[v].push_back(make_pair(u, w));
  }

  init(N);

  for ( int i = 0; i < Q; i++ ) {
    cin >> a >> b >> c; a--; b--; c--;
    cout << solve(a, b, c) << endl;
  }

  return 0;
}
