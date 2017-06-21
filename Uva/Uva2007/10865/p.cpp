// Basic
#include<stdio.h>
#define MAX 200000
int n;

int cx, cy;

class Point{
    public:
    int x, y;
    Point(){}
    Point( int x, int y ): x(x), y(y){}
};

Point P[MAX];

void compute(){
    int stan, ollie;
    stan = ollie = 0;

    int x, y;

    for ( int i = 0; i < n; i++ ){
	x = P[i].x;
	y = P[i].y;
	
	if ( cx < x && cy < y || cx > x && cy > y ) stan++;
	if ( cx < x && cy > y || cx > x && cy < y ) ollie++;
    }

    printf("%d %d\n", stan, ollie);
}

bool read(){
    scanf("%d", &n);
    if ( n == 0 ) return false;

    int x, y;
    for ( int i = 0; i < n; i++ ){
	scanf("%d %d", &x, &y);
	if ( i == n / 2 ){
	    cx = x; cy = y;
	}
	P[i] = Point( x, y );
    }

    return true;
}

main(){
    while ( read() ){
	compute();
    }
}
