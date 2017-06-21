// DP
// should be solved by DP not Dijkstra
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
#define MAX 100

int N, G[MAX][MAX];
map<string, int> N_I; // name to index;

void input(){
    N_I = map<string, int>();
    string name;
    cin >> N;
    for ( int i = 0; i < N; i++ ) {
	cin >> name; N_I[name] = i;
    }

    for ( int i = 0; i < N; i++ ) fill ( G[i], G[i] + N, INT_MAX );

    int M, cost; cin >> M;
    string source, target;
    for ( int i = 0; i < M; i++ ){
	cin >> source >> target >> cost;
	G[N_I[source]][N_I[target]] = min(G[N_I[source]][N_I[target]], cost);
    }
}

void compute(){
    int T[MAX][MAX];
    for ( int i = 0; i < N; i++ ) fill ( T[i], T[i] + N, INT_MAX );
    for ( int i = 0; i < N; i++ ) T[0][i] = 0;

    for ( int v = 1; v < N; v++ ){
	for ( int u = 0; u < v; u++ ){
	    if ( G[u][v] == INT_MAX) continue;
	    for ( int s = 1; s <= v; s++ ){
		if (  T[u][s-1] == INT_MAX) continue;
		T[v][s] = min( T[v][s], T[u][s-1] + G[u][v] );
	    }
	}
    }

    int Q, stop; cin >> Q;
    
    for ( int i = 0; i < Q; i++ ){
	cin >> stop; stop++;
	stop = min (stop, N-1);
	int minv = INT_MAX;
	for ( int s = 1; s <= stop; s++ ) minv = min( minv, T[N-1][s] );
	if ( minv == INT_MAX ) cout << "No satisfactory flights" << endl;
	else cout << "Total cost of flight(s) is $" << minv << endl;
    }
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	if ( i ) cout << endl;
	cout << "Scenario #" << i+1 << endl;
	input();
	compute();
    }
}
