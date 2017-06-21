#include<iostream>
using namespace std;
#define MAX 1441

int getT(int x){ return (x/100)*60 + x%100; }

main(){
    int n, p, q, k, P[MAX], b, e;
    while( cin >> n >> p >> q  ){
	if ( n == 0 && p == 0 && q == 0 ) break;
	for ( int i = 0; i < MAX; i++ ) P[i] = 0;
	for ( int i = 0; i < n; i++ ){
	    cin >> k;
	    b = getT(p);
	    for ( int j = 0; j < k; j++ ){
		cin >> e; e = getT(e);
		for ( int a = b; a < e; a++ ) P[a] = 1;
		cin >> b; b = getT(b);
	    }
	    e = getT(q);
	    for ( int a = b; a < e; a++ ) P[a] = 1;
	}

	int maxv = 0, v = 0;
	for ( int i = 0; i < MAX; i++ ){
	    if ( P[i] ) { v++;	maxv = max(maxv, v); }
	    else { v = 0; }
	}
	cout << maxv << endl;
    }
}
