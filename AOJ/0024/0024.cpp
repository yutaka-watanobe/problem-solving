#include<iostream>
#include<cmath>
using namespace std;

main(){
  double V;
  while( cin >> V ){
    int N = (int)ceil((V*V*4.9/(9.8*9.8)+5)/5.0 + 0.000000001);
    cout << N << endl;
  }
}
