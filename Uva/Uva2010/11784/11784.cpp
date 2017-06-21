// 11784:Escape:1.5:Grid Simulation
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
#define MAX 1000

class Goal{
public:
  int pi, pj, dist;
  Goal(int pi=0, int pj=0, int dist=0): pi(pi), pj(pj), dist(dist){}
  bool operator < ( const Goal &g ) const{
    return dist < g.dist;
  }
};

int H, W, ne, pi, pj;
bool G[MAX][MAX];

void print(){
  rep(i, H){
    rep(j, W){
      if ( i == 0 || j == 0 || i == H-1 || j == W-1 ){
	if ( G[i][j] ) cout << ".";
	else cout << "#";
      } else {
	cout << ".";
      }
    }
    cout << endl;
  }
    cout << endl;
}

void simulate(){
  Goal T[4];

  T[0] = Goal(0, pj, pi);
  T[1] = Goal(pi, W-1, W-pj-1);
  T[2] = Goal(H-1, pj, H-pi-1);
  T[3] = Goal(pi, 0, pj);
  sort(T, T+4);

  int t = 0;
  bool tmp;
  while(1){
    t++;
    tmp = G[0][0];
    rep(i, H-1) G[i][0] = G[i+1][0];
    rep(j, W-1) G[H-1][j] = G[H-1][j+1];
    for ( int i = H-1; i >= 1; i-- ) G[i][W-1] = G[i-1][W-1];
    for ( int j = W-1; j >= 1; j-- ) G[0][j] = G[0][j-1];
    G[0][1] = tmp;
    //print();

    for ( int cur = 0; cur < 4; cur++){
      if (G[T[cur].pi][T[cur].pj] && T[cur].dist <= t ){
	cout << t+1 << " " << T[cur].dist+1 << endl;
	return;
      }
    }
  }

}

main(){
  while(1){
    scanf("%d %d %d", &H, &W, &ne);
    if ( H == 0 && W == 0 && ne == 0 ) break;
    rep(j, W) G[0][j] = G[H-1][j] = false;
    rep(i, H) G[i][0] = G[i][W-1] = false;
    rep(i, ne){
      cin >> pi >> pj; 
      G[pi][pj] = true;
    }
    cin >> pi >> pj;
    simulate();
  }
}
