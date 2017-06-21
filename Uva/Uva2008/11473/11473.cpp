#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAX 100
#define POINT_ROAD 0
#define POINT_TREE 1

class Point{
    public:
    double x, y, dist;
    int type, id;
    Point(){}
    Point( int id, double x, double y, int type):id(id), x(x), y(y), type(type){}

    bool operator < ( const Point &p ) const{
	if ( dist == p.dist ) return type < p.type;
	else return dist < p.dist;
    }
};

int n, T, N;
Point P[MAX], path[MAX*2];

double getDist( Point p1, Point p2 ){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

void showTree( Point p1, Point p2, double d ){
    d -= p1.dist;
    d /= (p2.dist - p1.dist);
    double x = p1.x + (p2.x - p1.x)*d;
    double y = p1.y + (p2.y - p1.y)*d;
    printf("%.2lf %.2lf\n", x, y);
}

void compute(){
    N = n;
    for ( int i = 0; i < n; i++ ) path[i] = P[i];
    double w = P[n-1].dist/(T-1);
    for ( int i = 1; i <= T-2; i++ ){
	path[N++] = Point(-1, 0, 0, POINT_TREE);
	path[N-1].dist = i*w;
    }

    sort( path, path + N );

    printf("%.2lf %.2lf\n", P[0].x, P[0].y);
    Point pre = path[0];
    for ( int i = 1; i < N-1; i++ ){
	if ( path[i].type == POINT_ROAD ){
	    pre = path[i];
	} else {
	    showTree(pre, P[pre.id+1], path[i].dist);
	}
    }
    printf("%.2lf %.2lf\n", P[n-1].x, P[n-1].y);
}

void input(){
    scanf("%d %d", &n, &T);
    double x, y;
    scanf("%lf %lf", &x, &y);
    P[0] = Point( 0, x, y, POINT_ROAD);
    P[0].dist = 0.0;
    for ( int i = 1; i < n; i++ ){
	scanf("%lf %lf", &x, &y);
	P[i] = Point(i, x, y, POINT_ROAD);
	P[i].dist = P[i-1].dist + getDist(P[i-1], P[i]);
    }
}

int main(){
    int tcase; 
    scanf("%d", &tcase);
    for ( int i = 1; i <= tcase; i++ ){
	printf("Road #%d:\n", i);
	input();
	compute();
	printf("\n");
    }
    return 0;
}
