#include<iostream>
using namespace std;
#define N 10007

int pre(int i){
  if ( i == 0 ) return N-1;
  else return i-1;
}

int next(int i ){ return (i+1)%N; }

main(){
  int n = N;
  cout << n << endl;
  for ( int i = 0; i < n; i++ ){
    cout << next(i) << " 1 " <<  pre(i) << " 1" << endl;
  }
  cout << 0 << endl;
}
