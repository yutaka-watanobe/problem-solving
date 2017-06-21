// @JUDGE_ID:  17051CA  2285  C++
// @begin_of_source_code
/* Grid - Simulation */
#include<stdio.h>
#include<iostream>
#include<stl.h>
#include<vector>
#include<string>
#include<queue>
#define MAX 105
#define OR 0
#define AND 1
#define ZERO 0
#define ONE 1
#define EMPTY -1

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

char S[MAX][MAX]; /* circuit map */
bool U[MAX][MAX];
int L[MAX][MAX]; /* logic table */
int maxI, maxJ;
int outX, outY;

class Input{
 public:
  char name;
  int x, y;
  Input(){}
  Input( char name, int x, int y ): name(name), x(x), y(y){}
};

class Gate{
 public:
  int x, y;
  int type;
  int value;
  Gate(){}
  Gate( int type, int x, int y): type(type), x(x), y(y){}

  bool hasValue(){
    if ( L[x-1][y-2] != EMPTY && L[x+1][y-2] != EMPTY ){
      if ( type == AND ) value = ( L[x-1][y-2] & L[x+1][y-2] );
      else if ( type == OR ) value = ( L[x-1][y-2] | L[x+1][y-2] );
      return true;
    }else{
      return false;
    }
  }

};

queue<Input> inI;
queue<Gate> inG;
queue<Input> I;
queue<Gate> G;

void init(){
  for ( int i = 0; i < MAX; i++ ){
    fill ( S[i], S[i] + MAX, ' ' );
  }
  inI = queue<Input>();
  inG = queue<Gate>();
}

void initCircuit(){
  for ( int i = 0; i <= maxI; i++ ){
    for ( int j = 0; j <= maxJ; j++ ){
      U[i][j] = false;
      L[i][j] = EMPTY;
    }
  }
  I = inI;
  G = inG;
}

int read(){
  string line;
  char ch;
  init();
  maxI = 0;
  maxJ = 0;
  for ( int i = 0; ; i++ ){
    getline( cin, line );
    if ( cin.eof() ) return 0;
    if ( line[0] == '*' ) break;
    maxI = max( maxI, i );
    for ( int j = 0; j < line.size(); j++ ){
      maxJ = max( maxJ, j );
      ch = line[j];
      S[i][j] = ch;
      if ( 'A' <= ch  && ch <= 'Z' ){
	inI.push( Input( ch, i, j) );
      } else if ( ch == '>' ){
	inG.push( Gate( OR, i, j ) );
      } else if ( ch == ')' ){
	inG.push( Gate( AND, i, j ) );
      } else if ( ch == '?' ){
	outX = i;
	outY = j;
      }
    }
  }

  return 1;
}

void flip( int &v ){
  v = ( v == 1 ) ? 0 : 1;
}

bool check( int x, int y ){
  char ch = S[x][y];
  return ( 0 <= x && 0 <= y && x < MAX && y < MAX && ch != ' ' );
}

void flow( int x, int y, int value ){
  U[x][y] = true;
  if ( S[x][y] == 'o' ) flip( value );
  if ( S[x][y] == ':' || S[x][y] == '?' ) {
    L[x][y] = value;
    return;
  }

  int nx, ny;
  for ( int r = 0; r < 4; r++ ){
    nx = x + dx[r];
    ny = y + dy[r];
    if ( check( nx, ny ) ){
      if ( !U[nx][ny] ){
	flow( nx, ny, value );
      }
    }
  }
  
}

void simulate( string code ){

  initCircuit();

  Input in;
  while ( !I.empty() ){
    in = I.front(), I.pop();
    flow( in.x, in.y, code[in.name - 'A'] - '0');
  }

  Gate gate;
  while ( !G.empty() ){
    gate = G.front(), G.pop();
    
    if ( !gate.hasValue() ){
      G.push( gate );
      continue;
    }

    flow( gate.x, gate.y, gate.value );
  }

   cout << L[outX][outY] << endl;
}

void work(){
  string code;
  while ( 1 ){
    getline( cin, code );
    if ( code[0] == '*' ) break;
    simulate( code );
  }
}

main(){
  for ( int i = 0; read(); i++ ){
    work();
    cout << endl;
  }
}
// @end_of_source_code
