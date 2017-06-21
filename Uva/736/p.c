// @JUDGE_ID:  17051CA  736  C++
// @begin_of_source_code
/* Grid String Search */
#include<stdio.h>
#include<iostream>
#include<stl.h>
#include<string>
#define MAX 51

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1};
string direction[8] = {"N", "NE", "E", "SE", "S", "SW", "W", "NW" };

class LostInSpace{
 public:
  int N;
  char T[ MAX ][ MAX ];

  bool match( int row, int col, int r, string &str ){
    if ( T[row][col] != str[0] ) return false;
    
    for ( int i = 1; i < str.size(); i++ ){
      row += dx[r];
      col += dy[r];
      if ( !( 0 <= row && 0 <= col && row < N && col < N ) ) return false;

      if ( T[row][col] == ' ' ){
	i--;
	continue;
      }

      if ( str[i] != T[row][col] ) return false;

    }

    return true;

  }

  void search( string str ){
    printf("\n%s\n", str.c_str() );
    bool found = false;
    for ( int i = 0; i < N; i++ ){
      for ( int j = 0; j < N; j++ ){

	for ( int r = 0; r < 8; r++ ){
	  if ( match( i, j, r, str ) ){
	    printf("(%d,%d) - %s\n", i+1, j+1, direction[r].c_str() );
	    found = true;
	  }
	}

      }
    }

    if ( !found ) printf("not found\n");
  }

  void work(){
    string line;

    while ( 1 ){
      getline( cin, line );
      if ( line.size() == 0 || cin.eof() ) break;
      search( line );
    }
  }

  void read(){
    string line;
    cin >> N;
    getline ( cin, line );

    for ( int i = 0; i < N; i++ ){
      getline( cin, line );
      assert( line.size() == N );
      for ( int j = 0; j < N; j++ ){
	T[i][j] = line[j];
      }
    }
  }
};

main(){
  LostInSpace LIS;
  int tcase;
  string line;
  cin >> tcase;
  getline( cin, line );
  getline( cin, line );

  for ( int i = 0; i < tcase; i++ ){
    if ( i ) cout << endl;
    LIS.read();
    LIS.work();
  }
}

// @end_of_source_code


