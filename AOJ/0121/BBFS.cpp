// @author Yutaka Watanobe
// Bidirectional BFS
#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<queue>
#define SIZE 8
#define COLUMN 4
#define ROW 2

using namespace std;

class Puzzle{
    private:
    int buffer[SIZE];
    int space;
  
    public:
    void set( int index, int number ){
	if ( number == 0 ) space = index;
	buffer[index] = number;
    }

    bool isGoal(){
	for ( int i = 0; i < SIZE; i++ ) if ( buffer[i] != i ) return false;
	return true;
    }

    bool move( int direction ){
	static int dr[4] = {1, 0, -1, 0};
	static int dc[4] = {0, -1, 0, 1};
	int nr, nc;
	int r = space/COLUMN;
	int c = space%COLUMN;
	nr = r + dr[direction]; nc = c + dc[direction];
	if ( nr < 0 || nr >= ROW || nc < 0 || nc >= COLUMN ) return false;
	int tmp = buffer[nr*COLUMN + nc];
	buffer[ nr*COLUMN + nc ] = buffer[ r*COLUMN + c ];
	buffer[ r*COLUMN + c ] = tmp;
	space = nr*COLUMN + nc;
	return true;
    }

    bool operator < ( const Puzzle &p ) const{
	for ( int i = 0; i < 8; i++ ){
	    if ( buffer[i] == p.buffer[i] ) continue;
	    return buffer[i] < p.buffer[i];
	}
	return false;
    }
};

class PuzzleSolver{
    private:
    Puzzle current;
    map<Puzzle, int> goalDist;
    map<Puzzle, bool> goalVisited;
    
    public:

    void setGoalStates(){
	queue<Puzzle> q;
	Puzzle u, next;
	Puzzle goal;
	for ( int i = 0; i < 8; i++ ) goal.set(i, i);

	q.push( goal );
	goalDist[ goal ] = 0;
	goalVisited[ goal ] = true;

	while ( !q.empty() ){
	    u = q.front(); q.pop();

	    for ( int direction = 0; direction < 4; direction++ ){
		next = u;
		if ( next.move( direction ) && !goalVisited[ next ] ) {
		    goalVisited[ next ] = true;
		    goalDist[ next ] = goalDist[ u ] + 1;
		    q.push( next );
		}
	    }
	}
    }

    int bfs(){
	queue<Puzzle> q;
	map<Puzzle, int> dist;
	map<Puzzle, bool> visited;
	Puzzle u, next;

	q.push( current );
	dist[ current ] = 0;
	visited[ current ] = true;

	while ( !q.empty() ){
	    u = q.front(); q.pop();
	    if ( goalVisited[ u ] ) return dist[u] + goalDist[u];
	    for ( int direction = 0; direction < 4; direction++ ){
		next = u;
		if ( next.move( direction ) && !visited[ next ] ) {
		    visited[ next ] = true;
		    dist[ next ] = dist[ u ] + 1;
		    q.push( next );
		}
	    }
	}
	return -1;
    }

    void compute(){
	cout << bfs() << endl;
    }

    bool input(){
	string line;
	getline(cin, line);
	if ( cin.eof() ) return false;
	stringstream ss( line );
	int number;
	char ch;
	for ( int i = 0; i < SIZE; i++ ){
	  ss >> number;
	    current.set(i, number);
	}
	return true;
    }
};

main(){
    PuzzleSolver puzzleSolver;
    puzzleSolver.setGoalStates();
    while ( puzzleSolver.input() ) puzzleSolver.compute();
}
