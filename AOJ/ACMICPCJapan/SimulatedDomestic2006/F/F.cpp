// floyd
#include<iostream>
#include<algorithm>
#define MAX 101
#define INFTY 10000000
using namespace std;

int M[MAX][MAX];
int n, m, s, g1, g2;

void compute(){
    for ( int k = 1; k <= n; k++ )
	for ( int i = 1; i <= n; i++ )
	    for ( int j = 1; j <= n; j++ )
		M[i][j] = min( M[i][j], M[i][k] + M[k][j] );

    int mincost = INFTY;
    for ( int k = 1; k <= n; k++ )
	mincost = min( mincost, M[s][k] + M[k][g1] + M[k][g2] );

    cout << mincost << endl;
}

bool input(){
    int source, target, cost;
    cin >> n >> m >> s >> g1 >> g2;
    if ( n == 0 ) return false;
    for ( int i = 1; i <= n; i++ )
	for ( int j = 1; j <= n; j++ )
	    M[i][j] = ( i == j ) ? 0 : INFTY;
    for ( int i = 0; i < m; i++ ){
	cin >> source >> target >> cost;
	M[source][target] = cost;
    }
    return true;
}

main(){
    while ( input() ) compute();
}
