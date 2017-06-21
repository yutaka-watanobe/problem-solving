#include<iostream>
using namespace std;

main(){
  for ( int i = 0; i < 10; i++ ){
    cout << "insert " << rand()%100 << endl;
  }
  for ( int i = 0; i < 1000; i++ ){
    if ( rand()%5== 0 ){
      cout << "get" << endl;
    } else {
      cout << "insert " << rand()%100 << endl;
    }
  }
  cout << "end" << endl;
}
