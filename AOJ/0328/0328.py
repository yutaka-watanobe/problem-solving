#include<iostream>
using namespace std;
static const int NMAX = 100000;
static const int PMAX = 100000;

int N, T[2*PMAX+20+1];

int main(){
  int a, b;
  cin >> N;
  for ( int i = 0; i < N; i++ ){
    cin >> a >> b;
    T[a+b]++;
  }
  for ( int i = 0; i < 2*PMAX+20; i++ ){
    T[i+1] += T[i]/2;
    T[i] = T[i]%2;
    if ( T[i] ) cout << i << " " << 0 << endl;
  }

  return 0;
}
