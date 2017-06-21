// 11559:Event Planning:1.0:Writing
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<cassert>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)
#define WMAX 13
#define INFTY (1<<25)
class Hotel{
public:
  int price, w;
  int cap[WMAX];
  Hotel(int price=0, int w=0):price(price),w(w){}
};

main(){
  int N, B, H, W;
  Hotel hotels[20];
  while( cin >> N >> B >> H >> W ){
    rep(i, H){
      cin >> hotels[i].price;
      hotels[i].w = W;
      rep(j, W) cin >> hotels[i].cap[j];
    }
    int minc = INFTY;
    rep(i, W){
      rep(h, H){
	if ( hotels[h].cap[i] < N ) continue;
	minc = min(minc, N*hotels[h].price);
      }
    }

    if ( minc > B ) cout << "stay home" << endl;
    else cout << minc << endl;
  }
}
