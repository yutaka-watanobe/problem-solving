#include<stdio.h>
#include<algorithm>
using namespace std;
#define REP(i,e) for ( int i = 0; i < e; i++ )
#define MAX 15
static const int di[4] = {0, -1, 0, 1};
static const int dj[4] = {1, 0, -1, 0};

int N, IG[MAX][MAX];
int min_trans;

void flip( int i, int j, int G[MAX][MAX], int P[MAX][MAX] ){
    G[i][j]++;
    int ni, nj;
    for ( int r = 0; r < 4; r++ ){
	ni = i + di[r];
	nj = j + dj[r];
	if ( ni < 0 || nj < 0 || ni >= N || nj >= N ) continue;
	P[ni][nj]++;
    }
}

void parse(int nflip){
    int G[MAX][MAX], P[MAX][MAX], ni, nj;

    REP(i, N) REP(j, N) G[i][j] = IG[i][j];
    REP(i, N) REP(j, N) P[i][j] = 0;
    REP(i, N) REP(j, N){
	if ( G[i][j] ){
	    for ( int r = 0; r < 4; r++ ){
		ni = i + di[r];
		nj = j + dj[r];
		if ( ni < 0 || nj < 0 || ni >= N || nj >= N ) continue;
		P[ni][nj]++;
	    }
	}
    }

    for ( int i = 1; i < N; i++ ) REP(j, N){
	if ( P[i-1][j]%2 == 1 ){
	    if ( G[i][j] ) return;
	    flip(i, j, G, P); nflip++;
	}
    }

    for ( int j = 0; j < N; j++ ) if ( P[N-1][j]%2 == 1 ) return;

    min_trans = min( min_trans, nflip );
}

void recursive( int depth, int nflip ){
    if ( depth == N ){ parse(nflip);	return; }
    recursive(depth+1, nflip);
    if ( IG[0][depth] ==  0 ){
	IG[0][depth] = (IG[0][depth]+1)%2;
	recursive(depth+1, nflip+1);
	IG[0][depth] = (IG[0][depth]+1)%2;
    }
}

int compute(){
    scanf("%d", &N);
    REP(i,N) REP(j,N) scanf("%d", &IG[i][j]);

    min_trans = INT_MAX;
    recursive(0, 0);
    if ( min_trans == INT_MAX ) return -1;
    else return min_trans;
}

int main(){
    int tcase; scanf("%d", &tcase);
    for ( int i = 1; i <= tcase; i++ ){
	printf("Case %d: %d\n", i, compute());
    }
    return 0;
}
