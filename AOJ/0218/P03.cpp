#include<iostream>
#include<cassert>
using namespace std;

char judge(int pm, int pe, int pj){
    if ( pm == 100 || pe == 100 || pj == 100 ) return 'A';
    if ( (pm + pe)/2 >= 90 ) return 'A';
    if ( (pm + pe + pj)/3 >= 80 ) return 'A';
    if ( (pm + pe + pj)/3 >= 70 ) return 'B';
    if ( (pm + pe + pj)/3 >= 50 ){
	if ( pm >= 80 || pe >= 80 ) return 'B';
    }
    return 'C';
}

main(){
    int n, pm, pe, pj;
    while(1){
	cin >> n;
	if ( n == 0 ) break;
	assert(1 <= n && n <= 10000);
	for ( int i = 0; i < n; i++ ){
	    cin >> pm >> pe >> pj;
	    assert( 0 <= pm && pm <= 100);
	    assert( 0 <= pe && pe <= 100);
	    assert( 0 <= pj && pj <= 100);
	    cout << judge(pm, pe, pj) << endl;
	}
    }
}
