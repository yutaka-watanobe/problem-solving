#include<iostream>
using namespace std;

main(){
  int tcase; cin >> tcase;
  char ch; 
  double h, m, diff;
  for ( int i = 0; i < tcase; i++ ){
    cin >> h >> ch >> m;
    h = 30.0*h + m/2.0;
    m = 6.0*m;
    diff = max(h, m) - min(h, m);
    diff = min(diff, 360-diff);
    if ( 0 <= diff && diff < 30 ) cout << "alert" << endl;
    else if ( 90 <= diff && diff <= 180 ) cout << "safe" << endl;
    else cout << "warning" << endl;
  }
}
