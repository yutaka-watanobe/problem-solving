#include<iostream>
using namespace std;

main(){
  int H, W;
  char c;
  cin >> W >> H >> c;
  for ( int i = 0; i < H; i++ ){
    for ( int j = 0; j < W; j++ ){
      if ( i == 0 && j == 0 || i == 0 && j == W-1 ||
	   i == H-1 && j == 0 || i == H-1 && j == W-1 ){
	cout << '+';
      } else if ( i == 0 || i == H-1 ){
	cout << '-';
      } else if ( j == 0 || j == W-1 ){
	cout << '|';
      } else if ( i == H/2 && j == W/2 ){
	cout << c;
      } else {
	cout << '.';
      }
    }
    cout << endl;
  }
}
