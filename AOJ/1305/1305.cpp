#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<map>

using namespace std;
static const int MAX = 101;

vector<string> getList(string line){
  vector<string> l;
  string str = "";
  for ( int i = 0; i < line.size(); i++ ){
    if ( line[i] == '.' || line[i] == ',' ){
      l.push_back(str);
      str = "";
    } else str += line[i];
  }
  return l;
}

vector<string> M[MAX];
bool vis[MAX];

void rec(int p, map<string, int> P, set<string> &U, set<string> G, vector<string> V){
  vis[p] = true;
  for ( int i = 0; i < V.size(); i++ ){
    string name = V[i];
    if ( G.find(name) != G.end() ){
      int t = P[name];
      if ( !vis[t] ) rec(t, P, U, G, M[t]);
    } else {
      U.insert(name);
    }
  }
}

void solve(int n){
  string line;
  set<string> G;
  map<string, int> P;

  for ( int i = 0; i < n; i++ ) {
    cin >> line;
    int p = 0;
    string gname = "";
    while( line[p] != ':' ) { gname += line[p++]; }
    P[gname] = i;
    M[i] = getList(line.substr(p+1));
    G.insert(gname);
  }

  set<string> U;
  for ( int i = 0; i < n; i++ ) vis[i] = false;
  rec(0, P, U, G, M[0]);
  cout << U.size() << endl;
}

main(){
  int n;
  while( cin >> n, n) solve(n);
}
