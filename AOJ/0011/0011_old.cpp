#include<stdio.h>
#define MAX 32

using namespace std;

int G[MAX][MAX], R[MAX];
int w, n, a, b;

void parse( int p ){
    int j = p;
    for ( int i = 0; i < n + 1; i++ ) j = G[i][j];
    R[j] = p;
}

main(){
    scanf("%d %d", &w, &n);
    for ( int i = 0; i <= n + 1; i++ ){
	for ( int j = 1; j <= w; j++ ) G[i][j] = j;
    }

    for ( int i = 1; i <= n; i++ ){
	scanf("%d,%d", &a, &b);
	int tmp = G[i][a]; G[i][a] = G[i][b]; G[i][b] = tmp;
    }

    for ( int i = 1; i <= w; i++ ) parse( i );
    
    for ( int i = 1; i <= w; i++ ){
	printf("%d\n", R[i] );
    }
}
