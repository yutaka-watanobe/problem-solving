// @JUDGE_ID:  17051CA  10021  C++
// @begin_of_source_code
/* Graph - BFS */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#include<queue>
#define MAX 11

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

class Cube{
 public:
  int pos, cost;
  int front, back, left, right, top, bottom;
  Cube(){}
  Cube(int pos): pos(pos){
    front = 0;
    back = 1;
    left = 2;
    right = 3;
    top = 4;
    bottom = 5;
    cost = 0;
  }

  void move( int d ){
    switch( d ){
    case 0:
      moveEast(); break;
    case 1:
      moveNorth(); break;
    case 2:
      moveWest(); break;
    case 3:
      moveSouth(); break;
    }
  }

  void moveNorth(){
    int tmp;
    tmp = top;
    top = front;
    front = bottom;
    bottom = back;
    back = tmp;
  }

  void moveSouth(){
    int tmp;
    tmp = top;
    top = back;
    back = bottom;
    bottom = front;
    front = tmp;
  }

  void moveEast(){
    int tmp;
    tmp = top;
    top = left;
    left = bottom;
    bottom = right;
    right = tmp;
  }

  void moveWest(){
    int tmp;
    tmp = top;
    top = right;
    right = bottom;
    bottom = left;
    left = tmp;
  }
};

void split(vector<string> &d, const string &s, char c=' '){
  string t = "";
  d.clear();

  for(int i=0; i<s.size(); i++){    
    if(s[i]==c){
      if(t!=""){ d.push_back(t); t = ""; }
    }
    else t += s[i];
  }
  if(t.size()) d.push_back(t);
}

string line;
int G[MAX][MAX];
int W[MAX*MAX][MAX*MAX];
int X, Y, A, B, C, D;

void init(){
  for ( int i = 0; i < Y; i++ ){
    fill ( G[i], G[i] + X, 0 );
  }
  for ( int i = 0; i < X*Y; i++ ){
    fill ( W[i], W[i] + X*Y, 0 );
  }
}

int read(){
  vector<string> com;
  getline ( cin, line );
  split( com, line );
  X = atoi( com[0].c_str() );
  Y = atoi( com[1].c_str() );
  getline ( cin, line );
  split( com, line );
  B = atoi( com[0].c_str() );
  A = atoi( com[1].c_str() );
  getline ( cin, line );
  split( com, line );
  D = atoi( com[0].c_str() );
  C = atoi( com[1].c_str() );

  A--; B--; C--; D--;

  init();

  getline ( cin, line ); /* for v */

  int pos1, pos2, i, j;

  while ( 1 ){
    getline ( cin, line );
    if ( line == "h" ) break;
    split( com, line );
    j = atoi(com[0].c_str())-1; i = atoi(com[1].c_str())-1;
    pos1 = i*X + j;
    pos2 = i*X + j+1;
    W[pos1][pos2] = W[pos2][pos1] = 1;
  }
  while ( 1 ){
    getline ( cin, line );
    if ( line == "" || cin.eof() ) break;
    split( com, line );
    j = atoi(com[0].c_str())-1; i = atoi(com[1].c_str())-1;
    pos1 = i*X + j;
    pos2 = (i+1)*X + j;
    W[pos1][pos2] = W[pos2][pos1] = 1;
  }
}

int bfs(){
  int start = A*X + B;
  int end = C*X + D;
  int U[MAX*MAX][6][6]; /* pos, front, top */

  for ( int i = 0; i < X*Y; i++ ){
    for ( int j = 0; j < 6; j++ ){
      for ( int k = 0; k < 6; k++ ){
	U[i][j][k] = 0;
      }
    }
  }

  queue<Cube> q;
  Cube u, v;
  int ni, nj, npos;

  u = Cube( start );

  q.push( u );

  while ( !q.empty() ){
    u = q.front(); q.pop();

    U[u.pos][u.front][u.top] = 1;

    if ( u.pos == end && u.top == 4) return u.cost;

    for ( int d = 0; d < 4; d++ ){
      ni = u.pos/X + dx[d];
      nj = u.pos%X + dy[d];
      npos = ni*X+nj;
      if ( 0 <= ni && 0 <= nj && ni < Y && nj < X && !W[u.pos][npos] ){
	v = u;
	v.move( d );
	v.pos = npos;
	if ( !U[v.pos][v.front][v.top] ){
	  v.cost = u.cost + 1;
	  q.push( v );
	}
      }
    }
  }

  return -1;
}

void work(){
  int cost;
  cost = bfs();
  if ( cost == -1 ) cout << "No solution" << endl;
  else cout << cost << endl;
}

main(){
  int t;
  getline( cin, line );
  t = atoi( line.c_str() );
  getline( cin, line );
  for ( int i = 0; i < t; i++ ){
    if ( i ) cout << endl;
    read();
    work();
  }
}
// @end_of_source_code
