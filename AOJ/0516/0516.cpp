#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100000
int A[MAX], n, k;

int main(){
    while(1){
	cin >> n >> k;
	if ( n == 0 && k == 0 ) break;
	for ( int i = 0; i < n; i++ ) cin >> A[i];
	int sum = 0, maxs = 0;
	for ( int i = 0; i < k; i++ ) sum += A[i];
	maxs = max( sum, maxs );

	for ( int i = k; i < n; i++ ){
	    sum -= A[i-k];
	    sum += A[i];
	    maxs = max( sum, maxs );
	}
	cout << maxs << endl;
    }
    return 0;
}
