#include<iostream>
using namespace std;

main(){
  int n, T[100], t;
  cin >> n;
  for ( int i = 0; i < n; i++ ) cin >> T[i];

  cin >> t;
  
  cout << distance(T, lower_bound( T, T + n, t )) << endl;
  cout << distance(T, upper_bound( T, T + n, t )) << endl;
}
