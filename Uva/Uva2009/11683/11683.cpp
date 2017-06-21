#include<iostream>
using namespace std;
#define MAX 10000
#define rep(i, n) for ( int i = 1; i <= n; i++)
int H, W, B[MAX+1];

int simulate(){
    int C[MAX+1];
    rep(i, W) C[i] = H;
    int cnt = 0;
    for (int h = H; h >= 1; h-- ){
	int j = 1;
	while( j <= W ){
	    if ( B[j] < h ){
		cnt++;
		while( j <= W && B[j] < h ) j++;
		j++;
	    } else j++;
	}
    }
    return cnt;
}

main(){
    while( cin >> H >> W ){
	if ( H == 0 && W == 0 ) break;
	rep(i, W) cin >> B[i];
	cout << simulate() << endl;
    }
}
