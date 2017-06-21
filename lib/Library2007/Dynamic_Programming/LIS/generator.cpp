#include<iostream>
#include<stdlib.h>

using namespace std;

void print(int n){
  cout << n << endl;
  for ( int i = 0; i < n; i++ ){
    cout << rand()%1000 << " ";
  }
  cout << endl;

}

main(){
  print(20);
  print(30);
  print(10);
  print(50);
  print(50);
  print(50);
  print(100);
  print(1000);
}
