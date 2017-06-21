#include<iostream>
#include<climits>
using namespace std;
#define MAX 20

int T[MAX], n, sum, minv;

void rec( int cur, int v ){
    if ( cur == n ){
	int d = max(v, sum-v) - min(v, sum-v);
	minv = min(minv, d);
	return;
    }
    rec( cur+1, v);
    rec( cur+1, v+T[cur]);
}

void compute(){
    minv = INT_MAX;
    rec(0, 0);
    cout << minv << endl;
}

main(){
    while( cin >>n && n ) {
	sum = 0;
	for ( int i = 0; i < n; i++ ){
	    cin >> T[i]; sum += T[i];
	}
	compute();
    }
}
