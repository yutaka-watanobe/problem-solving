#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i, n) for ( int i = 0; i < (int)n; i++)

class P{
public:
  int s, c, r, t;
  P(int s=0, int c=0):s(s), c(c){ r = s; t = 0;}
  bool operator < ( const P &p ) const{ return s < p.s; }
};

vector<P> getNext(vector<P> &l, int w){
  vector<P> nl;
  rep(i, l.size()) l[i].r -= w;
  while ( 0 < l.size() && l[0].r <= 0 ){
    P p = l[0]; l.erase(l.begin());
    p.t++;
    if ( p.c*2 >= p.t ){
      p.r = p.s;
      nl.push_back(p);
    }
  }
  sort(nl.begin(), nl.end());
  return nl;
}

void simulate(vector<P> U, vector<P> D){
  vector<P> nU, nD;
  int w, e = 0;
  while( U.size() + D.size() > 0){
    if ( U.size() == 0 ) w = D[0].r;
    else if ( D.size() == 0 ) w = U[0].r;
    else w = min(U[0].r, D[0].r);
    e += w;
    nU = getNext(D, w);
    nD = getNext(U, w);
    rep(i, nU.size()) U.push_back(nU[i]);
    rep(i, nD.size()) D.push_back(nD[i]);
  }
  cout << e << endl;
}

main(){
  int n;
  while( cin >> n && n ){
    vector<P> U, D;
    rep(i, n){
      P p; cin >> p.s >> p.c;
      U.push_back(p);
    }
    sort(U.begin(), U.end());
    simulate(U, D);
  }
}
