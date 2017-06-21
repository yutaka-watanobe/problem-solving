#include<stdio.h>
#include<algorithm>
using namespace std;
#define NMAX 10
#define MMAX 100
#define LIMIT 5

int N, M, L[NMAX+1][MMAX+1];

void input(){
    scanf("%d %d", &N, &M);
    for ( int i = 1; i <= N; i++ ){
	for ( int j = 1; j <= M; j++ ) scanf("%d", &L[i][j]);
    }
}

void compute(){
    double T[NMAX+1][MMAX+1][MMAX+1];
    for ( int i = 1; i <= N; i++ ){
	for ( int j = 1; j <= M; j++ ){
	    for ( int k = 1; k <= M; k++ ) T[i][j][k] = 0.0;
	}
    }

    for ( int j = 1; j <= M; j++ ){
	if ( L[1][j] < LIMIT ) continue;
	T[1][j][j] = 1.0*L[1][j];
    }

    for ( int i = 2; i <= N; i++ ){
	for ( int j = 1; j <= (M-i+1); j++ ){
	    if ( L[i][j] < LIMIT ) continue;
	    for ( int k = (i+j-2); k <= M; k++ ){
		for ( int l = 1; l <= M; l++ ){
		    T[i][j][k] = max( T[i][j][k], T[i-1][l][k-j] + L[i][j]);
		}
	    }
	}
    }

    double maxv = 0.0;
    for ( int j = 1; j <= M; j++ ){
	for ( int k = 1; k <= M; k++ ) maxv = max( maxv, T[N][j][k] );
    }

    double average = maxv/N + (1e-9);

    if ( average < LIMIT ){
	printf("Peter, you shouldn't have played billiard that much.\n");
    } else {
	printf("Maximal possible average mark - %.2lf.\n", average);
    }

}

main(){
    int tcase; scanf("%d", &tcase);
    for ( int i = 0; i < tcase; i++ ){
	input();
	compute();
    }
}
