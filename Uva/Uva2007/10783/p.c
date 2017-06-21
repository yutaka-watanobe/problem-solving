// Simple Calculation
#include<iostream>

using namespace std;

int compute(){
  int a, b;
  cin >> a >> b;
  if ( a % 2 == 0 ) a++;
  if ( b % 2 == 0 ) b--;
  int sum = 0;
  for ( int i = a; i <= b; i+=2 ){
    sum += i;
  }

  return sum;
}

main(){
  int tcase; cin >> tcase;
  for ( int i = 1; i <= tcase; i++ ){
    cout << "Case " << i << ": " << compute() << endl;
  }
}
