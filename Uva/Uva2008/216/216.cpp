#include<iostream>
#include<stdio.h>
#include<cmath>
#include<cfloat>
#include<algorithm>
using namespace std;

#define MAX 8

struct Point { int x, y; };

int n;
Point P[MAX];

double getDist( Point p1, Point p2 ){
    return sqrt( (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

void compute(){
    int O[MAX], OPT[MAX];
    for ( int i = 0; i < n; i++ ) O[i] = i;
    double mind = FLT_MAX;

    double D[MAX][MAX];
    for ( int i = 0; i < n; i++ )
	for ( int j = 0; j < n; j++ ) D[i][j] = getDist(P[i], P[j]) + 16;


    do{
	double dist = 0.0;
	for ( int i = 0; i < n-1; i++ ){
	    //	    dist += getDist( P[O[i]], P[O[i+1]] )+16.0;
	    dist += D[O[i]][O[i+1]];
	}
	if ( mind > dist ){
	    mind = dist;
	    for ( int i = 0; i < n; i++ ) OPT[i] = O[i];
	}
    } while( next_permutation( O, O + n ) );

    for ( int i = 0; i < n-1; i++ ){
	printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", P[OPT[i]].x, P[OPT[i]].y, P[OPT[i+1]].x, P[OPT[i+1]].y, D[OPT[i]][OPT[i+1]]);
    }
    printf("Number of feet of cable required is %.2lf.\n", mind);
}

int main(){
    int tcase = 1;
    while( cin >> n && n) {
	for ( int i = 0; i < n; i++ ) { cin >> P[i].x >> P[i].y; }
	cout << "**********************************************************" << endl;
	cout << "Network #" << tcase++ << endl;
	compute();
    }
    return 0;
}
