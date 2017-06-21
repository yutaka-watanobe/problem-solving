#include<iostream>
using namespace std;

void gen(int n){
  cout << n << endl;
  for ( int i = 0; i < n; i++ ){
    cout << 1 + rand()%20 << " " << rand()%364 << endl;
  }
}

main(){
  for ( int i = 0; i < 20; i++ )  gen(10);
  for ( int i = 0; i < 20; i++ )  gen(20);
  for ( int i = 0; i < 20; i++ )  gen(25);
  cout << 0 << endl;
}
