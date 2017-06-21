#include<iostream>
using namespace std;

// decimal to BASE
void convert( int x, int BASE ){
  if ( x / BASE ) convert( x / BASE, BASE );
  cout << x % BASE;
}

int main(){
  int n, base;
  while( cin >> n  >> base&& n >= 0){
    convert(n, base);
    cout << endl;
  }
  return 0;
}
