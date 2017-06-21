#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
#define MAX 1000
#define EPS (1e-8)

struct Point{ double x, y; };

int N;
Point H[MAX], G, D;

void compute(){
    for ( int i = 0; i < N; i++ ){
	double gdist = (H[i].x - G.x)*(H[i].x - G.x) + (H[i].y - G.y)*(H[i].y - G.y);
	double ddist = (H[i].x - D.x)*(H[i].x - D.x) + (H[i].y - D.y)*(H[i].y - D.y);
	if ( gdist*4 < ddist || fabs(gdist*4 - ddist) <= EPS ){
	    printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", H[i].x, H[i].y);
	    return;
	}
    }
    printf("The gopher cannot escape.\n");
}

void input(){
    scanf("%lf %lf", &G.x, &G.y);
    scanf("%lf %lf", &D.x, &D.y);
    for ( int i = 0; i < N; i++ ){
	scanf("%lf %lf", &H[i].x, &H[i].y);
    }
}

int main(){
    while( scanf("%d", &N) != EOF ){
	input();
	compute();
    }
    return 0;
}


