#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 5000

int N, T[MAX];

int binarySearch( int left, int right, int target ){
    int mid;
    while( left < right ){
	mid = (left + right ) / 2;
	if ( T[mid] == target ) {
	    int counter = 1;
	    int i = mid + 1;
	    while( i < right && T[i] == target ){ counter++; i++; }
	    i = mid-1;
	    while( i >= left && T[i] == target ){ counter++; i--; }
	    return counter;
	}

	if ( T[mid] < target ) left = mid+1;
	else right = mid;
    }

    return 0;
}

int main(){
    int counter = 0;
    while( scanf("%d", &N) != EOF ){
	for ( int i = 0; i < N; i++ ) scanf("%d", &T[i]);
	sort( T, T + N );
	//	for ( int i = 0; i < N; i++ ) cout << T[i] << " ";
	//	cout << endl;
	counter = 0;
	for ( int i = 0; i < N-2; i++ ){
	    for ( int j = i+1; j < N-1; j++ ){
		//counter += binarySearch( j+1, N, T[i] + T[j] );
		counter += ( distance(T, upper_bound(T + j+1, T + N, T[i]+T[j]) -distance(T, lower_bound(T + j+1, T + N, T[i]+T[j]) )));
				      
	    }
	}
	printf("%d\n", counter);
    }
    return 0;
}
