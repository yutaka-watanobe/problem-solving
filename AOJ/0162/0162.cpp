#include<iostream>
using namespace std;

#define MAX 1000000

main(){
    bool H[MAX+1];
    int T[MAX+1];
    for ( int i = 0; i <= MAX; i++ ){
	H[i] = false;
	T[i] = 0;
    }

    H[1] = H[2] = H[3] = H[5] = true;
    for ( long long i = 1; i <= MAX; i *= 2 ){
	for ( long long j = 1; j <= MAX; j *= 3 ){
	    if ( i*j > MAX ) continue;
	    for ( long long k = 1; k <= MAX; k *= 5 ){
		if ( i*j*k > MAX ) continue;
		H[i*j*k] = true;
	    }
	}
    }
    for ( int i = 1; i <= MAX; i++ ){
	T[i] += T[i-1];
	if ( H[i] ) T[i]++;
    }

    int l, r;
    while( cin >> l && l ){
	cin >> r;
	int a = T[r] - T[l];
	if ( H[l] ) a++;
	cout << a << endl;
    }
}
