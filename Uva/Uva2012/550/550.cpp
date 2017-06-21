#include<iostream>
using namespace std;
typedef unsigned long long ll;

main(){
  ll b, c, x, p, a;
  while( cin >> b >> c >> x ){
    if ( c == 0 || x == 1 ) {
      cout << 1 << endl; continue;
    }
    p = 0;
    a = c;
    for ( int d = 1;; d++){
      p = p/b + c*x;
      if ( a == p%b && p/b == 0){
	cout << d << endl;
	break;
      }
      c = p%b;
    }
  }
}
