// @JUDGE_ID:  17051CA  10453  C++
// @begin_of_source_code
/* Dynamic Programming ( Similar to Edit Distance tech. ) */
/* 5.512 sec */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#define MATCH 0
#define LEFT 1
#define RIGHT 2
#define MAX 1001
using namespace std;

class cell{
 public:
  int cost;
  int parent;
  cell(){}
  cell( int cost, int parent ): cost( cost ), parent( parent ){}
};

cell M[MAX][MAX];

class Palindrome{
 public:
  string source, result;

  int n;
  int shift;
  
  Palindrome( string source ): source( source ){
    n = source.size();
  }
  
  void makePalindrome(){
    /* init */
    int i, j;
    for ( i = 0, j = 0 ; i < n; i++, j++ ){
	M[i][j].cost = 0;
	M[i][j].parent = -1;
    }
    for ( i = 1, j = 0; i < n; i++, j++ ){
      M[i][j].cost = 0;
      M[i][j].parent = -1;
    }
    
    int opt[ 3 ];

    for ( int sj = 1; sj < n; sj++ ){
      for ( i = 0, j = sj; j < n;  i++, j++ ){
	if ( source[i] == source[j] ){
	  M[i][j].cost = M[i+1][j-1].cost;
	  M[i][j].parent = MATCH;
	} else {
	  opt[ LEFT ] = M[i][j-1].cost + 1;
	  opt[ RIGHT ] = M[i+1][j].cost + 1;
	  if ( opt[ LEFT ] <= opt[ RIGHT ] ){
	    M[i][j].cost = opt[ LEFT ];
	    M[i][j].parent = LEFT;
	  } else {
	    M[i][j].cost = opt[ RIGHT ];
	    M[i][j].parent = RIGHT;
	  }
	}
      }
    }

    shift = 0;
    result = source;
    reconstruct_path( 0, n-1 );
  }

  void reconstruct_path( int i, int j ){

    if ( M[i][j].parent == -1 ) return;

    if ( M[i][j].parent == MATCH ) {
      reconstruct_path( i+1, j-1 );
      return;
    }

    if ( M[i][j].parent == LEFT ){
      insert_left( i, j );
      reconstruct_path( i, j-1 );
      return;
    }

    if ( M[i][j].parent == RIGHT ){
      insert_right( i, j );
      reconstruct_path( i+1, j );
      return;
    }
  }

  void match_out( int i, int j ){
    
  }

  void insert_left( int i, int j ){
    result.insert( result.begin() + (i + shift ), source[j] );
    shift++;
  }

  void insert_right( int i, int j ){
    result.insert( result.begin() + (j + 1 + shift), source[i] );
  }

  int getCost(){
    return M[0][n-1].cost;
  }

  string getPalindrome(){
    return result;
  }

  void testPrint(){
    for ( int i = 0; i < n; i++ ){
      for ( int j = 0; j < n; j++ ){
	printf( "%3d", M[i][j].cost );
      }
      cout << endl;
    }
    cout << endl;

    for ( int i = 0; i < n; i++ ){
      for ( int j = 0; j < n; j++ ){
	printf( "%3d", M[i][j].parent );
      }
      cout << endl;
    }
    cout << endl;
  }


};

main(){
  string source;
  while (  cin >> source ){
    Palindrome p = Palindrome( source );
    p.makePalindrome();
    cout << p.getCost() << " " << p.getPalindrome() << endl;
  }
}
// @end_of_source_code
