#include<iostream>
using namespace std;
const int MAX_X = 2000;
const int MAX_Y = 2000;

int grid[MAX_X][MAX_Y]; // 海苔が置かれる区画。 グローバル変数のため0に初期化される。

int main() {
  int x, y, w, h;
  for ( int k = 0; k<2; ++k ) {
    cin >> x >> y >> w >> h;
    for ( int i = x; i < x + w; ++i ) 
      for ( int j = y; j < y + h; ++j ) ++grid[i][j];
  }
    
  int c = 0;
  for ( int i = 0; i < MAX_X; ++i ) 
    for ( int j = 0; j < MAX_Y; ++j ) 
      if ( grid[i][j] == 1 ) ++c;
  cout << c << endl;
  return 0;
}

