#include<iostream>
#define rep(i, n ) for ( int i = 0; i < n; i++ )
using namespace std;

#define RMAX 10
#define CMAX 10000

int R, C;
int T[RMAX][CMAX];
bool F[RMAX];
int maxv;

int getValue(){
    int nb = 0, nw = 0;
    int sum = 0;
    for ( int j = 0; j < C; j++ ){
	nb = nw = 0;
	for ( int i = 0; i < R; i++ ){
	    if ( F[i] ){
		if ( T[i][j] == 1 ) nw++;
		else nb++;
	    } else {
		if ( T[i][j] == 1 ) nb++;
		else nw++;
	    }
	}
	sum += max( nb, nw );
    }
    return sum;
    
}


void rec( int u ){
    if ( u == R ){
	maxv = max( maxv, getValue() );
	return;
    }
    
    F[u] = false;
    rec(u+1);
    F[u] = true;
    rec(u+1);
}

void compute(){
    maxv = 0;
    rec(0);
    cout << maxv << endl;
}

int main(){
    while(1){
	cin >> R >> C;
	if ( R == 0 && C == 0 ) break;
	rep(i, R) rep(j, C) cin >> T[i][j];
	compute();
    }
    return 0;
}
