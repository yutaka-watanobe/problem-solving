#include<iostream>
using namespace std;

main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if ( a == b && c == d ||
       a == c && b == d ||
       a == d && b == c ) cout << "yes" << endl;
  else cout << "no" << endl;

  return 0;
}
