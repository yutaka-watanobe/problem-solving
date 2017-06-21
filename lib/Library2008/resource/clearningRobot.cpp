// begin_of_source
#include<iostream>
#include<queue>
#include<algorithm>
#define MAX 20
#define DMAX 10
using namespace std;

class Point{
    public:
    int y, x;
    Point(){}
    Point( int y, int x ): y(y), x(x){}

    bool operator == ( const Point &p ) const{
	return ( x == p.x && y == p.y );
    }
};

int W, H;
char G[MAX][MAX];
Point start;
Point dirty[DMAX];
int dsize;
int T[DMAX]; // start to all dirty;
int M[DMAX][DMAX]; // all dirty to all dirty

int bfs( Point p1, Point p2 ){
    bool visited[MAX][MAX];
    int d[MAX][MAX];
    queue<Point> q;

    for ( int i = 0; i < H; i++ ){
	for ( int j = 0; j < W; j++ ){
	    visited[i][j] = false;
	    d[i][j] = INT_MAX;
	}
    }

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    q.push( p1 );
    d[p1.y][p1.x] = 0;

    Point u;

    while ( !q.empty() ){
	u = q.front(); q.pop();

	if ( u == p2 ) return d[u.y][u.x];

	int nx, ny;
	for ( int r = 0; r < 4; r++ ){
	    ny = u.y + dy[r];
	    nx = u.x + dx[r];
	    
	    if ( !( 0 <= nx && 0 <= ny && ny < H && nx < W ) ) continue;

	    if ( !visited[ny][nx] && G[ny][nx] != 'x' ){
		visited[ny][nx] = true;
		d[ny][nx] = d[u.y][u.x] + 1;
		q.push( Point( ny, nx ) );
	    }
	}
    }

    return INT_MAX;
}

void computeDistanceTable(){
    for ( int i = 0; i < dsize; i++ ){
	T[i] = bfs( start, dirty[i]);
    }
    for ( int i = 0; i < dsize-1; i++ ){
	for ( int j = i; j < dsize; j++ ){
	    if ( i == j ) M[i][j] = M[j][i] = 0;
	    M[i][j] = M[j][i] = bfs( dirty[i], dirty[j] );
	}
    }
}

int getMinimumMove(){
    int order[DMAX];
    for ( int i = 0; i < dsize; i++ ){
	order[i] = i;
    }

    int minMove = INT_MAX;

    do{
	int move = T[ order[0] ];
	
	for ( int i = 1; i < dsize; i++ ){
	    move += M[ order[i-1] ][ order[i] ];
	}

	if ( minMove > move ) minMove = move;

    } while( next_permutation(order, order + dsize )) ;

    return minMove;
}

bool notReachable(){
    for ( int i = 0; i < dsize; i++ ){
	if ( T[i] == INT_MAX ) return true;
    }
    return false;
}

void compute(){
    computeDistanceTable();
    if ( notReachable() ) cout << "-1" << endl;
    else {
	cout << getMinimumMove() << endl;
    }
}

bool read(){
    cin >> W >> H;
    if ( W == 0 && H == 0 ) return false;
    dsize = 0;
    char ch;
    for ( int i = 0; i < H; i++ ){
	for ( int j = 0; j < W; j++ ){
	    cin >> ch;
	    G[i][j] = ch;
	    if ( ch == 'o' ){
		start = Point(i, j);
	    } else if ( ch == '*' ){
		dirty[dsize++] = Point(i, j);
	    }
	}
    }
    return true;
}

main(){
    while ( read() ) compute();
}
// end_of_source
