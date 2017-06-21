#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 100

int main(){
    int n;
    int A[MAX], P[MAX];
    while( cin >> n && n ){
	for ( int i = 0; i < n; i++ ) cin >> A[i];
	for ( int i = 0; i < n; i++ ) P[i] = 0;

	//sort( A, A + n );
	for ( int end = n-1; end >= 1; end-- ){
	  for ( int i = 0; i <= end; i++ ){
	    if ( A[i] > A[i+1] ) {
	      int tmp = A[i];
	      A[i] = A[i+1];
	      A[i+1] = tmp;
	    }
	  }
	}


	P[0] = A[0];
	int total = P[0];
	for ( int i = 1; i < n; i++ ) {
	    P[i] = P[i-1] + A[i];
	    total += P[i];
	}
	cout << total << endl;
    }
}
