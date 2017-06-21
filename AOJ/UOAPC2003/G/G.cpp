#include<stdio.h>
#include<algorithm>
#include<climits>

using namespace std;
#define REP(i, n) for ( int i = 0; i < (int)n; i++ )
#define MAX 100
#define SPACE 0
#define WHITE 1
#define BLACK 2

class Node{
    public:
    int id, deg;
    Node( int id = 0, int deg = 0): id(id), deg(deg){}

    bool operator < ( const Node &n) const{
	if ( deg == n.deg ) return id < n.id;
	else return deg > n.deg;
    }
};

int n;
bool G[MAX][MAX];
int limit;

int estimate(){
    bool dominated[MAX];
    REP(i, n) dominated[i] = false;

    int e = 0;
    while(1){
	int maxv = 0;
	int target = -1;
	for ( int i = 0; i < n; i++ ){
	    int d = 0;
	    if ( !dominated[i] ) d++;
	    for ( int j = 0; j < n; j++ ){
		if ( i == j || !G[i][j]) continue;
		if ( !dominated[j] ) d++;
	    }
	    if ( maxv < d ){
		maxv = d;
		target = i;
	    }
	}
	if ( target == -1 ) return e;
	e++;

	dominated[target] = true;
	for ( int j = 0; j < n; j++ ){
	    if ( G[target][j] ) dominated[j] = true;
	}
    }
}

int ans;
int acolor[MAX];
int color[MAX];

bool check(){
    for ( int u = 0; u < n; u++ ){
	bool ok = false;
	if ( color[u] != WHITE ) ok = true;
	else {
	    for ( int v = 0; v < n; v++ ){
		if ( G[u][v] ){
		    if ( color[v] != WHITE ){ ok = true; v = n; }
		}
	    }
	}
	if ( !ok ) return true;
    }
    return false;
}

bool allWhite(int u){
    for ( int v = 0; v < n; v++ ){
	if ( !G[u][v] ) continue;
	if ( color[v] != WHITE ) return false;
    }
    return true;
}

void recursive(int depth, int nblack){

    if ( check() ) return;

    if ( nblack > limit ) return;

    if ( depth == n ){
	if ( ans > nblack ){
	    ans = nblack;
	    REP(i, n) acolor[i] = color[i];
	}
	return;
    }

    if ( allWhite(depth) ){
	color[depth] = BLACK;
	recursive( depth+1, nblack+1);
    } else {
	// non take
	color[depth] = WHITE;
	recursive( depth+1, nblack);
	
	// take
	color[depth] = BLACK;
	recursive( depth+1, nblack+1);
    }
}

void compute(){
    limit = estimate();
    //    cout << "estimated = " << limit << endl;

    ans = INT_MAX;
    REP(i, n) color[i] = SPACE;

    recursive(0, 0);

    printf("%d\n", ans);
    return;
    for ( int i = 0; i < n; i++ ){
      if ( acolor[i] == BLACK ) printf("%d ", i);
    }
    printf("\n");

}

int main(){
    int m, s, t;
    while(1){
      scanf("%d %d", &n, &m);
	if ( n == 0 && m == 0 ) break;
	REP(i, n) REP(j, n) G[i][j] = false;
	for ( int i = 0; i < m; i++ ){
	  scanf("%d %d", &s, &t);
	    G[s][t] = G[t][s] = true;
	}
	compute();
    }

    return 0;
}
