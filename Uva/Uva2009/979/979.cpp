#include<stdio.h>
#define MAX 4000
#define rep(i, n) for ( int i = 0; i < n; i++ )
struct Point { int x, y; };

Point T[3], P[MAX];
int n;

int getDist( Point p1, Point p2 ){
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

void compute(){
    rep(i, n) rep(j, n){
	if ( getDist(T[0], T[1]) != getDist(P[i], P[j]) ) continue;
	rep(k, n){
	    if ( getDist(T[1], T[2]) != getDist(P[j], P[k]) ) continue;
	    if ( getDist(T[2], T[0]) != getDist(P[k], P[i]) ) continue;
	    printf("%d %d\n", P[i].x, P[i].y);
	    printf("%d %d\n", P[j].x, P[j].y);
	    printf("%d %d\n", P[k].x, P[k].y);
	    return;
	}
    }
}

int main(){
    int tcase = 0;
    while( scanf("%d %d", &T[0].x, &T[0].y) != EOF ){
	if ( tcase++ ) printf("\n");
	rep(i, 2) scanf("%d %d", &T[i+1].x, &T[i+1].y );
	scanf("%d", &n);
	rep(i, n) scanf("%d %d", &P[i].x, &P[i].y);
	compute();
    }
    return 0;
}
