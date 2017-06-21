#include<iostream>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++)

main(){
    char P[8][8], T[8][8];
    rep(i, 8) rep(j, 8) cin >> P[i][j];
    for ( int d = 90; d < 360; d += 90 ){
	cout << d << endl;
	rep(i, 8) rep(j, 8) T[i][j] = P[i][j];
	rep(i, 8) rep(j, 8) P[j][8-i-1] = T[i][j];
	rep(i, 8){
	    rep(j, 8) cout << P[i][j];
	    cout << endl;
	} 
    }
}
