// @JUDGE_ID:  17051CA  2361  C++
// @begin_of_source_code
/* Gird Operation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

#define MAX 12
#define OTHER 0
#define HORIZONTAL 1
#define VERTICAL -1
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

int M[ 2 * MAX - 1 ][ 2 * MAX + 1 ];

int n, row, column;

bool read(){
  cin >> n;
  if ( n == 0 ) return false;
  row = 2 * n - 1;
  column = 2 * n + 1;

  /* init */
  for ( int i = 0; i < row; i++ ){
    for ( int j = 0; j < column; j++ ){
      M[i][j] = OTHER;
    }
  }

  for ( int i = 0; i < row; i += 2 ){
    for ( int j = 1; j < column; j += 2 ){
      cin >> M[i][j];
    }
  }
}

void setInitial(){
  for ( int i = 0; i < row; i += 2 ){
    for ( int j = 1; j < column; j += 2 ){
      if ( M[i][j] == HORIZONTAL ){
	M[i][j-1] = RIGHT;
	M[i][j+1] = LEFT;
      } else if ( M[i][j] == VERTICAL ){
	M[i-1][j] = DOWN;
	M[i+1][j] = UP;
      } else if ( M[i][j] == OTHER ) {
	/* ignore in this step */
      } else {
	assert ( false );
      }
    }
  }
}

void setHydrogen(){
  for ( int i = 0; i < row; i += 2 ){
    for ( int j = 1; j < column; j += 2 ){
      if ( M[i][j] != OTHER ) continue;
      if ( i == 0 ){
	if ( M[i][j-1] == OTHER ) M[i][j-1] = RIGHT;
	else M[i][j+1] = LEFT;
	M[i+1][j] = UP;
      } else if ( i == row - 1 ) {
	if ( M[i][j-1] == OTHER ) M[i][j-1] = RIGHT;
	else M[i][j+1] = LEFT;
	M[i-1][j] = DOWN;
      } else {
	if ( M[i][j-1] == OTHER ) M[i][j-1] = RIGHT;
	else M[i][j+1] = LEFT;
	if ( M[i-1][j] == OTHER ) M[i-1][j] = DOWN;
	else M[i+1][j] = UP;
      }
    }
  }
}

void printAsta(){
  for ( int j = 0; j < 4 * n + 3; j++ ) cout << '*';
  cout << endl;
}

void printResult(){
  printAsta();

  for ( int i = 0; i < row; i++ ){
    if ( i % 2 == 0 ){
      cout << '*';
      for ( int j = 0; j < column; j++ ){
	if ( j % 2 == 0 ){
	  if ( j == 0 ) cout << "H-";
	  else if ( j == column - 1 ) cout << "-H";
	  else {
	    if ( M[i][j] == LEFT ) cout << "-H ";
	    else if ( M[i][j] == RIGHT ) cout << " H-";
	  }
	} else {
	  cout << 'O';
	}
      }
      cout << '*' << endl;
    } else {
      cout << '*';
      for ( int j = 0; j < column; j++ ){
	if ( j % 2 == 0 ) {
	  if ( j == 0 || j == column - 1 ) cout << "  ";
	  else cout << "   ";
	} else {
	  if ( M[i][j] == UP ) cout << "|";
	  else cout << " ";
	}
      }
      cout << '*' << endl;
      cout << '*';
      for ( int j = 0; j < column; j++ ){
	if ( j % 2 == 0 ) {
	  if ( j == 0 || j == column - 1 ) cout << "  ";
	  else cout << "   ";
	} else {
	  cout << "H";
	}
      }
      cout << '*' << endl;
      cout << '*';
      for ( int j = 0; j < column; j++ ){
	if ( j % 2 == 0 ) {
	  if ( j == 0 || j == column - 1 ) cout << "  ";
	  else cout << "   ";
	} else {
	  if ( M[i][j] == DOWN ) cout << "|";
	  else cout << " ";
	}
      }
      cout << '*' << endl;     
    }
  }

  printAsta();
}

void work(){
  setInitial();
  setHydrogen();
  printResult();
}

main(){
  for ( int i = 1; read(); i++ ){
    if ( i > 1 ) cout << endl;
    cout << "Case " << i << ":" << endl;
    cout << endl;
    work();
  }
}
// @end_of_source_code
