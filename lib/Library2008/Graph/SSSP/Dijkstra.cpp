// 423
#include<iostream>
#include<string>
#include<algorithm>
#define MAX 101

using namespace std;

int N, M[MAX][MAX];

void dijkstra( int s, int d[], int pi[] ){
    bool visited[MAX];
    for ( int i = 0; i < N; i++ ){
	d[i] = INT_MAX;
	visited[i] = false;
    }

    d[s] = 0;
    pi[s] = -1;

    while( 1 ){
	int u;
	int mincost = INT_MAX;
	for ( int i = 0; i < N; i++ ){
	    if ( !visited[i] && d[i] < mincost ){
		mincost = d[i]; u = i;
	    }
	}

	if ( mincost == INT_MAX ) break;

	visited[u] = true;

	for ( int v = 0; v < N; v++ ){
	    if ( visited[v] || M[u][v] == INT_MAX ) continue;
	    if ( d[u] + M[u][v] < d[v] ){
	      d[v] = d[u] + M[u][v];
	      pi[v] = u;
	    }
	}
    }
}

main(){
    cin >> N;
    string x;
    for ( int i = 1; i < N; i++ ){
	for ( int j = 0; j < i; j++ ){
	    cin >> x;
	    if ( x == "x" )
		M[i][j] = M[j][i] = INT_MAX;
	    else
		M[i][j] = M[j][i] = atoi(x.c_str());
	}
    }

    int d[MAX];
    int pi[MAX];
    dijkstra(0,  d, pi );
    int maxvalue = 0;
    for ( int i = 0; i < N; i++ ){
	if ( d[i] != INT_MAX && maxvalue < d[i] ) maxvalue = d[i];
	char p = 'a' + pi[i];
	char c = 'a' + i;
	cout << p << "-->" << c << endl;
    }
    cout << maxvalue << endl;
}

