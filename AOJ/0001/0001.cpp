#include<iostream>
#include<algorithm>
using namespace std;
main(){
  int A[10]; for ( int i = 0; i < 10; i++ ) cin >> A[i]; 
  sort(A, A+10);
  for ( int i = 9; i >= 7; i-- ) cout << A[i] << endl;

}
