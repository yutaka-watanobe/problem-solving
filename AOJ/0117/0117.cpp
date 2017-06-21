#include<iostream>
using namespace std;
#define MAX 100
#define INFTY (1 <<21)
int N;
int M[MAX][MAX];

int dijkstra( int s, int t ){
    bool visited[MAX]; 
    int d[MAX];
    for ( int i = 0; i < N; i++ ){
        d[i] = INFTY;
        visited[i] = false;
    }
    
    d[s] = 0; 
    
    while( 1 ){
        int u; 
        int mincost = INFTY;
        for ( int i = 0; i < N; i++ ){
            if ( !visited[i] && d[i] < mincost ){
                mincost = d[i]; u = i;
            }
        }
        
        if ( mincost == INFTY ) break;
        
        visited[u] = true; 
        
        for ( int v = 0; v < N; v++ ){
            if ( visited[v] || M[u][v] == INFTY ) continue;
            d[v] = min( d[v], d[u] + M[u][v] );
        }
    }

    return d[t];
}

main(){
    cin >> N;
    int m; cin >> m;
    int s, t, c1, c2;
    char ch;
    for ( int i = 0; i < N; i++ )
	for ( int  j = 0; j < N; j++ ) M[i][j] = INFTY;
    for ( int i = 0; i < m; i++ ){
	cin >> s >> ch >> t >> ch >> c1 >> ch >> c2;
	s--; t--;
	M[s][t] = c1;
	M[t][s] = c2;
    }

    int source, target, money, wood;
    cin >> source >> ch >> target >> ch >> money >> ch >> wood;
    source--; target--;
    int cost = dijkstra( target, source );
    cost += dijkstra(source, target );
    
    cout << money - cost - wood << endl;

}
