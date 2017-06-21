#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#define MAX 800

using namespace std;

int N;
int M[MAX][MAX];

void prim(){
    dist = 0.0;
    
    bool visited[MAX];
    int cost[MAX];
    int pi[MAX];
    
    for ( int i = 0; i < N; i++ ){
	visited[i] = false;
	cost[i] = INT_MAX;
    }
    
    cost[0] = 0;
    pi[0] = -1;
    
    while ( 1 ){
	int mincost = INT_MAX;
	int u;
	for ( int i = 0; i < N; i++ ){
	    if ( !visited[i] && cost[i] < mincost ){
		mincost = cost[i];
		u = i;
	    }
	}
	
	if ( mincost == INT_MAX ) break;
	visited[u] = true;
	
	for ( int v = 0; v < N; v++ ){
	    if ( visited[v] || M[u][v] == INT_MAX ) continue;
	    if ( M[u][v] < cost[v] ){
		cost[v] = M[u][v];
		pi[v] = u;
	    }
	}
    }
}

void init(){
    for ( int i = 0; i < N; i++ )
	for ( int j = 0; j < N; j++ ) M[i][j] = INT_MAX;
}

bool input(){
    if ( scanf("%d", &N) == EOF ) return false;
    pair<int, int> points[MAX];
    
    for( int i = 0; i < N; i++ ){
	scanf("%d %d", &points[i].first, &points[i].second );
    }
    
    init();
    
    for ( int i = 0; i < N - 1; i++ ){
	for ( int j = i + 1; j < N; j++ ){
	    int x1 = points[i].first;
	    int x2 = points[j].first;
	    int y1 = points[i].second;
	    int y2 = points[j].second;
	    
	    M[i][j] = M[j][i] = sqrt( (int)(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
	}
    }
    
    int source, target, m;
    scanf("%d", &m);
    for ( int i = 0; i < m; i++ ){
	scanf("%d %d", &source, &target);
	source--; target--; // zero base
	M[source][target] = M[target][source] = 0.0;
    }
    
    return true;
}

void compute(){
    int dist;
    prim(dist);
    printf("%.2lf\n", dist);
}

int main(){
    while ( input() ) compute();

    return 0;
}

