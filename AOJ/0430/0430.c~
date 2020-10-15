#include<iostream>
using namespace std;

int main(){
  int N, x, d;
  cin >> N >> x;
  int R = x;
  int L = x;
  
  for ( int i = 0; i < N; i++ ){
    cin >> d;
    R = max(R, d);
    L = min(L, d);
  }
  int minv = min(R - x, x - L);
  int maxv = max(R - x, x - L);
  cout << minv * 2 + maxv << endl;
  return 0;
}
