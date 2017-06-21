#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 10000

main(){
    int A[MAX];
    int n;
    while( cin >> n && n ){
	for ( int i = 0; i < n; i++ ) cin >> A[i];
	sort(A, A+n);

	long long total = 0;
	long long sum = 0;
	for ( int i = 1; i < n; i++ ) {
	    sum += A[i-1];
	    total += sum;

	}
	cout << total << endl;
    }
    
}
