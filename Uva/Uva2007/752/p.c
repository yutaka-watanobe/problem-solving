// @JUDGE_ID:  17051CA  752  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#define MAX 256
#define INTERNAL -1

class UnscramblingImages{
 public:
  int P[ MAX ]; /* password */
  int M[ MAX ][ MAX ];
  int N;

  void fillPixel( int node, int intensity ){
    if ( P[ node ] == INTERNAL ){
      for ( int i = 1; i <= 4; i++ ){
	fillPixel( node * 4 + i, intensity );
      }
    } else {
      int pos = P[ node ];
      M[pos/N][pos%N] = intensity;
    }
  }

  void work(){
    int m, node, intensity;
    cin >> m;
    for ( int i = 0; i < m; i++ ){
      cin >> node >> intensity;
      fillPixel( node, intensity );
    }
    printResult();
  }

  void printResult(){
    for ( int i = 0; i < N; i++ ){
      for ( int j = 0; j < N; j++ ){
	printf("%4d", M[i][j] );
      }
      printf("\n");
    }
    printf("\n");
  }

  void read(){
    int m, index, target;
    cin >> N;
    for ( int i = 0; i < N * N ; i++ ) P[i] = INTERNAL;

    cin >> m;
    for ( int i = 0; i < m; i++ ){
      cin >> index >> target;
      P[ index ] = target;
    }
    
  }

  void start(){
    int tcase;
    cin >> tcase;
    for ( int i = 1; i <= tcase; i++ ){
      cout << "Case " << i << endl << endl;
      read();
      work();
    }
  }
};

main(){
  int tcase;
  cin >> tcase;
  UnscramblingImages UI;

  for ( int i = 0; i < tcase; i++ ){
    if ( i ) cout << endl;
    UI.start();
  }
}
// @end_of_source_code


