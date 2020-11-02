#include<iostream>
#include<vector>
using namespace std;
static const int PMAX = 100000;

vector<int> T(2 * PMAX + 20);

int main(){
  int N, a, b;
  cin >> N;
  for ( int i = 0; i < N; i++ ){
    cin >> a >> b;
    T[a + b]++;
  }
  for ( int i = 0; i < 2 * PMAX + 20 - 1; i++ ){
    T[i + 1] += T[i] / 2;
    T[i] %= 2;
    if ( T[i] ) cout << i << " " << 0 << endl;
  }

  return 0;
}
