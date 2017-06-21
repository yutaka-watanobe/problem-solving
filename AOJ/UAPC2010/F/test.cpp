#include<iostream>
#include<cmath>

using namespace std;

double power2(int n){
    double p = 1.0;
    for ( int i = 0; i < n; i++ ) p *= 2.0;
    return p;
}

main(){
  int n;
  cin >> n;
  cout << pow(2.0, n) << endl;
  cout << power2(n) << endl;
}
