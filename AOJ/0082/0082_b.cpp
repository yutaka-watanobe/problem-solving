#include<iostream>
#include<algorithm>
using namespace std;
#define N 8

int q[N];

void compute(){
    int T[8] = {4, 1, 4, 1, 2, 1, 2, 1};
	//int T[8] = {4, 1, 2, 1, 2, 1, 4, 1};
    int A[8];

    int minv = (1<<21);
    int maxs = 0;
    for ( int i = 0; i < N; i++ ){
	int sum = 0;
	int s = 0, p = 10000000;
	for ( int j = 0; j < N; j++ ){
	    int rem = q[j] - T[j];
	    if ( rem > 0 ) sum += rem;
	    s += T[j]*p;
	    p /= 10;
	}
	if ( sum < minv ){
	    maxs = s;
	    minv = sum;
	    for ( int k = 0; k < N; k++ ) A[k] = T[k];
	} else if ( sum == minv && maxs > s){
	    for ( int k = 0; k < N; k++ ) A[k] = T[k];
	}
	
	int tmp = T[0];
	for ( int k = 0; k < N-1; k++ ){
	    T[k] = T[k+1];
	}
	T[N-1] = tmp;
    }

    for ( int i = 0; i < N; i++ ){
	cout << A[i] << " ";
    }
    cout << endl;
}

main(){
    while( cin >> q[0] ){
	for ( int i = 1; i < N; i++ ) cin >> q[i];
	compute();
    }
}
