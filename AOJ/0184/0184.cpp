#include<iostream>
using namespace std;
#define REP(i, n) for ( int i = 0; i < n; i++ )
int n, C[7];

int getIndex( int x ){
    REP(i, 7) if ( i*10 <= x && x < (i+1)*10 ) return i;
    return 6;
}

int main(){
    int x;
    while( cin >> n && n ){
	REP(i, 7) C[i] = 0;
	REP(i, n) { cin >> x; C[getIndex(x)]++;}
	REP(i, 7) cout << C[i] << endl;
    }
    return 0;
}
