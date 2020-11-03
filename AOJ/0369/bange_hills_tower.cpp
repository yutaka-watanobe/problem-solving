#include<iostream>
using namespace std;

int main() {
  int N;
  double t, maxSlope = 0.0, xi, hi;
  cin >> N >> t;

  for ( int i = 0; i < N; i++ ) {
    cin >> xi >> hi;
    double slope = hi / xi;
    if ( slope > maxSlope ) maxSlope = slope;
  }

  //coutで小数点以下６桁を常に表示
  cout.setf(ios_base::fixed, ios_base::floatfield);
  
  cout << t * maxSlope << endl;
  return 0;
}
