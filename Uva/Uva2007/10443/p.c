// @JUDGE_ID:  17051CA  10443  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>
#include<string>
#include<cmath>
#define MAX 101

char G[MAX + 2][MAX + 2];
char nextG[MAX + 2][MAX + 2];

int timeD, row, column;
/*vector<vector<char> > G;*/

bool defeatWin( char c1, char c2 ){
  if ( c1 == 'R' ){
    if ( c2 == 'S' ) return true;
  }else if ( c1 == 'S' ){
    if ( c2 == 'P' ) return true;
  }else if ( c1 == 'P' ){
    if ( c2 == 'R' ) return true;
  }
  return false;
}

void determinG(){

  int nx, ny;
  nextG = G;

  for ( int i = 1; i <= row ;i++ ){
    for ( int j = 1; j <= column; j++ ){
      if ( defeatWin( G[i-1][j], G[i][j] ) ) nextG[i][j] = G[i-1][j];
      if ( defeatWin( G[i][j-1], G[i][j] ) ) nextG[i][j] = G[i][j-1];
      if ( defeatWin( G[i+1][j], G[i][j] ) ) nextG[i][j] = G[i+1][j];
      if ( defeatWin( G[i][j+1], G[i][j] ) ) nextG[i][j] = G[i][j+1];
    }
  }

  //  G = nextG;

  for ( int i = 1; i <= row ;i++ ){
    for ( int j = 1; j <= column; j++ ){
      G[i][j] = nextG[i][j];
    }
  }


}

void work(){
  for ( int i = 0; i < timeD; i++ ){
    determinG();
  }

  for ( int i = 1; i <= row; i++ ){
        for ( int j = 1; j <= column; j++ ){
          cout << G[i][j];
        }
        cout << endl;
  }
}

void read(){
  cin >> row >> column >> timeD;

  for ( int i = 0; i < row + 2; i++ ){
    for ( int j = 0; j < column + 2; j++ ){
      if ( i == 0 || j == 0 || i == row + 1 || j == column + 1 ){
	G[i][j] = ' ';
      } else {
	cin >> G[i][j];
      }
    }
  }
  
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
