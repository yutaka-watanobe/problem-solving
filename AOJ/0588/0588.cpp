#include<iostream>
using namespace std;

main(){
  int a, b;
  char op;
  cin >> a;
  while(1){
    cin >> op;
    if ( op == '=' ) break;
    cin >> b;
    if ( op == '+' ) a += b;
    else if ( op == '*' ) a *= b;
    else if ( op == '-' ) a -= b;
    else if ( op == '/' ) a /= b;
  }
  cout << a << endl;
}
