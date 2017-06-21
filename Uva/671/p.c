// @JUDGE_ID:  17051CA  671  C++
// @begin_of_source_code
/* Binary Search + */
/* Edit Distance --> only distance 1 --> can be O(n) */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#include<cmath>
#define MAX 10001

struct Word{
  char content[20];
};

class SpellChecker{
 public:
  Word W[ MAX ];
  string  sortedW[ MAX ];
  int nword;

  void compute( char *str ){

    string tmp = str;
    if ( binary_search( sortedW, sortedW + nword, tmp ) ){
      printf("%s is correct\n", str );
      return;
    }

    printf("%s:", str );

    int size = strlen ( str );

    for ( int i = 0; i < nword; i++ ){
      Word w = W[i];
      int lsize = strlen( str );
      int wsize = strlen( w.content );
      if ( abs( lsize - wsize ) > 1 ) continue;

      bool able = false;

      if ( lsize == wsize ){
	int diff = 0;
	for ( int i = 0; i < lsize; i++ ){
	  if ( str[i] != w.content[i] ) diff++;
	}
	if ( diff == 1 ) able = true;
      } else if ( wsize > lsize ){
	int match = 0;
	int j = 0;
	for ( int i = 0; i < lsize && j < wsize; ){
	  if ( str[i] == w.content[j] ){
	    match++;
	    i++;
	  }
	  j++;
	}
	if ( match == lsize ) able = true;
      } else {
	int match = 0;
	int j = 0;
	for ( int i = 0; i < wsize && j < lsize; ){
	  if ( str[j] == w.content[i] ){
	    match++;
	    i++;
	  }
	  j++;
	}
	if ( match == wsize ) able = true;
      }
      
      if ( able ){
	printf(" %s", w.content );
      }

    }
    printf("\n");
  }

  void work(){

    char line[20];

    while ( 1 ){
      scanf("%s", line );
      if ( line[0] == '#' ) break;
      compute( line );
    }
  }

  void read(){
    nword = 0;
    while ( 1 ){
      Word w;
      scanf("%s", w.content );
      if ( w.content[0] == '#' ) break;
      
      W[ nword ] = w;
      sortedW[ nword ] = w.content;
      nword++;
    }
    sort( sortedW, sortedW + nword );
  }

};

main(){
  SpellChecker SC;
  int tcase;
  scanf("%d", &tcase); 
  for ( int i = 0; i < tcase; i++ ){
    if ( i ) printf("\n");
    SC.read();
    SC.work();
  }
}

// @end_of_source_code


