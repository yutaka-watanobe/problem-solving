#include<iostream>
using namespace std;

main(){
    int n, B[10], P[2], b, s;
    cin >> n;
    for ( int t = 0; t < n; t++ ){
	for ( int i = 0; i < 10; i++ ) cin >> B[i];
	P[0] = P[1] = 0;
	bool p = true;
	for ( int i = 0; i < 10; i++ ){
	    if ( P[0] > P[1] ) { b = 0; s = 1; }
	    else { b = 1; s = 0;}
	    if ( B[i] > P[b] ) P[b] = B[i];
	    else if ( B[i] > P[s] ) P[s] = B[i];
	    else {p = false; break;}
	}
	if ( p ) cout << "YES" << endl;
	else cout << "NO" << endl;
    }
}
