#include<iostream>
using namespace std;

const int MAX_X = 2000;
const int MAX_Y = 2000;

//sはグローバル変数なので 宣言時に0に初期化される
int s[MAX_X][MAX_Y];

int main() {
  int x, y, w, h;
  for ( int k = 0; k<2; ++k ) {
    cin >> x >> y >> w >> h;
    for ( int i = x; i < x + w; ++i ) 
      for ( int j = y; j < y + h; ++j ) ++s[i][j];
  }
    
  int c = 0;
  for ( int i = 0; i < MAX_X; ++i ) 
    for ( int j = 0; j < MAX_Y; ++j ) 
      if ( s[i][j] == 1 ) ++c;
  cout << c << endl;
  return 0;
}
