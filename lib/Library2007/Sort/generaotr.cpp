#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

main(){
  int n = 1000;
  for ( int i = 0; i< n ; i++ ){
    cout << rand()%100000 << " ";
    for ( int i = 1; i < rand()%5 + 3; i++ ){
      cout << (char)('a' + rand()%26);
    }
    cout << endl;
  }
}
