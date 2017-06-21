// @JUDGE_ID:  17051CA  851  C++
// @begin_of_source_code
/* Iterative Deepening */
/* 1.41 sec */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#define MAX 8
#define SPACE 0
#define GOAL 1
#define BLOCK 2
#define INF (-100000)

using namespace std;

class State{
 public:
  char content[MAX-2][MAX-2];
  State(){}
  State( int n ){
    for ( int i = 0; i < n-2; i++ ){
      for ( int j = 0; j < n-2; j++ ) content[i][j] = 0;
    }
  }
};

class Maze{
 public:
  int n, nstate;
  int maze[ MAX ][ MAX ];
  int distanceTable[ MAX ][ MAX ];
  State currentState, initialState, emptyState;
  int deepening;
  vector<int> path;

  bool recursive( int cost, int from, int mdistance ){

    if ( mdistance == 0 ){
      path.push_back( from );
      return true;
    }

    if ( cost + mdistance > deepening ) return false;
    
    State tmpState = currentState;
    int nextMDistance; 
    
    for ( int direction = 0; direction < 4; direction++ ){
      currentState = tmpState;
      move( currentState, nextMDistance, direction );
      if ( recursive( cost + 1, direction, nextMDistance ) ){
	path.push_back( from );
	return true;
      }
    }

    return false;
  }

  void move( State &state, int &mdistance, int direction ){

    static int dx[4] = {0, -1, 0, 1};
    static int dy[4] = {1, 0, -1, 0};

    State next = emptyState;
    int max_distance = 0;
    int nx, ny;

    for ( int i = 0; i < nstate; i++ ){
      for ( int j = 0; j < nstate; j++ ){
	if ( state.content[i][j] == 0 ) continue;
	nx = i + dx[direction] + 1;
	ny = j + dy[direction] + 1;
	if ( maze[nx][ny] == SPACE ){
	  next.content[nx-1][ny-1] = 1;
	  if ( max_distance < distanceTable[nx][ny] ) max_distance = distanceTable[nx][ny];
	} else if ( maze[nx][ny] == BLOCK ){
	  next.content[i][j] = 1;
	  if ( max_distance < distanceTable[i+1][j+1] ) max_distance = distanceTable[i+1][j+1];
	}
      }
    }
    mdistance = max_distance;
    state = next;
  }

  int getMDistance(){
    int max_distance = 0;
    for ( int i = 0; i < nstate; i++ ){
      for ( int j = 0; j < nstate; j++ ){
	if ( currentState.content[i][j] == 0 ) continue;
	if ( max_distance < distanceTable[i+1][j+1] ) max_distance = distanceTable[i+1][j+1];
      }
    }
    return max_distance;
  }

  void work(){
    createDistanceTable();
    createInitialState();
    currentState = initialState;
    deepening = getMDistance();
    path.clear();

    while ( 1 ){
      currentState = initialState;
      if ( recursive( 0, -1, getMDistance() ) ) break;
      deepening++;
    }

    printPath();
  }

  void printPath(){
    for ( int i = path.size() - 2; i >=0; i-- ){
      if ( path[i] == 0 ) printf("east\n");
      else if ( path[i] == 1 ) printf("north\n");
      else if ( path[i] == 2 ) printf("west\n");
      else if ( path[i] == 3 ) printf("south\n");
    }
  }
  
  void createInitialState(){
    initialState = State();
    for ( int i = 1; i < n-1; i++ ){
      for ( int j = 1; j < n-1; j++ ){
	if ( maze[i][j] == SPACE ) initialState.content[i-1][j-1] = 1;
	else initialState.content[i-1][j-1] = 0;
      }
    }
    emptyState = State( n );
  }

  void createDistanceTable(){
    for ( int i = 0; i < n; i++ ){
      for ( int j = 0; j < n ; j++ ){
	if ( i == 0 || j == 0 || i == n - 1 || j == n - 1 ) distanceTable[i][j] = INF;
	else distanceTable[i][j] = INT_MAX;
      }
    }
    queue<pair<int, int> > q;
    for ( int j = 1; j < n-1; j++ ) if ( maze[0][j] == GOAL ) pushStart(q, 1, j );
    for ( int j = 1; j < n-1; j++ ) if ( maze[n-1][j] == GOAL ) pushStart(q, n-2, j );
    for ( int i = 1; i < n-1; i++ ) if ( maze[i][0] == GOAL ) pushStart(q, i, 1 );
    for ( int i = 1; i < n-1; i++ ) if ( maze[i][n-1] == GOAL ) pushStart(q, i, n-2 );
    bfs( q );
  }

  void pushStart( queue<pair<int, int> > &q , int i, int j){
    if ( maze[i][j] != SPACE ) return;
    q.push( make_pair( i, j ) );
    distanceTable[i][j] = 1;
  }

  void bfs( queue<pair<int, int> > q ){

    static int dx[4] = {0, -1, 0, 1};
    static int dy[4] = {1, 0, -1, 0};
    
    pair<int, int> u, v;

    while ( !q.empty() ){
      u = q.front(); q.pop();
      int ni, nj;
      for ( int r = 0; r < 4; r++ ){
	ni = u.first + dx[r];
	nj = u.second + dy[r];
	if ( maze[ni][nj] == SPACE && distanceTable[ni][nj] == INT_MAX ){
	  distanceTable[ni][nj] = distanceTable[u.first][u.second] + 1;
	  q.push( make_pair( ni, nj ) );
	}
      }
    }
  }

  void read(){
    char ch;
    cin >> n;
    nstate = n - 2;
    for ( int i = 0; i < n; i++ ){
      for ( int j = 0; j < n; j++ ){
	cin >> ch;
	if ( ch == 'O' ) maze[i][j] = BLOCK;
	else {
	  if ( i == 0 || j == 0 || i == n-1 || j == n-1 ) maze[i][j] = GOAL;
	  else maze[i][j] = SPACE;
	}
      }
    }
  }

};

main(){
  Maze M;
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    if ( i ) printf("\n");
    M.read();
    M.work();
  }
}
