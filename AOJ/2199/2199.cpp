// DP
#include<iostream>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )
#define NMAX 20001
#define MMAX 16
#define INFTY (1<<30)
int N, M, C[MMAX], X[NMAX];
unsigned long  T[256][NMAX];

unsigned long  compute(){
    rep(i, 256) rep(j, N+1) T[i][j] = INFTY;
    T[128][0] = 0;
    rep(j, N){
	rep(i,256){
	    if ( T[i][j] == INFTY ) continue;
	    rep(k, M){
		int p = i + C[k];
		if ( p > 255 ) p = 255;
		if ( p < 0 ) p = 0;
		T[p][j+1] = min(T[p][j+1], T[i][j] + (X[j+1]-p)*(X[j+1]-p));
	    }
	}
    }
    unsigned long minv = INFTY;
    rep(i, 256) minv = min(minv, T[i][N]);
    return minv;
}

main(){
    while(cin >> N >> M && N ){
	rep(i, M) cin >> C[i];
	rep(i, N) cin >> X[i+1];
	cout << compute() << endl;
    }
}
