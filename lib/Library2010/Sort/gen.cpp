#include<iostream>
using namespace std;

main(){
  int n = 2000000;
  int A[2000000];
  cout << n << endl;
  for ( int i = 0; i < n; i++ ){
    A[i] = i;
  }

  for ( int i = 0; i < 10000; i++ ){
    int a = rand()%n;
    int b = rand()%n;
    swap(A[a], A[b]);
  }
  for ( int i = 0; i < n ;i++ ) cout << A[i] << endl;
}
