#include<iostream>
using namespace std;

main(){
  int total = 0, sum = 0, v, a, n = 0;
  char ch;
  while( cin >> v >> ch >> a ){
    total += v*a;
    sum += a;
    n++;
  }
  cout << total << endl;
  cout << (int)(1.0*sum/n +0.5) << endl;
}
