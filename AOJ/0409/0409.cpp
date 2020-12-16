#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int search(ll x, ll y){
  ll x_min = 0;
  ll y_min = 0;
  ll x_max = 0;
  ll y_max = 0;
  ll f, f1 = 1, f2 = 0;
  for ( ll p = 0;; p++){
    if ( x_min <= x && x <= x_max &&
         y_min <= y && y <= y_max  )
      return p % 3 + 1;
    f = f1 + f2;
    if ( p % 4 == 0 )  x_max += f;     // east
    else if ( p % 4 == 1 ) y_max += f; // north
    else if ( p % 4 == 2 ) x_min -= f; // west
    else  y_min -= f;                  // south
    f2 = f1;
    f1 = f;
  }
}

int main(){
  ll x, y;
  cin >> x >> y;
  cout << search(x, y) << endl;
  return 0;
}
