#include<iostream>
using namespace std;

void gen(){
  for ( int i = 0; i < 5; i++ ){
    cout << rand()%3+1 << endl;
  }
}

main(){
  for ( int i = 0; i < 100; i++ ){
    gen();
  }

  for ( int i = 0; i < 5; i++ ) cout << 1 << endl;
  for ( int i = 0; i < 5; i++ ) cout << 2 << endl;
  for ( int i = 0; i < 5; i++ ) cout << 3 << endl;

  for ( int i = 0; i < 5; i++ ) cout << rand()%2+1 << endl;
  for ( int i = 0; i < 5; i++ ) cout << rand()%2+1 << endl;
  for ( int i = 0; i < 5; i++ ) cout << rand()%2+1 << endl;

  cout << 0 << endl;
}
