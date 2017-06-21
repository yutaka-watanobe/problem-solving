#include<iostream>
#include<math.h>
#include<algorithm>
#include<float.h>
using namespace std;
#define MAX 1000

struct Point{ int x, y; };

int N, R;
Point C[MAX]; 
double MST[MAX][MAX];
bool visited[MAX];

double getDist( int i, int j ){
    double dx = C[i].x - C[j].x;
    double dy = C[i].y - C[j].y;
    return sqrt( dx*dx + dy*dy );
}

pair<int, int> prim(){
    double d[MAX];
    int pi[MAX];
    for ( int i = 0; i < N; i++ ){
	visited[i] = false;
	d[i] = FLT_MAX;
	pi[i] = -1;
    }

    d[0] = 0.0;

    double rcost = 0;
    double rrcost = 0;

    while(1){
	double minv = FLT_MAX;
	int u = -1;
	for ( int i = 0; i < N; i++ ){
	    if ( !visited[i] && d[i] < minv ){
		minv = d[i]; u = i;
	    }
	}

	if ( u == -1 ) break;
	visited[u] = true;

	if ( pi[u] != -1 ){
	    if ( R >= d[u] ) rcost += d[u];
	    else rrcost += d[u];
	    MST[u][pi[u]] = MST[pi[u]][u] = d[u];
	}

	for ( int v = 0; v < N; v++ ){
	    if ( visited[v] ) continue;
	    double dist = getDist( u, v );
	    if ( dist < d[v] ){
		d[v] = dist; pi[v] = u;
	    }
	}
    }

    return make_pair((int)(rcost+0.5), (int)(rrcost+0.5));
}

void dfs( int u ){
    visited[u] = true;
    for ( int v = 0; v < N; v++ ){
	if ( !visited[v] &&  MST[u][v] <= R ) dfs(v);
    }
}

void compute(){
    for ( int i = 0; i < N; i++ )
	for ( int j = 0; j < N; j++ ) MST[i][j] = FLT_MAX;

    pair<int, int> cost = prim();

    int ncomponent = 0;
    for ( int i = 0; i < N; i++ ) visited[i] = false;
    for ( int i = 0; i < N; i++ ){
	if ( !visited[i] ){
	    ncomponent++;
	    dfs(i);
	}
    }
    
    cout << ncomponent << " " << cost.first << " " << cost.second << endl;
}

void input(){
    cin >> N >> R;
    for ( int i = 0; i < N; i++ ) cin >> C[i].x >> C[i].y;
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	cout << "Case #" << i+1 << ": ";
	input();
	compute();
    }
}
