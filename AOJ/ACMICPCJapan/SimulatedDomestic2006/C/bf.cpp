// Brute force version
// @author yutaka C++
#include<iostream>
#include<climits>
#include<set>
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
BoundingBox boxes[SIZE]; // 0 - 25 = A - Z
int H, W;
set<char> order;

void initBoundingBoxes(){
    for ( int i = 0; i < SIZE; i++ ) boxes[i] = BoundingBox();
    for ( int i = 0; i < H; i++ ){
	for ( int j = 0; j < W; j++ ){
	    if ( G[i][j] == SPACE ) continue;
	    order.insert( G[i][j] );
	    boxes[G[i][j] - 'A'].minx = min( boxes[G[i][j] - 'A'].minx, i );
	    boxes[G[i][j] - 'A'].miny = min( boxes[G[i][j] - 'A'].miny, j );
	    boxes[G[i][j] - 'A'].maxx = max( boxes[G[i][j] - 'A'].maxx, i );
	    boxes[G[i][j] - 'A'].maxy = max( boxes[G[i][j] - 'A'].maxy, j );
	}
    }
}

bool isValid( int curr ){
    for ( int i = boxes[curr].minx; i <= boxes[curr].maxx ; i++ )
	for ( int j = boxes[curr].miny; j <= boxes[curr].maxy ; j++ )
	    if ( !( G[i][j] == ASTA || G[i][j] == curr + 'A' ) ) return false;

    for ( int i = boxes[curr].minx; i <= boxes[curr].maxx ; i++ )
	for ( int j = boxes[curr].miny; j <= boxes[curr].maxy ; j++ )
	    G[i][j] = ASTA;

    return true;
}

void compute(){
    initBoundingBoxes();

    int count = 0;
    set<char>::iterator it;
    bool visited[SIZE];
    for ( int i = 0; i < SIZE; i++ ) visited[i] = false;
    while (1){
	bool updated = false;
	for ( it = order.begin(); it != order.end(); it++ ){
	    if ( visited[*it - 'A'] ) continue;
	    if ( isValid( *it - 'A' ) ) {
		visited[*it - 'A'] = true;
		updated = true;
		count++;
	    }
	}

	if ( !updated || count == order.size() ) break;
    }
    
    if ( count == order.size() ) cout << "SAFE" << endl;
    else cout << "SUSPICIOUS" << endl;
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
