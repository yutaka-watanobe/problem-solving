// TST by Dynamic Programming
#include<iostream>
#define INFTY 1 << 21
#define MAX 15
#define SMAX 1 << MAX

using namespace std;

int size;
int source;
int G[MAX][MAX];
int F[SMAX][MAX];
pair<int, int> P[SMAX][MAX];

void compute( int source ){
    int smax = 1 << size;
    
    for ( int state = 1; state < smax; state++ ){
	for ( int j = 0; j < size; j++ ){
	    F[state][j] = INFTY;
	    P[state][j] = make_pair(-1, -1);
	}
    }

    for ( int j = 0; j < size; j++ ){
	F[1 << j][j] = G[source][j];
    }
    
    for ( int state = 1; state < smax; state++ ){
	for ( int i = 0; i < size; i++ ){
	    if ( ! (( 1 << i ) & state ) ) continue;
	    for ( int j = 0; j < size; j++ ){
		if ( ( 1 << j ) & state ) continue;
		int cost = F[state][i] + G[i][j];
		if ( cost < F[state|(1 << j)][j] ){
		    F[state|(1 << j)][j] = cost;
		    P[state|(1 << j)][j] = make_pair(state, i);
		}
	    }
	}
    }

    cout << F[smax-1][source] << endl;

    pair<int, int> pre = make_pair(smax-1, source);

    while ( 1 ){
	if( pre.first == -1 ) break;
	cout << pre.second << " ";
	pre = P[pre.first][pre.second];
    }
    cout << endl;
}

void input(){
    cin >> size;
    for ( int i = 0; i < size; i++ ){
	for ( int j = 0; j < size; j++ ){
	    G[i][j] = INFTY;
	}
    }
    int m, s, t, w; cin >> m;
    for ( int i = 0; i < m; i++ ){
	cin >> s >> t >> w;
	G[s][t] = w;
    }
}

main(){
    input();
    for ( int i = 0; i < size; i++ )
	compute(i);
}
