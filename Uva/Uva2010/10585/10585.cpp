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
#include<algorithm>
using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)
#define EPS 1e-12
#define MAX 10000

class Point{ 
    public:
    int x, y; 
    Point(int x=0, int y=0):x(x), y(y){}
    bool operator < ( const Point &p ) const{
	if ( x == p.x ) return y > p.y;
	return x < p.x;
    }
};

bool eq(double a, double b){
    return fabs(a-b) < EPS;
}

bool compute(){
    int n;  cin >> n;
    Point P[MAX];
    rep(i, n){ cin >> P[i].x >> P[i].y; }
    sort(P, P + n );



    double cx = (P[0].x + P[n-1].x)/2.0;
    double cy = (P[0].y + P[n-1].y)/2.0;
    double tx, ty;

    for ( int i = 1; i <= (n-1)/2; i++ ){
	tx = (P[i].x + P[n-i-1].x)/2.0;
	ty = (P[i].y + P[n-i-1].y)/2.0;
	if ( !( eq(cx, tx) && eq(cy, ty))  ) return false;
    }
	
    return true;

}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ) {
	if ( compute() ) cout << "yes" << endl;
	else cout << "no" << endl;
    }
}
