#include<iostream>
using namespace std;

int A[9], U[10], cnt;

void rec(int p){
  if ( p == 9 ){
    if ( ((A[0] + A[2] + A[5]) % 10 == A[8]) &&
	 (((A[0] + A[2] + A[5]) / 10 + A[1] + A[4]) % 10 == A[7]) &&
	 (((A[0] + A[2] + A[5]) / 10 + A[1] + A[4]) / 10 + A[3] == A[6]) ) cnt++;
  } else if ( A[p] == -1 ){
    for ( int i = 1; i <= 9; i++ ){
      if ( U[i] ) continue;
      U[i] = true;
      A[p] = i;
      rec(p+1);
      A[p] = -1;
      U[i] = false;
    }
  } else {
    U[A[p]] = true;
    rec(p+1);
  }
}

int main(){
  for ( int i = 0; i < 9; i++ ) cin >> A[i];
  cnt = 0;
  rec(0);
  cout << cnt << endl;
  return 0;
}
