#include<iostream>
#include<queue>
using namespace std;

#define MAX 1000
int size;
int adjMatrix[MAX][MAX]; // graph structure

void breadthFirstSearch( int s, int g ){
    queue<int> Q;
    bool visited[MAX];
    int dist[MAX], pi[MAX];

    for ( int i = 0; i < size; i++ ) {
	visited[i] = false;
	dist[i] = INT_MAX;
    }

    Q.push(s);
    visited[s] = true;
    dist[s] = 0;
    pi[s] = -1;

    int u;
    while ( !Q.empty() ){
	u = Q.front(), Q.pop();
	for ( int v = 0; v < size; v++ ){
	    if ( !adjMatrix[u][v] ) continue;
	    if ( !visited[v] ){
		visited[v] = true;
		dist[v] = dist[u] + 1;
		pi[v] = u;
		Q.push( v );
	    }
	}
    }

    // output result
    for ( int i = 0; i < size; i++ ){
      cout << i << " " << dist[i] << endl;
    }
    cout << endl;
    // output path form s to g
    for (; g != -1; g = pi[g] ) cout << g << " <- ";
    cout << endl;
}

void inputGraph(){
    cin >> size;
    for ( int i = 0; i < size; i++ ){
	for ( int j = 0; j < size; j++ ){
	    adjMatrix[i][j] = 0;
	}
    }

    for ( int i = 0; i < size; i++ ){
	for ( int j = 0; j < size; j++ ){
	    cin >> adjMatrix[i][j];
	}
    }
}

int main(){
    inputGraph();
    breadthFirstSearch(0, size-1);
    return 0;
}

