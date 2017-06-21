#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 5000
typedef  long long ullong;

int N, size;
int T[MAX], P[MAX];

int binarySearch( int left, int right, int target ){
    int mid;
    while( left < right ){
	mid = (left + right ) / 2;
	if ( T[mid] == target ) return P[mid];
	if ( T[mid] < target ) left = mid+1;
	else right = mid;
    }

    return 0;
}

void compute(){
    ullong counter = 0;
    int is, ie;

    for ( int j = size-2; j >= 1; j-- ){
	is = max(0, distance(T, lower_bound(T, T+(j), T[j+1] - T[j])));
	ie = min(j-1, distance(T, lower_bound(T, T+(j), T[size-1] - T[j])));
	for ( int i = is; i <= ie; i++ ){
	    counter += (P[i]*P[j]*binarySearch( j+1, size, T[i] + T[j] ));
	}
    }

    for ( int i = 0; i < size-1; i++ ){
	if ( P[i] < 2 ) continue;
	counter += ((P[i]*(P[i]-1)/2)*binarySearch(i+1, size, T[i]*2));
    }

    printf("%lld\n", counter);
}

void construct(){
    int I[MAX];
    for ( int i = 0; i < N; i++ ) scanf("%d", &I[i]);

    sort( I, I + N );
    int pre = I[0];
    T[0] = pre; 
    P[0] = 1;
    size = 1;
    for ( int i = 1; i < N; i++ ){
	if ( pre == I[i] ) P[size-1]++;
	else {
	    size++;
	    T[size-1] = I[i];
	    P[size-1] = 1;
	    pre = I[i];
	}
    }
}

int main(){
    while( scanf("%d", &N) != EOF ){
	construct();
	compute();
    }

    return 0;
}
