#include<iostream>
#include<math.h>
using namespace std;
#define MAX 100
#define INFTY (1 << 21)

struct Building{ int x, y; };

int n;
Building B[MAX+1];
double D[MAX+1];
int P[MAX+1];

double getDistance( Building b1, Building b2 ){
    return sqrt(1.0*(b1.x-b2.x)*(b1.x-b2.x) + (b1.y - b2.y)*(b1.y - b2.y));
}

void dijkstra( int s ){
    bool visited[MAX+1];
    for ( int i = 1; i <= n; i++ ){
	D[i] = INFTY;
	P[i] = -1;
	visited[i] = false;
    }

    D[s] = 0.0;

    while(1){
	double minv = INFTY;
	int u = 0;
	for ( int i = 1; i <= n; i++ ){
	    if ( visited[i] ) continue;
	    if ( minv > D[i] ){
		minv = D[i];
		u = i;
	    }
	}
	if ( minv == INFTY ) break;
	visited[u] = true;

	for ( int v = 1; v <= n; v++ ){
	    if ( visited[v] ) continue;
	    double d = getDistance( B[u], B[v] );
	    if ( d <= 50.0 && D[u] + d < D[v] ){
		D[v] = D[u] + d;
		P[v] = u;
	    }
	}
    }
}

void print( int i, bool f){
    if ( i == -1 ) return;
    print(P[i], true);
    cout << i;
    if ( f ) cout << " ";
}

void printPath( int s, int g ){
    if ( D[g] == INFTY ) {
	cout << "NA" << endl;
	return;
    }
    print(g, false);
    cout << endl; 
}

main(){
    while( cin >> n, n ){
	int x;
	for ( int i = 1; i <= n; i++ ){
	    cin >> x >> B[x].x >> B[x].y;
	}
	int query; cin >> query;
	int s, g;
	for ( int i = 0; i < query; i++ ){
	    cin >> s >> g;
	    dijkstra(s);
	    printPath(s, g);
	}
    }
}
