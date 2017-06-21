// @author yutaka C++
// BFS
#include<iostream>
#include<map>
#include<set>
#include<queue>
#include<cassert>
#define MAX_SIZE 10
#define MAX_ROCK 105
#define LIMIT 20

using namespace std;

class Point{
    public:
    int x, y;
    int target[6];

    Point(){}
    Point( int x, int y ): x(x), y(y){
	for ( int i = 0;  i < 6; i++ ) target[i] = -1;
    }
    
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

void tryMove( int pos, Snake current, set<Snake> &nexts, bool moved, int order ){
    nexts.insert( current );
    if ( order == 1 && pos == nBody || order == -1 && pos == -1 ) return;

    Snake next;

    // do not move
    tryMove ( pos + order, current, nexts, false, order );

    // move
    if ( moved ) return;

    if ( pos == 0 || pos == current.size() -1 ){
	if ( current.target[0] >= 0
	
    } else {



    }


}

int bfs(){
    queue<Snake> Q;
    map<Snake, int> D;
    
    Q.push( initial );
    D[initial] = 0;
    
    while ( !Q.empty() ){
	Snake current = Q.front(); Q.pop();
	int cost = D[current];

	if ( current.bodies[0] == goal ) return cost;

	set<Snake> nexts;
	tryMove( 0, current, nexts, false, 1 );
	tryMove( current.size - 1, current, nexts, false, -1 );

	for ( set<Snake>::iterator it = nexts.begin(); it != nexts.end(); it++ ){
	    int adder = current.bodies[0].getDist(goal);
	    if ( adder > 1 ) adder = (int)(adder*1.5) + cost;
	    else adder += cost;
	    if ( D.count(*it) == 0 && adder  <= LIMIT  ){
		D[*it] = cost + 1;
		Q.push(*it);
	    }
	}
    }
    assert( false );
}

void compute(){
    cout << bfs() << endl;
}

bool input(){
    cin >> nBody;
    if ( nBody == 0 ) return false;

    initial = Snake( nBody );

    for ( int i = 0; i < nBody; i++ ){
	cin >> initial.bodies[i].x >> initial.bodies[i].y;
    }


    static const int dx[6] = {1, 0, -1, -1, 0, 1};
    static const int dy[6] = {-1, -1, 0, 1, 1, 0};
    for ( int i = 0; i < nBody; i++ ){
	for ( int j = 0; j < nBody; j++ ){
	    if ( i == j ) continue;
	    for ( int r = 0; r < 6; r++ ){
		if ( initial.bodies[i].x + dx[r] == initial.bodies[j].x &&
		     initial.bodies[i].y + dy[r] == initial.bodies[j].y ){

		    initial.bodies[i].target[r] = j;
		    initial.bodies[i].target[(r+3)%6] = i;
		}
	    }
	}
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
