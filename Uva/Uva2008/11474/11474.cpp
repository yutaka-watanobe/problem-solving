#include<iostream>
#include<cmath>
using namespace std;
#define MAX 110
#define REP(i, e) for ( int i = 0; i < e; i++ )

struct Point{ int x, y;};

int n, m, k, d, N;
bool G[MAX][MAX];
Point P[MAX][10];
int NB[MAX]; // number of branch
bool V[MAX];

double getDist( Point p1, Point p2 ){
    return sqrt( (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) );
}

bool isConnected( int s, int t, int dist ){
    for ( int i = 0; i < NB[s]; i++ ){
	for ( int j = 0; j < NB[t]; j++ ){
	    if ( getDist( P[s][i], P[t][j] ) <= dist ) return true;
	}
    }
    return false;
}

void makeGraph(){
    cin >> n >> m >> k >> d;
    N = n + 1;
    REP(i, N) REP(j, N ) G[i][j] = false;
    
    for ( int i = 0; i < m; i++ ) {
	cin >> P[0][i].x >> P[0][i].y;
    }
    NB[0] = m;
    
    for ( int i = 1; i < 1 + n; i++  ){
	int b; cin >> b;
	NB[i] = b;
	for ( int j = 0; j < b; j++ ){
	    cin >> P[i][j].x >> P[i][j].y;
	}
    }

    for ( int i = 1; i < N-1; i++ ){
	for ( int j = i+1; j < N; j++ ){
	    if ( isConnected(i, j, k) ) G[i][j] = G[j][i] = true;
	}
    }

    for ( int j = 1; j < N; j++ ){
	if ( isConnected(0, j, d) ) G[0][j] = G[j][0] = true;
    }

    for ( int i = 0; i < N; i++ ) V[i] = false;
}

bool dfs(int u){
    if ( u == 0 ) return true;
    V[u] = true;
    for ( int v = 0; v < N; v++ ){
	if ( G[u][v] && !V[v]){
	    if ( dfs(v) ) return true;
	}
    }
    return false;
}

int main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	makeGraph();
	if ( dfs(1) ) cout << "Tree can be saved :)" << endl;
	else cout << "Tree can't be saved :(" << endl;
    }
}



