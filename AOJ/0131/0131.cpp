#include<stdio.h>
#include<iostream>
#include<climits>
using namespace std;
#define SIZE 100

class ExtendedLightsOut{
 public:
  char M[SIZE], P[SIZE], A[SIZE];
  bool solved;
  int min_value;

  bool check(){
    for ( int i = 0; i < SIZE; i++ ) if ( M[i] == '1' ) return false;
    return true;
  }

  void flipM( int pos ){ M[pos] = ( M[pos] == '0' ) ? '1' : '0'; }
  void flipP( int pos ){ P[pos] = ( P[pos] == '0' ) ? '1' : '0'; }

  void press( int pos ){
    int x, y, nx, ny;
    x = pos / 10;
    y = pos % 10;

    flipM( pos );
    flipP( pos );

    nx = x + 1;
    ny = y;
    if ( 0 <= nx && 0 <= ny && nx < 10 && ny < 10 ) flipM( nx*10 + ny );

    nx = x;
    ny = y + 1;
    if ( 0 <= nx && 0 <= ny && nx < 10 && ny < 10 ) flipM( nx*10 + ny );

    nx = x - 1;
    ny = y;
    if ( 0 <= nx && 0 <= ny && nx < 10 && ny < 10 ) flipM( nx*10 + ny );

    nx = x;
    ny = y - 1;
    if ( 0 <= nx && 0 <= ny && nx < 10 && ny < 10 ) flipM( nx*10 + ny );

  }

  bool recursive( int pos ){
    if ( pos == SIZE ) return check();

    if ( pos < 10 ){
      if ( recursive( pos + 1 ) ) return true;
      press( pos );
      if ( recursive( pos + 1 ) ) return true;
      press( pos );
    } else {
      int p = pos - 20;
      if ( p > 0 && M[p] == '1' ) return false;
      int v = pos - 10;
      if ( M[v] == '1' ) {
	press( pos );
	if ( recursive( pos + 1 ) ) return true;
	press( pos );
      } else {
	if ( recursive( pos + 1 ) ) return true;
      }
    }
    return false;
  }

  void print(){
    for ( int i = 0; i < 10; i++ ){
      for ( int j = 0; j < 10; j++ ){
	if ( j ) printf(" ");
	printf("%c", P[i*10+j] );
      }
      printf("\n");
    }
  }

  void work(){
    for ( int i = 0; i < SIZE; i++ ){
	P[i] = '0';
    }
    solved = false;
    min_value = INT_MAX;
    if ( recursive( 0 ) ){
      print();
    }else{
      cout << "NO SOLUTION" << endl;
    }
  }

  void read(){
    for ( int i = 0; i < SIZE; i++ ){
      cin >> M[i];
    }
  }
};

main(){
  ExtendedLightsOut ELO;
  int tcase;
  cin >> tcase;
  for ( int i = 1; i <= tcase; i++ ){
    ELO.read();
    ELO.work();
  }
}
