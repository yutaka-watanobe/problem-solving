#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 1000

main(){
    int n, m, P[MAX], sum;
    while(1){
	cin >> n >> m;
	if ( n == 0 && m == 0 ) break;
	sum = 0;
	for ( int i = 0; i < n; i++ ) {
	    cin >> P[i];
	    sum += P[i];
	}
	sort(P, P+n, greater<int>());
	for ( int i = m-1; i < n; i += m ) sum -= P[i];
	cout << sum << endl;
    }
    
}
