#include<iostream>
#include<stdio.h>
#include<cfloat>
#include<algorithm>
using namespace std;
#define MAX 100

int D[MAX+1];
double C[MAX+1];
int n, r;
double b, v, e, f;

double getCost( int d ){
    double sum = 0.0;
    for ( int x = 0; x <= d - 1; x++ ){
	if ( x >= r ) sum +=  1/(v - e*(x - r));
	else sum +=1/(v - f*(r - x));
    }
    return sum;
}

void compute(){
    for ( int i = 1; i <= n; i++ ) C[i] = FLT_MAX;
    C[0] = 0.0;
    for ( int i = 1; i <= n; i++ ){
	for ( int j = 0; j < i; j++ ){
	    C[i] = min( C[i], C[j] + getCost(D[i] - D[j]) + (j == 0 ? 0 : b) );
	}
    }
    printf("%.4lf\n", C[n]);
}

bool input(){
    cin >> n;
    if ( n == 0 ) return false;
    D[0] = 0;
    for ( int i = 1; i <= n; i++ ) cin >> D[i];
    cin >> b >> r >> v >> e >> f;
    return true;
}

main(){
    while ( input() ) compute();
}
