#include<stdio.h>
#define MAX 25
#define REP(i, e) for ( int i = 0; i < e; i++ )

int C[MAX][MAX][MAX], n;

int add(int x){
    return (x+1)%n;
}

int sub(int x){
    return (x==0)? (n-1): x-1;
}

void compute(){
    REP(i, n) REP(j, n) REP(k, n) C[i][j][k] = 0;
    int i, j, k, ni, nj, nk;
    i = j = n/2;
    k = 0;
    int cur = 1;
    REP(s, n*n*n){
	C[i][j][k] = cur++;
	ni = i; nj = add(j); nk = sub(k);
	if ( C[ni][nj][nk] ){
	    ni = sub(i); nj = j; nk = sub(k);
	    if ( C[ni][nj][nk] ){
		ni = i; nj = j; nk = add(k);
	    }
	}
	i = ni; j = nj; k = nk;
    }
    
    for ( int k = n-1; k >= 0; k-- ){
	if ( k != n-1 ) printf("\n");
	REP(i, n){
	    REP(j, n){
		if ( j ) printf(" ");
		printf("%5d", C[i][j][k]);
	    }
	    printf("\n");
	}
    }
    
}

int main(){
    bool isFast = true;
    while( scanf("%d", &n) && n ){
	if ( !isFast ) printf("\n");
	isFast = false;
	compute();
    }
    return 0;
}
