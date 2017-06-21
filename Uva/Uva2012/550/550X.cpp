#include<iostream>
using namespace std;
typedef unsigned long long ll;

ll power(ll b, ll p){
  ll a = 1;
  for ( int i = 0; i < p; i++ ) a *= b;
  cout << a << endl;
  return a;
}

ll rot(ll x, ll b, ll k){
  ll a = x/b;
  ll r = x%b;
  a += r*power(b, k-1);
  return a;
}

main(){
  ll b, c, x, d;
  while( cin >> b >> c >> x ){
    ll d = 0;
    ll cur = c;
    if ( c == 0 || x == 1 ) {
      cout << 1 << endl; continue;
    }
    while(1){
      //      if ( cur*x == rot(cur, b, d+1) ){
      if ( rot(cur, b, d+1)%x == 0 &&
	   rot(cur, b, d+1)/x == cur ){

	cout << d+1 << endl;
	break;
      }
      cur = c + cur*x%power(b, d+1)*b;
      d++;
          cout << d << endl;
    }

  }
}
