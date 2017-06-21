#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 21

int NN, NB, C[4];
bool G[MAX][MAX];
int maxd;
int maxv;

bool visited[MAX];
int color[MAX];
int colorT[4];

bool input(){
    cin >> NN;
    if ( NN == 0 ) return false;
    cin >> NB;
    for ( int i = 0; i < 4; i++ ) cin >> C[i];
    int s, t;
    for ( int i = 0; i < NN; i++ )
	for ( int j = 0; j < NN; j++ ) G[i][j] = false;

    int degree[MAX];
    for ( int i = 0; i < NN; i++ ) degree[i] = 0;
    for ( int i = 0; i < NB; i++ ){
	cin >> s >> t;
	s--; t--;
	degree[s]++; degree[t]++;
	G[s][t] = G[t][s] = true;
    }

    maxd = 0;
    for ( int i = 0; i < NN; i++ ){
	if ( degree[maxd] < degree[i] ) maxd = i;
    }

    sort ( C, C+4 );
}

int getColor(){
    int total = 0;
     for ( int i = 0; i < NN; i++ ){
	for ( int j = 0; j < NN; j++ ){
	    if ( !G[i][j] || i >= j) continue;

	    int c = colorT[color[i]] - colorT[color[j]];
	    total += c*c;
	}
    }
    return total;
}

int getCost(){

    int opv = 0;

    colorT[0] = C[0];

    colorT[1] = C[1];
    colorT[2] = C[2];
    colorT[3] = C[3];
    opv = max( opv, getColor() );

    colorT[1] = C[1];
    colorT[2] = C[3];
    colorT[3] = C[2];
    opv = max( opv, getColor() );

    colorT[1] = C[2];
    colorT[2] = C[1];
    colorT[3] = C[3];
    opv = max( opv, getColor() );

    colorT[1] = C[2];
    colorT[2] = C[3];
    colorT[3] = C[1];
    opv = max( opv, getColor() );

    colorT[1] = C[3];
    colorT[2] = C[1];
    colorT[3] = C[2];
    opv = max( opv, getColor() );

    colorT[1] = C[3];
    colorT[2] = C[2];
    colorT[3] = C[1];
    opv = max( opv, getColor() );

    return opv;
}


bool checkColor( int u, int c ){
    for ( int v = 0; v < NN; v++ ){
	if ( !G[u][v] ) continue;
	if ( color[v] == c ) return false;
    }
    return true;
}

void dfs( int u, int col, int cnt ){
    visited[u] = 0;
    color[u] = col;

    if ( cnt == NN ){
	//	maxv = max ( maxv, getCost() );
    }

    for ( int v = 0; v < NN; v++ ){
	if ( !G[u][v] || visited[v] ) continue;
	for ( int c = 0; c < 4; c++ ){
	    if ( checkColor( v, c ) ) dfs( v, c, cnt+1);
	}
    }
}

void compute(){
    
    for ( int i = 0; i < NN; i++ ) {
	visited[i] = false;
	color[i] = -1;
    }
    
    int maxv = 0;

    dfs(maxd, 0, 1);

    cout << maxv << endl;
}


main(){
    while( input() ){
	compute();
    }
}
