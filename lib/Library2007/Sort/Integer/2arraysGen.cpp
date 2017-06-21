#include<iostream>
using namespace std;

main(){
  int n1 = 10000;
  int n2 = 10000;
  int p;
  cout << n1 << endl;
  p = 0;
  for ( int i = 0; i < n1; i++ ){
    cout << p << " ";
    p += rand()%5;
  }
  cout << endl;
  cout << n2 << endl;

  for ( int i = 0; i < n2; i++ ){
    cout << p << " ";
    p += rand()%5;
  }
  cout << endl;

}
