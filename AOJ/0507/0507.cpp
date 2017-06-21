// f(n, m) = [m] f(n-m, m)
//           [m-1] f(n-m+1, m-1)
//           ..
//           [1]f(n-1, 1);
             
#include<iostream>
#include<vector>
using namespace std;

void rec( vector<int> v, int n, int m ){
    if ( n == 0 ) {
	for ( int i = 0; i < v.size(); i++ ){
	    if ( i ) cout << " ";
	    cout << v[i];
	}
	cout << endl;
	return;
    }

    for ( int i = min(n, m); i >= 1; i-- ){
	vector<int> u = v;
	u.push_back(i);
	rec(u, n-i, i);
    }
}

main(){
    int n;
    while( cin >> n ){
	if ( n == 0 ) break;
	vector<int> v;
	rec(v, n, n);
    }
}
