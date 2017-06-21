#include<iostream>
#include<cstdio>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )
#define MAX 100
enum {SPACE, LOSE, BACK};

double C[MAX+2][MAX+1];
int S[MAX+1], N, T, L, B;

void compute(){
    C[0][0] = 1;
    rep(i, T) rep(j, N+1){
	for ( int k = 1; k <= 6; k++ ){
	    int t =  (j+k>N) ? 2*N-(j+k) : j+k;
	    int s = (S[j]==LOSE) ? i+2 : i+1;
	    if ( S[t] == BACK ) t = 0;
	    if ( j == N ) t = N;
	    C[s][t] += C[i][j]/6;
	}
    }

    printf("%.8lf\n", C[T][N]);
}

main(){
    int x;
    while( cin >> N >> T >> L >> B && N){
	rep(i, T+1) rep(j, N+1) C[i][j] = 0;
	rep(i, N+1) S[i] = SPACE;
	rep(i, L) { cin >> x; S[x] = LOSE; }
	rep(i, B) { cin >> x; S[x] = BACK; }
	compute();
    }
}
