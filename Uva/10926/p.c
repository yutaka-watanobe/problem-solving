// Graph - DFS
#include<stdio.h>
#define MAX 101

bool M[MAX][MAX];
int N;
int ndependencies[MAX];
bool visited[MAX];

void dfs( int u ){
    ndependencies[u]++;
    visited[u] = true;
    for ( int v = 0; v < N; v++ ){
	if ( M[u][v] && !visited[v]){
	    dfs( v );
	}
    }
}

void init(){
    for ( int i = 0; i < N; i++ ) visited[i] = false;
}

void compute(){
    for ( int i = 0; i < N; i++ ) ndependencies[i] = 0;

    for ( int i = 0; i < N; i++ ) {
	init();
	dfs( i );
    }

    int maxIndex, maxValue;
    maxValue = 0;

    for ( int i = 0; i < N; i++ ){
	if ( maxValue < ndependencies[i] ){
	    maxValue = ndependencies[i];
	    maxIndex = i;
	}
    }

    printf("%d\n", maxIndex + 1);
}

bool read(){
    scanf("%d", &N);
    if ( N == 0 ) return false;
    for ( int i = 0; i < N; i++ ){
	for ( int j = 0; j < N; j++ ) M[i][j] = false;
    }

    int k;
    for ( int target = 1; target <= N; target++ ){
	scanf("%d", &k);
	for ( int j = 0; j < k; j++ ){
	    int source;
	    scanf("%d", &source);
	    M[source-1][target-1] = true;;
	}
    }
    /*
    for ( int i = 0; i < N; i++ ){
	for ( int j = 0; j < N; j++ ){
	    if ( M[i][j] ) printf("1 ");
	    else printf("0 ");
	}
	printf("\n");
	}*/
    return true;
}

main(){
    while ( read() ) compute();
}
