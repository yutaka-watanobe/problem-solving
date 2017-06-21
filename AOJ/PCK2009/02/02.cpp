#include<iostream>
#include<cassert>
using namespace std;

main(){
    int L, M, N;
    while( cin >> L && L ){
	assert( 1 <= L && L <= 1000000 );

	int t = 0, S = 0;
	for ( int i = 1; i <= 12; i++ ){
	    cin >> M >> N; 
	    assert( 0 <= N && N <= 100000);
	    assert( 0 <= M && M <= 100000);
	    assert( N <= M );
	    S += M - N;
	    if ( S >= L && t == 0 ) t = i;
	}
	if ( S < L ) cout << "NA" << endl;
	else cout << t << endl;
    }
}
