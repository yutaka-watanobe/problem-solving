#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAX 100000

class Point{
    public:
    double x, y, r;
    
    Point ( double x = 0, double y = 0, double r = 0): x(x), y(y), r(r){}
    
    bool operator < ( const Point &p ) const {
	return x != p.x ? x < p.x : y < p.y;
    }
};

int n;
Point P[MAX];

double getDistance( Point p1, Point p2 ){
    return sqrt( (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

void compute(){
    sort( P, P + n );
    double ans = (1<<21);

    for ( int i = 0; i < n-1; i++ ){
	for ( int j = i+1; j < n; j++ ){
	    if ( P[j].y - P[i].y > ans ) break;
	    ans = min( ans, getDistance(P[i], P[j]) );
	}
    }

    printf("%.12lf\n", ans);
}

main(){
    while(1){
	scanf("%d", &n);
	if ( n == 0 ) break;
	for ( int i = 0; i < n; i++ ){
	    scanf("%lf %lf %lf", &P[i].x, &P[i].y, &P[i].r);
	}
	compute();
    }
}
