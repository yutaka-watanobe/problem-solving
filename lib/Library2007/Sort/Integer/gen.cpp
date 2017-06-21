#include<iostream>
using namespace std;

main(){
  int n = 100;
  cout << n << endl;
  for ( int i = 0; i < n; i++ ){
    cout << rand()%50 << " ";
  }
  cout << endl;
}
