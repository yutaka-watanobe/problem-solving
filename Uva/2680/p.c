// @JUDGE_ID:  17051CA  2680  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#define MAX_SUB 16000000

int power(int x, int n){
  int tmp = 1;

  if(n>0){
    tmp = power(x, n/2);
    if(n%2==0) tmp = tmp*tmp;
    else tmp = tmp*tmp*x;
  }
  return tmp;
}

int N, NC;
int indexTable[ 256 ];
int current_index;
int buffer[ 10000 ];
int powerTable[ 32 ];
int upper;

char used[ MAX_SUB ];

void init(){
  upper = power( NC, N + 1 );

  fill ( indexTable, indexTable + 256, 0 );
  fill ( used, used + upper, 0 );
  current_index = 1;

  powerTable[0] = 1;
  for ( int i = 1; i < NC; i++ ){
    powerTable[ i ] = powerTable[ i - 1 ] * NC;
  }

}

void setIndex( char ch ){
  if ( indexTable [ ch ] == 0 ){
    indexTable[ ch ] = current_index;
    current_index++;
  }
}

void setUsed( int index ){
  
  int pos = 0;
  for ( int i = index; i >= index - N + 1; i-- ){
    pos += powerTable[ index - i ] * buffer[ i ];
  }

  used[ pos ] = 1;
}

void printResult(){
  int sum = 0;
  for ( int i = 0; i < upper; i++ ){
    if ( used[i] == 1 ) sum++;
  }
  printf( "%d\n", sum );
}

void work(){
  char ch;
  int index = 0;
  int n = N - 1;

  scanf( "%c", &ch ); /* ฒþนิ */

  while ( 1 ){
    scanf( "%c", &ch );
    if ( ch == '\n' || ch == EOF ) break;
    setIndex( ch );
    buffer[ index ] = indexTable[ ch ];

    if ( index >= n ){
      setUsed( index );
    }
    index++;
  }

  printResult();
}

void read(){

  scanf( "%d %d", &N, &NC );
  init();
  
}

main(){
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    if ( i ) cout << endl;
    read();
    work();
  }
}

// @end_of_source_code


