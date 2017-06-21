/*
 * DP in a DAG (compressed grid graph)
 */
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define REP(i, b, e) for ( int i = b; i < (int)e; i++ )
#define rep(i, n) REP(i, 0, n)
static const int INFTY = (1<<30);
static const int NMAX = 150;
static const int MMAX = 80;
class Node{
public:
  int p, s, M[MMAX];
  Node(){}
  Node(int p, int s):p(p), s(s){
    rep(i, MMAX) M[i] = INFTY;
  }
};

int n, m;
vector<Node> P[NMAX];

int compute(){
  rep(j, P[0].size()) P[0][j].M[0] = 0;
  if ( n >= 2 ){
    rep(j, P[1].size()) P[1][j].M[1] = 0;
  }

  rep(i, n-1){
    rep(j, P[i].size()){
      Node src = P[i][j];
      rep(k, P[i+1].size()){
	Node tar = P[i+1][k];
	int cost = (src.s + tar.s)*(max(src.p, tar.p) - min(src.p, tar.p));
	rep(l, m+1){
	    P[i+1][k].M[l] = min(P[i+1][k].M[l], P[i][j].M[l] + cost);
	}
      }
      if (i == n-1) continue;
      rep(k, P[i+2].size()){
	Node tar = P[i+2][k];
	int cost = (src.s + tar.s)*(max(src.p, tar.p) - min(src.p, tar.p));
	rep(l, m){
	    P[i+2][k].M[l+1] = min(P[i+2][k].M[l+1], P[i][j].M[l] + cost);
	}
      }
    }
  }
  int minv = INFTY;
  rep(j, P[n-1].size()){
    rep(l, m+1) minv = min(minv, P[n-1][j].M[l]);
  }
  if ( n > 1 ){
    rep(j, P[n-2].size()){
      rep(l, m) minv = min(minv, P[n-2][j].M[l]);
    }
  }
  return minv;
}

main(){
  int k, p, s;
  while(1){
    cin >> n >> m;
    if ( n == 0 && m == 0 ) break;
    rep(i, n) P[i].clear();
    rep(i, n){
      cin >> k;
      rep(j, k){
	cin >> p >> s;
	P[i].push_back(Node(p, s));
      }
    }
    cout << compute() << endl;
  }
}
