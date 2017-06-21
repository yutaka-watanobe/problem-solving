#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 10

main(){
    int f, r, F[MAX], R[MAX];
    double D[MAX*MAX];
    while(1){
	cin >> f;
	if ( f == 0 ) break;
	cin >> r;
	for ( int i = 0; i < f; i++ ) cin >> F[i];
	for ( int i = 0; i < r; i++ ) cin >> R[i];

	int k = 0;
	for ( int i = 0; i < f; i++ ){
	    for ( int j = 0; j < r; j++ ){
		D[k++] = 1.0*F[i]/R[j];
	    }
	}

	sort( D, D + k );

	double maxd = D[1]/D[0];
	for ( int i = 2; i < k; i++ ){
	    maxd = max( maxd, D[i]/D[i-1]);
	}

	printf("%.2lf\n", maxd);
    }
}
