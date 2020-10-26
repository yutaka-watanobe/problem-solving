#include<iostream>
using namespace std;

int main(){
  int N, A[1000];
  cin >> N;
  for ( int i = 0; i < N; i++ ) cin >> A[i];
  int maxr = 0, cnt = 0;
  for ( int i = N - 1; i >= 0; i-- ){
    if ( A[i] > maxr ) {
      cnt++;
      maxr = A[i];
    }
  }
  cout << cnt << endl;
  return 0;
}
