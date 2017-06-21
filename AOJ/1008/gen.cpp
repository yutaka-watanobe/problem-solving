#include<iostream>

using namespace std;

void gen( int n, int r){

  cout << n << endl;
  for ( int i = 0; i < n; i++ ){
    if ( i ) cout << " ";
    if ( i % 2 == 0 ) cout << 86;
    else cout << rand()%r;
  }
  cout << endl;



}
void gen2( int n, int r){

  cout << n << endl;
  for ( int i = 0; i < n; i++ ){
    if ( i ) cout << " ";
    cout << rand()%r;
  }
  cout << endl;



}
main(){
  
  gen(20, 3);
  gen(25, 100);
  gen(23, 99);
  gen(22, 22);
  gen(25, 100);
  gen(10, 3);
  gen(10, 4);
  gen(10, 2);
  gen(15, 3);
  gen(18, 100);
  gen(100, 100);
  gen(80, 87);
  gen(100, 87);
  gen(120, 87);
  gen(1000, 87);
  gen(10000, 87);
  gen(100000, 1000);
  gen(799999, 1000000);
  gen(899998, 10000);
  gen(200000, 87);
  gen(300000, 100000);
  gen(400000, 87);
  gen(1000000, 87);
  gen2(1000000, INT_MAX);
  


  cout << 0 << endl;
}
