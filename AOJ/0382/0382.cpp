#include<iostream>
using namespace std;

int main(){
  int N, C;
  cin >> N >> C;
  int sum = 0;
  for ( int i = 0; i < C; i++ ){
    int x; cin >> x;
    sum += x;
  }
  N++;

  cout << sum/N + (sum%N==0?0:1) << endl;

  return 0;
}
