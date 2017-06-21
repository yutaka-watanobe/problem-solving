#include<iostream>
using namespace std;


void gen( int size ){
  cout << size << endl;
  for ( int i = 0; i < size; i++ ){
    for ( int j = 0; j < size; j++ ){
      if ( rand()%53 == 0 || rand()%23 == 0) cout << "0 ";
      else cout << "1 ";
    }
    cout << endl;
  }
}

main(){
  for ( int i = 0; i < 10; i++ ){
    gen(20);
  }

  for ( int i = 0; i < 5; i++ ){
    gen(50);
  }


  cout << 0 << endl;
}
