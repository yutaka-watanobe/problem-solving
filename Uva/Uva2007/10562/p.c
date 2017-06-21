// @JUDGE_ID:  17051CA  10562  C++
// @begin_of_source_code
#include<stdio.h>
#include<string>
#include<stl.h>
#include<iostream>
#define MAX 205

class Tree{
 public:
  int row, column;
  char M[MAX][MAX];

  bool isNode( char ch ){
    if ( ch == ' ' || ch == '|' || ch == '-' || ch == '#' ) return false;
    return true;
  }

  void rec( int x, int y ){

    printf("%c(", M[x][y] );

    if ( x+1 < row && M[x+1][y] == '|' ){ // has children
      int posj = y;
      while ( 0 <= posj && M[x+2][posj] == '-' ) posj--;
      if ( M[x+2][posj] != '-' ) posj++;
      //assert( M[x+2][posj] == '-' );
      while ( M[x+2][posj] == '-' ){
	if ( isNode( M[x+3][posj] ) ){
	  rec( x+3, posj );
	}
	posj++;
      }
    }

    printf(")");

  }


  void work(){
    printf("(");

    for ( int i = 0; i < row; i++ ){
      for (int j = 0; j < column; j++ ){
	if ( isNode( M[i][j] ) ){
	  rec( i, j );
	  goto next;
	}
      }
    }

  next:;
    printf(")\n");
  }

  void read(){
     for ( int i = 0; i < MAX; i++ ){
       for ( int j = 0; j < MAX; j++ ){
	 M[i][j] = ' ';
       }
     }
     
    string line;
    int i = 0;
    row = column = 0;
    while ( 1 ){
      line = "";
      getline( cin, line );
      column = max( column, (int)line.size() );
      if ( line.size() && line[0] == '#' ){
	row = i;
	return;
      }
      if ( line.size() == 0 ) line += ' ';
      for ( int j = 0; j <line.size(); j++ ){
	M[i][j] = line[j];
      }
      i++;
    }
    
   
  }
};

main(){
  Tree T;
  string str;
  int tcase;
  getline( cin, str );
  tcase = atoi ( str.c_str() );
  for ( int i = 0; i < tcase; i++ ) {
    T.read();
    T.work();
  }
}

// @end_of_source_code


