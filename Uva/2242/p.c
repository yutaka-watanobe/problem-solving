// @JUDGE_ID:  17051CA  2242  C++
// @begin_of_source_code
/* Grid + Permutaion */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#include<vector>
#define MAX 31

class Frame{
 public:
  int row, column; 
  int top, left, right, bottom; /* i.e. most top,.. */
  char symbol;

  vector<vector<char> > F;
  Frame(){}
  Frame( int row, int column, char s): row(row), column(column){
    symbol = s;
    F.resize( row );
    for ( int i = 0; i < row; i++ ) F[i].resize( column, '.');
    top = row - 1;
    bottom = 0;
    left = column - 1;
    right = 0;
  }

  void insertChar( int i, int j, char ch ){
    F[i][j] = ch;
    top = min( i, top );
    bottom = max( i, bottom );
    left = min( j, left );
    right = max( j, right );
  }

  void createFrame(){
    for ( int j = left; j <= right; j++ ) F[top][j] = symbol;
    for ( int j = left; j <= right; j++ ) F[bottom][j] = symbol;
    for ( int i = top; i <= bottom; i++ ) F[i][left] = symbol;
    for ( int i = top; i <= bottom; i++ ) F[i][right] = symbol;
  }
};

int row, column;
set<char> char_set;
vector<vector<char> > G;
map<char, Frame> FM; /* frame map */
map<char, int> StoI; /* map from Symbol to Index */
map<int, char> ItoS; /* map from Index to Symbol */
vector<int> D; /* degree */
vector<string> answer;

int n;

int M[ MAX ][ MAX ]; /* graph matrix */

void init(){
  FM = map<char, Frame>();
  StoI = map<char,int>();
  ItoS = map<int, char>();
  char_set.clear();
  G.clear();
  D.clear();
  answer.clear();
}

bool read(){
  init();
  string line;
  if ( !( cin >> row >> column ) ) return false;

  G.resize( row );
  for ( int i = 0; i < row; i++ ) G[i].resize( column );

  char ch;
  for ( int i = 0; i < row; i++ ){
    cin >> line;
    for ( int j = 0; j < column; j++ ){
      ch = line[j];
      G[i][j] = ch;
      if ( ch == '.' ) continue;
      if ( FM.find( ch ) == FM.end() ){
	FM[ ch ] = Frame( row, column, ch );
	FM[ ch ].insertChar(i, j, ch );
      } else {
	FM[ ch ].insertChar(i, j, ch );
      }
      char_set.insert( line[j] );
    }
  }

  n = char_set.size();
  
  set<char>::iterator pos;
  int index = 0;
  for ( pos = char_set.begin(); pos != char_set.end(); pos++ ){
    StoI[ *pos ] = index;
    ItoS[ index ] = *pos;
    index++;
  }
  return true;
}

void makeFrame(){
  map<char, Frame>::iterator pos;
  for( pos = FM.begin(); pos != FM.end(); pos++ ){
    (*pos).second.createFrame();
  }
}

void makeGraph(){
  D.resize( n, 0 );
  for ( int i = 0; i < n; i++ ) fill ( M[i], M[i] + n, 0 );
  map<char, Frame>::iterator pos;
  vector<vector<char> > F;

  for ( pos = FM.begin(); pos != FM.end(); pos++ ){
    Frame f = (*pos).second;
    F = f.F;
    for ( int i = 0; i < row; i++ ){
      for ( int j = 0; j < column; j++ ){
	if ( F[i][j] == f.symbol && G[i][j] != f.symbol ){
	  char source = f.symbol;
	  char target = G[i][j];
	  M[ StoI[source] ][ StoI[target] ] = 1;
	}
      }
    }
  }

  for ( int i = 0; i < n; i++ ){
    D[i] = 0;
    for ( int j = 0; j < n; j++ ){
      if ( M[i][j] ) D[i]++;
    }
  }
}

void makePermutation( vector<int> d, int cnt, string path ){

  if ( cnt == n ){
    reverse( path.begin(), path.end() );
    answer.push_back( path );
    return;
  }

  vector<int> next_deg;
  string next_path;

  for ( int i = 0; i < n; i++ ){
    if ( d[i] == 0 ){
      next_deg = d;
      next_path = path;
      for ( int j = 0; j < n; j++ ){
	if ( M[j][i] ) next_deg[j]--;
      }
      next_deg[i] = -1;
      next_path += ItoS[ i ];
      makePermutation( next_deg, cnt + 1, next_path);
    }
  }

}

void work(){
  makeFrame();
  makeGraph();

  makePermutation( D, 0, "");
  sort( answer.begin(), answer.end() );
  for ( int i = 0; i < answer.size(); i++ ){
    cout << answer[i] << endl;
  }
}

main(){
  while ( read() ){
    work();
  }
}

// @end_of_source_code
