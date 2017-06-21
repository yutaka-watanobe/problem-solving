#include<iostream>
using namespace std;

main(){
  int n; cin >> n;
  long long v = 1;
  for (int i = 1; i <= n; i++ ){
    v *= i;
  }
  cout << v << endl;

}
