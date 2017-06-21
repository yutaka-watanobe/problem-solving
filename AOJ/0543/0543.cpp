#include<iostream>
using namespace  std;

main(){
  int total, sum, x;
  while( cin >> total && total ){
    sum = 0;
    for ( int i = 1; i < 10; i++ ){
      cin >> x; sum += x;
    }
    cout << total - sum << endl;
  }
}
