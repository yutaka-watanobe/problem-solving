// Cycle ditection + Topological sort
#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#define ISIZE 50
#define SIZE 26
#define SPACE '.'
#define ASTA '*'

using namespace std;

class BoundingBox{
    public:
    int minx, miny, maxx, maxy;
    BoundingBox(): minx(INT_MAX), miny(INT_MAX), maxx(INT_MIN), maxy(INT_MIN){}
    BoundingBox( int minx, int miny, int maxx, int maxy): minx(minx), miny(miny),
							  maxx(maxx), maxy(maxy){}
};

char G[ISIZE+1][ISIZE+1]; // grid
int M[SIZE][SIZE]; // graph for topological sort
BoundingBox boxes[SIZE]; // 0 - 25 = A - Z
int H, W;
bool visited[SIZE];
vector<int> order;

void initBoundingBoxes(){
    for ( int i = 0; i < SIZE; i++ ) boxes[i] = BoundingBox();
    for ( int i = 0; i < H; i++ ){
	for ( int j = 0; j < W; j++ ){
	    if ( G[i][j] == SPACE ) continue;
	    boxes[G[i][j] - 'A'].minx = min( boxes[G[i][j] - 'A'].minx, i );
	    boxes[G[i][j] - 'A'].miny = min( boxes[G[i][j] - 'A'].miny, j );
	    boxes[G[i][j] - 'A'].maxx = max( boxes[G[i][j] - 'A'].maxx, i );
	    boxes[G[i][j] - 'A'].maxy = max( boxes[G[i][j] - 'A'].maxy, j );
	}
    }
}

void makeGraph(){
    for ( int i = 0; i < SIZE; i++ )
	for ( int j = 0; j < SIZE; j++ ) M[i][j] = 0;

    for ( int curr = 0; curr < SIZE; curr++ )
	for ( int i = boxes[curr].minx; i <= boxes[curr].maxx ; i++ )
	    for ( int j = boxes[curr].miny; j <= boxes[curr].maxy ; j++ )
		if ( !( G[i][j] == SPACE || G[i][j] == curr + 'A' ) ) {
		    M[G[i][j] - 'A'][curr] = 1;
		}
}

bool hasCycle(){
    int T[SIZE][SIZE];
    for ( int i = 0; i < SIZE; i++ )
	for ( int j = 0; j < SIZE; j++ ) T[i][j] = M[i][j];

    for ( int k = 0; k < SIZE; k++ )
	for ( int i = 0; i < SIZE; i++ )
	    for ( int j = 0; j < SIZE; j++ ) 
		T[i][j] = T[i][j] | T[i][k] & T[k][j];

    for ( int i = 0; i < SIZE; i++ )
	if ( T[i][i] ) return true;

    return false;
}

void dfs( int u ){
    visited[u] = true;
    for ( int v = 0; v < SIZE; v++ )
	if ( M[u][v] && !visited[v] ) dfs( v );
    order.push_back( u );
}

void topologicalSort(){
    order.clear();
    for ( int i = 0; i < SIZE; i++ ) visited[i] = false;
    for ( int i = 0; i < SIZE; i++ )
	if ( !visited[i] && boxes[i].minx != INT_MAX )
	    dfs( i ); 
}

bool isValid( int curr ){
    for ( int i = boxes[curr].minx; i <= boxes[curr].maxx ; i++ )
	for ( int j = boxes[curr].miny; j <= boxes[curr].maxy ; j++ ){
	    if ( !( G[i][j] == ASTA || G[i][j] == curr + 'A' ) ) return false;
	    else G[i][j] = ASTA;
	}
    return true;
}

void compute(){
    initBoundingBoxes();
    makeGraph();

    if ( hasCycle() ){
	cout << "SUSPICIOUS" << endl; return;
    }

    topologicalSort();    

    for ( int i = order.size() - 1; i >= 0; i-- ){
	if ( !isValid( order[i] ) ){
	    cout << "SUSPICIOUS" << endl; return;
	}
    }
    
    cout << "SAFE" << endl;
}

void input(){
    cin >> H >> W;
    for ( int i = 0; i < H; i++ )
	for ( int j = 0; j < W; j++ ) cin >> G[i][j];
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	input(); 
	compute();
    }
}
