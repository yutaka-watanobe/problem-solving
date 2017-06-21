#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

void compute(){
    int A[9], B[9];
    for ( int i = 0; i < 9; i++ ) cin >> A[i];
    for ( int i = 0; i < 9; i++ ) cin >> B[i];
    
    sort(A, A + 9);
    int w = 0, sum = 0;
    do{
	int a = 0, b = 0;
	for ( int i = 0; i < 9; i++ ){
	    if ( A[i] > B[i] ) a += A[i]+B[i];
	    else b += A[i]+B[i];
	}
	if ( a > b ) w++;
	sum++;
    } while( next_permutation(A, A+9));
    double ra = 1.0*w/sum;
    double rb = 1 - ra;
    printf("%.8lf %.8lf\n", ra, rb);
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ) compute();
}
