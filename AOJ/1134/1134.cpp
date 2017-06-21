#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++)
#define MAX 200

bool G[MAX][MAX], V[MAX];

void split(string line, string &s1, string &s2){
  int p=0;
  s1 = s2 = "";
  while(line[p] != '-' ) s1 += line[p++];
  p++;
  while( p < line.size() ) s2 += line[p++];
}

int getIndex(string s, map<string, int> &M, int &nnode){
  if ( M.find(s) == M.end() ){
    M[s] = nnode++;
    return M[s];
  } else return M[s];
}

bool dfs( int u, int t, int nnode, int p){
  if ( u == t ){
    return p%2;
  }

  V[u] = true;

  rep(v, nnode){
    if ( !G[u][v] || V[v]) continue;
    if ( dfs( v, t, nnode, p+1) ) return true;
  }
  //  V[u] = false;
  return false;
}

void compute(int n){
  string s1, s2, line;
  map<string, int> M;
  vector<pair<int, int> > L;
  int nnode = 0;
  rep(i, MAX) rep(j, MAX) G[i][j] = false;
  rep(i, n){
    cin >> line;
    split(line, s1, s2);
    int s = getIndex(s1, M, nnode);
    int t = getIndex(s2, M, nnode);
    G[s][t] = true;
    L.push_back(make_pair(s, t));
  }
  
  rep(a, nnode-1) for ( int b = a+1; b < nnode; b++ ){
    if ( a == b ) continue;
    bool AC = false, BC = false, CA = false, CB = false, DA = false, BD = false, AE = false, EB = false;
    rep(i, L.size()){
      int s = L[i].first;
      int t = L[i].second;
      if ( s == a && t == i ) AC = true;
      if ( s == b && t == i ) BC = true;
      if ( s == i && t == a ) CA = true;
      if ( s == i && t == b ) CB = true;
      if ( s == i && t == a ) DA = true;
      if ( s == b && t == i ) BD = true;
      if ( s == a && t == i ) AE = true;
      if ( s == i && t == b ) EB = true;
    }
    if ( (AC && BC || CA && CB ) &&
	 !(DA && BD) && !(AE && EB ) ) G[a][b] = true;
  }

  cout << nnode << endl;
  int m; cin >> m;
  rep(i, m){
    cin >> line;
    split(line, s1, s2);
    rep(i, nnode) V[i] = false;

    if ( dfs( M[s1], M[s2], nnode, 0) ) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}

main(){
  int n;
  while( cin >> n && n ) compute(n);
}
