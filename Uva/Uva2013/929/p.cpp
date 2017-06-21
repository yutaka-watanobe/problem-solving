#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
#define MAX 999
#define INFTY (1<<21)

class Node{
    public:
    int id, cost;
    Node(){}
    Node( int id, int cost): id(id), cost(cost){}
    bool operator < ( const Node &n ) const{
	return cost > n.cost;
    }
};

int G[MAX+2][MAX+2];
int N, M;

int dijkstra(){
    bool visited[MAX+2][MAX+2];
    int d[MAX+2][MAX+2];
    priority_queue<Node> PQ;


    for ( int i = 0; i < N+1; i++ ){
	for ( int j = 0; j < M+1; j++ ){
	    visited[i][j] = false;
	    d[i][j] = INFTY;
	}
    }

    visited[1][1] = true;
    d[1][1] = G[1][1];
    PQ.push(Node(M+1, G[1][1]));

    int di[4] = {0, -1, 0, 1};
    int dj[4] = {1, 0, -1, 0};

    Node u, v;
    int i, j, ni, nj;
    while( !PQ.empty()){
	u = PQ.top(); PQ.pop();
	
	i = u.id/M;
	j = u.id%M;
	
	for ( int r = 0; r < 4; r++ ){
	    ni = i + di[r];
	    nj = j + dj[r];

	    if ( !visited[ni][nj] && d[ni][nj] > d[i][j] + G[ni][nj] ){
		visited[ni][nj] = true;
		d[ni][nj] = d[i][j] + G[ni][nj];
		PQ.push(Node(ni*M+nj, d[ni][nj]));
	    }
	}
    }

    return d[N][M];
}

void input(){
    scanf("%d %d", &N, &M);
    for ( int i = 0; i < N; i++ ) G[i][0] = G[i][M+1] = INFTY;
    for ( int j = 0; j < M; j++ ) G[0][j] = G[N+1][j] = INFTY;
    for ( int i = 1; i <= N; i++ ){
	for ( int j = 1; j <= M; j++ ){
	    scanf("%d", &G[i][j]);
	}
    }
}

main(){
    int tcase; scanf("%d", &tcase);
    for ( int i = 0; i < tcase; i++ ){
	input();
	printf("%d\n", dijkstra());
    }
}
