#include<iostream>
using namespace std;
#define MAX 100
main(){
  
  for ( int k = 0; k < 100; k++ ){
    int size = 10;
    cout << size << endl;
    for ( int i = 0; i < size; i++ ){
      for ( int j = 0; j < size; j++ ){
	if ( rand()%2 == 0 || rand()%3 == 0 ) cout << ".";
	else cout << "*";
      }
      cout << endl;
    }
  }


  for ( int k = 0; k < 30; k++ ){
    int size = (rand()%MAX) + 20;
    cout << size << endl;
    for ( int i = 0; i < size; i++ ){
      for ( int j = 0; j < size; j++ ){
	if ( rand()%2 == 0 || rand()%3 == 0 ) cout << ".";
	else cout << "*";
      }
      cout << endl;
    }
  }

  for ( int k = 0; k < 10; k++ ){
    int size = 100;
    cout << size << endl;
    for ( int i = 0; i < size; i++ ){
      for ( int j = 0; j < size; j++ ){
	if ( rand()%739 == 0 ) cout << "*";
	else cout << ".";
      }
      cout << endl;
    }
  }

for ( int k = 0; k < 10; k++ ){
    int size = 100;
    cout << size << endl;
    for ( int i = 0; i < size; i++ ){
      for ( int j = 0; j < size; j++ ){
	cout << ".";
      }
      cout << endl;
    }
  }

  cout <<  0 << endl;
}
