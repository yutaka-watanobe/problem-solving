#include<iostream>
using namespace std;

#define MAX 20

int T[MAX][MAX], X[MAX][MAX];
int H, W, n;
int main(){
    while(1){
	cin >> W >> H;
	if ( W == 0 && H == 0 ) break;
	cin >> n;
	for ( int i = 1; i <= H; i++ ){
	    for ( int j = 1; j <= W; j++ ) X[i][j] = 0;
	}
	int x, y;
	for ( int i = 0; i < n; i++ ){
	    cin >> y >> x;
	    X[x][y] = 1;
	}

	for ( int i = 0; i <= H; i++ ) T[i][0] = 0;
	for ( int i = 0; i <= W; i++ ) T[0][i] = 0;
	
	T[0][1] = 1;

	for ( int i = 1; i <= H; i++ ){
	    for ( int j = 1; j <= W; j++ ){
		if ( X[i][j] ) T[i][j] = 0;
		else {
		    T[i][j] = T[i-1][j] + T[i][j-1];
		}
	    }
	}

	cout << T[H][W] << endl;
    }
    return 0;
}
