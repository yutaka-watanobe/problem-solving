#include<stdio.h>
#define MAX 8
#define REP(i, n) for ( int i = 0; i < n; i++ )

int G[MAX][MAX*(MAX-1)/2];
int n, m;

bool judge(){
    scanf("%d %d", &n, &m);
    REP(i, n) REP(j, m) scanf("%d", &G[i][j]);
    
    REP(j, m){
	int cnt = 0;
	int i1, i2;
	i1 = -1;
	REP(i, n) {
	    if ( G[i][j] ) {
		if ( i1 == -1 ) i1 = i;
		else i2 = i;
		cnt++;
	    }
	}
	if ( cnt != 2 ) return false;

	for ( int k = j; k < m; k++ ){
	    if ( k == j ) continue;
	    if ( G[i1][k] && G[i2][k] ) return false;
	}
    }
    return true;
}

int main(){
    int tcase; scanf("%d", &tcase);
    for ( int i = 0; i < tcase; i++ ){
	if ( judge() ) printf("Yes\n");
	else printf("No\n");
    }
    return 0;
}
