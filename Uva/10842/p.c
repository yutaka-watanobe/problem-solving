#include<stdio.h>
#include<climits>

#define MAX 101

using namespace std;

int M[ MAX ][ MAX ];
int n;

int prim(){
    bool visited[MAX];
    int d[MAX], p[MAX];

    for ( int i = 0; i < n; i++ ) {
	visited[i] = false;
	d[i] = -1;
    }
    
    d[0] = INT_MAX;
    p[0] = -1;
    
    int minL = INT_MAX;
    
    while ( 1 ){
	
	int maxValue = -1;
	int kernel = -1;
	
	for ( int  i = 0; i < n; i++ ){
	    if ( !visited[i] && maxValue < d[i] ){
		maxValue = d[i];
		kernel = i;
	    }
	}
	
	if ( kernel == -1 ) break;
	
	visited[kernel] = true;
	
	if ( p[kernel] != -1 && minL > M[kernel][p[kernel]] ){
	    minL = M[kernel][p[kernel]];
	}
	
	for ( int v = 0; v < n; v++ ){
	    if ( !visited[v] && d[v] < M[kernel][v] ){
		d[v] = M[kernel][v];
		p[v] = kernel;
	    }
	}
    }
    
    return minL;
}

void read(){
    int m;
    scanf("%d %d", &n, &m);
    for ( int i = 0; i < n; i++ ){
	for ( int j = i; j < n; j++ ){
	    M[i][j] = M[j][i] = -1;
	}
    }
    
    int source, target, w;
    
    for ( int i = 0; i < m; i++ ){
	scanf("%d %d %d", &source, &target, &w);
	if ( M[source][target] < w ){
	    M[source][target] = M[target][source] = w;
	}
    }
}

main(){
    int tcase; scanf("%d", &tcase);
    for ( int i = 1; i <= tcase; i++ ){
	read();
	printf("Case #%d: %d\n", i, prim());
    }
}
