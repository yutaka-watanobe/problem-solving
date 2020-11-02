#include<iostream>
using namespace std;

int main(){
  int N, C;
  cin >> N >> C;
  N++;
  
  int sum = 0;
  for ( int i = 0; i < C; i++ ){
    int p; cin >> p;
    sum += p;
  }

  cout << sum / N + (sum %N == 0 ? 0 : 1) << endl;
  return 0;
}
