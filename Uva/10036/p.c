// @JUDGE_ID:  17051CA  10036  C++
// @begin_of_source_code
/* Mod operation + Dynamic Programming */
#include<stdio.h>
#include<iostream>
#define MAX 10001

class Divisibility{
 public:
  int N, K;
  int sequence[ MAX ];
  bool positive[ MAX ][ 101 ];
  bool negative[ MAX ][ 101 ];

  void setFlag( int index, int value ){
    if ( value < 0 ) negative[ index ][ 0 - value ] = true;
    else positive[ index ][ value ] = true;
  }

  void work(){
    
    int value;
    value = sequence[ 0 ] % K;

    setFlag( 0, value );

    for ( int i = 1; i < N; i++ ){
      value = sequence[ i ] % K;

      for ( int v = 0; v <= K; v++ ){
	if ( positive[i-1][v] ){
	  setFlag( i, ( v + value ) % K );
	  setFlag( i, ( v - value ) % K );
	}
      }

      for ( int v = 1; v <= K; v++ ){
	if ( negative[i-1][v] ){
	  setFlag( i, ( -v + value ) % K );
	  setFlag( i, ( -v - value ) % K );
	}
      }
    }

     if ( positive[ N - 1 ][0] ) cout << "Divisible" << endl;
     else cout << "Not divisible" << endl;
  }

  bool read(){
    scanf("%d %d", &N, &K );

    for ( int i = 0; i < N; i++ ){
      for ( int j = 0; j <=K; j++ ){
	positive[i][j] = false;
	negative[i][j] = false;
      }
    }

    for ( int i = 0; i < N; i++ ){
      scanf("%d", &sequence[i] );
    }
  }

};

main(){
  Divisibility D;
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    D.read();
    D.work();
  }
}

// @end_of_source_code


