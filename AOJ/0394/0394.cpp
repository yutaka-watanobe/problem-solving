#include<iostream>
#include<cassert>
using namespace std;

int solve(int N, int K){
  int t = 1;
  int n = 1;
  int a = 1;

  while(1){
    n = (K+a-1)/K;
    a += n;
    if ( N < a ) return t;
    t++;
  }
}

int main() {
  int N, K; cin >> N >> K;
  int t = solve(N, K);
  cout << t << endl;
}
