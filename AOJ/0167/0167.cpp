#include<iostream>
using namespace std;

main(){
    int A[100], n;
    while( cin >> n && n ){
	for ( int i = 0; i < n; i++ ) cin >> A[i];
	int cnt = 0;
	for ( int end = n-1; end > 0; end-- ){
	    for ( int j = 0; j < end; j++ ){
		if ( A[j+1] < A[j] ){
		    int t = A[j]; A[j] = A[j+1]; A[j+1] = t;
		    cnt++;
		}
	    }
	}
	cout << cnt << endl;
    }

}
