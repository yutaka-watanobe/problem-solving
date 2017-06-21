#include<iostream>
#include<vector>
using namespace std;
static const int N = 100;

bool isSequence(vector<int> v){
  int d = v[1] - v[0];
  for ( int i = 1; i < v.size(); i++ ){
    if ( v[i] -  v[i-1] != d ) return false;
  }
  return true;
}

bool isSeq(vector<int> A,int n){
  int d = A[1] - A[0];
  for ( int i = 1; i < n; i++ ){
    if ( A[i] - A[i-1] != d ) return false;
  }
  return true;
}

main(){
  vector<int> A;
  int n, x;
  while(1){
    cin >> n;
    if ( n == 0 ) break;
    A.resize(n+1);
    for ( int i = 0; i < n+1; i++ ) {
      cin >> A[i];
    }

    for ( int i = 0; i < n+1; i++ ){
      vector<int> tmp = A;
      tmp.erase(tmp.begin() + i);
      if ( isSequence(tmp) ) {
	cout << A[i] << endl;
	break;
      }
    }
  }
}
