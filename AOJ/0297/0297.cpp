#include<iostream>
using namespace std;

int main(){
  int N, K, P;
  cin >> N;
  for ( int i = 0; i < N; i++ ){  // N 回繰り返す
    cin >> K >> P;
    cout << (K - 1) % P + 1 << endl;
  }
  return 0;
}
  
