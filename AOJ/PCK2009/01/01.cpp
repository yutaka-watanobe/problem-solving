#include<iostream>
#include<cassert>
using namespace std;
#define N 5

main(){
    int T[N];
    while( cin >> T[0] && T[0] ){
	for ( int i = 1; i < N; i++ ) cin >> T[i];
	for ( int i = 0; i < N; i++ ){
	    int w = 0, l = 0;
	    for ( int j = 0; j < N; j++ ){
		if ( T[i]%3 == T[j]-1 ) w++;
		if ( T[j]%3 == T[i]-1 ) l++;
	    }
	    if ( w && l == 0 ) cout << 1 << endl;
	    else if ( l && w == 0 ) cout << 2 << endl;
	    else cout << 3 << endl;
	}
    }
}
