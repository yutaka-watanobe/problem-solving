// 11776:Oh Your Royal Greediness!:2.5:Sort, Greedy, 
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

#define IN 0
#define OUT 1
#define MAX 2000
#define EPS 1e-8

class Event{
public:
  int type;
  double p;
  Event(int type=0, double p=0):type(type), p(p){}
  bool operator < ( const Event &e) const{
    return p < e.p;
  }
};

int compute(int N){
  Event E[MAX];
  int s, e;
  for ( int i = 0; i < N*2; i+=2){
    cin >> s >> e;
    E[i] = Event(IN, 1.0*s-EPS);
    E[i+1] = Event(OUT, 1.0*e+EPS);
  }
  sort(E, E + (2*N));

  int w = 0;
  int maxv = 0;
  for ( int i = 0; i < 2*N; i++ ){
    Event event = E[i];
    if ( event.type == IN ) w++;
    else if ( event.type == OUT ) w--;
    maxv = max(maxv, w);
  }
  return maxv;
}

main(){
  int N;
  for ( int t= 1; ; t++ ){
    cin >> N;
    if ( N == -1 ) break;
    cout << "Case " << t << ": " << compute(N) << endl;
  }
}
