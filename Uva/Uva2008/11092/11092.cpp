#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAX 10000000

struct Point{ int x, y;};

Point P[MAX+1];

void init(){
    int x, y, w, i;
    w = 1;
    static int dx[6] = {-1, -1, 0, 1, 1, 0};
    static int dy[6] = {1, 0, -1, -1, 0, 1};
    P[0].x = P[0].y = 0;
    P[1].x = 1; P[1].y = 0;
    i = 2; x = 1; y = 0;
    while( i <= MAX ){
	for ( int d = 0; d < 6; d++ ){
	    int W = w;
	    if ( d == 4 ) W++;
	    for (int k = 0; k < W; k++ ){
		if ( i > MAX ) break;
		P[i].x = P[i-1].x + dx[d]; 
		P[i].y = P[i-1].y + dy[d]; 
		i++;
	    }
	}
	w++;
    }
}

int main(){
    init();
    int A, B;
    double D1, D2, ax, ay, bx, by;
    while( scanf("%d %d", &A, &B) != EOF){
	D1 = 1.0* (max(A, B) - min(A, B));
	ax = (double)P[A].x + P[A].y*0.5;
	ay = (double)P[A].y*sqrt(3.0)/2;
	bx = (double)P[B].x + P[B].y*0.5;
	by = (double)P[B].y*sqrt(3.0)/2;
	
	D2 = sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
	printf("%.3lf %.3lf\n", D1, D2);
    }
    return 0;
}
