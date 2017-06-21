#include<iostream>
using namespace std;

main(){
  int n = 100;
  cout << n << endl;
  for ( int x = 1; x <= 19; x+= 2){
    for ( int y = 1; y <= 19; y+= 2 ){
      cout << x << " " << y << " " << x << " " << y+1 << " " << x+1 << " " << y+1 << " " << x+1 << " " << y << endl;
    }
  }
}
