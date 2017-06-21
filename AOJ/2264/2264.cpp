#include<iostream>
using namespace std;
static const int MAX = 10000;

int main(){
  int N, K;
  cin >> N >> K;

  if ( N < 2*K ) {
    cout << -1 << endl;
    return 0;
  }

  int base[MAX], w, b;

  base[0] = 0;
  base[1] = 1;
  w = N-2;
  b = 1;
  for ( int i = 2; i < N; i++ ){
    base[i] = (base[i-1] + (w*b))%N;
    w--;
    b *= -1;
  }

  for ( int k = 0; k < K; k++ ){
    for ( int i = 0; i < N-1; i++ ){
      printf("%d %d\n",(base[i]+k)%N+1, (base[i+1]+k)%N+1);
    }
  }
  return 0;
}
