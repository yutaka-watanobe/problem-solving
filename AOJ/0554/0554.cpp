#include<iostream>
using namespace std;

main(){
  int sum = 0, x;
  for ( int i = 0; i < 4; i++ ){
    cin >> x;
    sum += x;
  }

  cout << sum/60 << endl;
  cout << sum%60 << endl;
}
