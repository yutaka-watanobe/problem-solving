/* Graph Coloring - minimum number of color */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>
#include<string>
#define MAX 26

class Node{
 public:
  int index;
  int degree;
  Node(){}
  Node( int index, int degree ): index(index), degree(degree){}

  bool operator < ( const Node &n ) const{
    return n.degree < degree;
  }
};

int n;
vector<vector<int> > M;

vector<Node> D; /* degree */

void init(){
  M.clear();
  M.resize( n );
  for ( int i = 0; i < n; i++ ) M[i].resize( n, 0 );
  D.clear();
  D.resize( n );
}

bool read(){
  cin >> n;
  if ( n == 0 ) return false;
  init();
  string line;
  int target;

  for ( int i = 0; i < n; i++ ){
    cin >> line;
    for ( int j = 2; j < line.size(); j++ ){
      target = line[j] - 65;
      M[ i ][ target ] = 1;
      M[ target ][ i ] = 1;
    }
    D[i] = Node( i, line.size() - 2 );
  }

  return true;
}

/**
 * return minimum number of color
 * Solved 2243,
 */
int welch_powell( vector<vector<int> > &M, vector<Node> &D ){

  int size = M.size();
  vector<int> C; /* color */
  C.resize( size, 0 );
  sort( D.begin(), D.end() );

  int color = 0;
  int cnt = 0;

  while ( cnt < size ){
    color++;
    for ( int i = 0; i < size; i++ ){
      int index = D[i].index;
      if ( C[ index ] > 0 ) continue;

      bool able = true;
      for ( int j = 0; j < n; j++ ){
	if ( M[index][j] && C[j] == color ){
	  able = false;
	  goto next;
	}
      }

      next:;
      if ( able ){
	C[index] = color;
	cnt++;
      }
    }
  }

  return color;
}

void work(){
  int number = welch_powell( M, D );

  cout << number << " ";
  if ( number == 1 ) cout << "channel";
  else cout << "channels";
  cout << " needed." << endl;
}

main(){
  while ( read() ){
    work();
  }
}
