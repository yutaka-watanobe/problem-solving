// @JUDGE_ID:  17051CA  10567  C++
// @begin_of_source_code
/* String Search */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#define MAX 1000000
#define EMPTY INT_MAX

int N;
int tmp[52];
char str[ MAX ]; 
int nextTable[ 100000 ][52]; 

void init(){
  scanf("%s", str );
  N = strlen( str );
  
  for ( int i = 0; i < 52; i++ ) tmp[i] = EMPTY;
  
  char ch;
  for ( int i = N - 1; i >= 0; i-- ){
    ch = str[i];
    
    if ( islower( ch ) ){
      tmp[ ch - 71 ] = i; /* ch - 'a' + 26 */
    } else {
      tmp[ ch - 'A' ] = i;
    }
    if ( i % 10 == 0 ){
      for ( int t = 0; t < 52; t++ ) nextTable[ i / 10 ][t] = tmp[t];
    }
  }

}

class HelpingFillBates{
 public:
  char candidate[ 101 ];
  int ncandidate;
  
  void compute(){
    
    int cursor = 0;
    int lower, upper;

    lower = upper = -1;

    for ( int i = 0; i < ncandidate; i++ ){

      bool isMatch = false;

      char target = candidate[i];

      while ( true ){
	if ( str[ cursor ] == target ){
	  isMatch = true;
	  if ( i == 0 && lower == -1) lower = cursor;
	  else if ( i == ncandidate - 1 && upper == -1 ) upper = cursor;
	  cursor++;
	  goto next;
	} 

	if ( cursor % 10 == 0 ) {
	  if ( islower( target ) ){
	    cursor = nextTable[cursor/10][ target - 71 ];
	  } else {
	    cursor = nextTable[cursor/10][ target - 'A' ];
	  }
	} else {
	  cursor++;
	}

	if ( cursor >= N ) goto next;
      }

    next:;
      if ( !isMatch ){
	printf("Not matched\n" );
	return;
      }
    }

    printf("Matched %d %d\n", lower, upper );

  }

  void work(){
    int q;
    cin >> q;
    for ( int i = 0; i < q; i++ ){
      scanf("%s",candidate );
      ncandidate = strlen( candidate );

      compute();
    }

  }

};

main(){
  init();
  HelpingFillBates HFB;
  HFB.work();
}

// @end_of_source_code


