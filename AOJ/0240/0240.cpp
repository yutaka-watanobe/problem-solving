#include<iostream>
#include<cmath>
using namespace std;

double fukuri( int y, int r ){
  double ans = 1;
  for ( int i = 0; i < y; i++ )  ans *= 1 + r/100.0;
  return ans;
}

double tanri( int y, int r ){
  return 1 + y * (r/100.0);
}

main(){
  int n, y, b, r, ans, t;
  double maxv , var;

  while(1){
    cin >> n;
    if ( n == 0 ) break;
    cin >> y;
    maxv = -1;

    for ( int i= 0; i < n; i++ ){
      cin >> b >> r >> t;

      if ( t == 2 ) var = fukuri(y, r);
      else if ( t == 1)  var = tanri(y, r);

      if ( maxv < var ){
	maxv = var;
	ans = b;
      }
    }
    cout << ans << endl;
  }
}
