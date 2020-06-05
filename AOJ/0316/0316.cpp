#include<iostream>
using namespace std;

main(){
  int h1, h2, k1, k2, a, b, c, d;
  cin >> h1 >> h2 >> k1 >> k2;
  cin >> a >> b >> c >> d;
  int hiroshi = h1*a + h2*b + (h1/10)*c + (h2/20)*d;
  int kenjiro = k1*a + k2*b + (k1/10)*c + (k2/20)*d;

  if ( hiroshi > kenjiro ) cout << "hiroshi" << endl;
  else if ( hiroshi < kenjiro ) cout << "kenjiro" << endl;
  else cout << "even" << endl;
}
