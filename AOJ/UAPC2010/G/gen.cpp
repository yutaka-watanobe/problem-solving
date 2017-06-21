#include<iostream>
using namespace std;

void gen(int H, int W){
  cout << H << " " << W << endl;
  for ( int i = 0; i < H; i++ ){
    for ( int j = 0; j < W; j++ ){
      if ( j ) cout << " ";
      cout << rand()%10;
    }
    cout << endl;
  }
  cout << "0 0" << endl;
  cout << H-1 << " " << W-1 << endl;
}


main(){
  for ( int i = 0; i < 100; i++ ){
    gen(10, 10);
  }
  cout << "0 0" << endl;
}
