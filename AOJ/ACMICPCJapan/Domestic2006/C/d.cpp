#include<iostream>
#include<map>
#include<set>
#include<cassert>
#define MAX_SIZE 10
#define MAX_ROCK 105
#define LIMIT 20

using namespace std;

class Point{
    public:
    int x, y;
    Point(){}
    Point( int x, int y ): x(x), y(y){}
    
    int getDist( const Point &p ){
	return max(x, p.x)-min(x, p.x) + max(y, p.y)-min(y, p.y);
    }

    bool isAdj( const Point &p ){
	int dx = max( x, p.x ) - min( x, p.x );
	int dy = max( y, p.y ) - min( y, p.y );
	if ( dx == 1 && dy == 0 || dx == 0 && dy == 1 ) return true;
	if ( dx == 1 && dy == 1 && ( x - p.x ) != (y - p.y ) ) return true;
	return false;
    }

    bool operator == ( const Point &p ) const{
	return (x == p.x && y == p.y);
    }

    bool operator < ( const Point &p ) const {
	if ( x == p.x ) return y < p.y;
	else return x < p.x;
    }
};

class Snake{
    public:
    int size, cost;
    Point bodies[MAX_SIZE];

    Snake(){}
    Snake( int size ): size( size ){}

    bool operator < ( const Snake &s ) const{
	for ( int i = 0; i < size; i++ ){
	    if ( bodies[i] == s.bodies[i] ) continue;
	    return (bodies[i] < s.bodies[i]);
	}
	return false;
    }
};

int nBody, nRock;
Snake initial;
Point rocks[MAX_ROCK], goal;

bool onRock( Point target ){
    for ( int i = 0; i < nRock; i++ ) if ( rocks[i] == target ) return true;
    return false;
}

void tryMove( int pos, Snake current, set<Snake> &nexts, bool moved, int direction ){
    
    nexts.insert( current );

    if ( direction == 1 && pos == nBody ||
	 direction == -1 && pos == -1 ) return;

    Snake next;

    // do not move
    tryMove ( pos + direction, current, nexts, false, direction );

    if ( moved ) return;
    // move
    static const int dx[6] = {1, 0, -1, -1, 0, 1};
    static const int dy[6] = {-1, -1, 0, 1, 1, 0};
    for ( int r = 0; r < 6; r++ ){
	Point target = current.bodies[pos];
	target.x += dx[r];
	target.y += dy[r];
	
	if ( onRock( target ) ) continue;

	int adjList[2], lsize;
	lsize = 0;
	for ( int j = 0; j < current.size; j++ ){
	    if ( j != pos && target.isAdj( current.bodies[j] )) adjList[lsize++] = j;
	}

	int valid = false;
	if ( pos == 0 ){
	    if ( lsize == 1 && adjList[0] == 1 ) valid = true;
	} else if ( pos == nBody - 1 ){
	    if ( lsize == 1 && adjList[0] == nBody-2 ) valid = true;
	} else {
	    if ( lsize ==2 &&
		 ( adjList[0] == pos - 1 && adjList[1] == pos + 1 ||
		   adjList[0] == pos + 1 && adjList[1] == pos - 1 ) ) valid = true;
	}

	if ( valid ){
	    next = current;
	    next.bodies[pos] = target;
	    tryMove( pos + direction, next, nexts, true, direction );
	}
    }
}

int limit;

bool recursive( Snake current, int depth){

    if ( current.bodies[0] == goal ) return true;
    if ( depth + current.bodies[0].getDist(goal) > limit ) return false;

    set<Snake> nexts;
    tryMove( 0, current, nexts, false, 1 );
    tryMove( current.size - 1, current, nexts, false, -1 );
    for ( set<Snake>::iterator it = nexts.begin(); it != nexts.end(); it++ ){
	if ( recursive( *it, depth+1 ) ) return true;
    }
    return false;
}

void compute(){
    for ( limit = 0; limit <= 20; limit++ ){
	if ( recursive( initial, 0 ) ) break;
    }
    cout << limit << endl;
}

bool input(){
    cin >> nBody;
    if ( nBody == 0 ) return false;

    initial = Snake( nBody );

    for ( int i = 0; i < nBody; i++ ){
	cin >> initial.bodies[i].x >> initial.bodies[i].y;
    }

    cin >> nRock;
    for ( int i = 0; i < nRock; i++ ){
	cin >> rocks[i].x >> rocks[i].y;
    }

    cin >> goal.x >> goal.y;

    return true;
}

main(){
    while ( input() ) compute();
}
