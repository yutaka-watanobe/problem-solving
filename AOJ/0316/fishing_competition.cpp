#include<iostream>
using namespace std;

int getScore(int iwa, int yam,
	       int a, int b, int c, int d) {
  return iwa * a + yam * b +
    (iwa / 10) * c + (yam / 20) * d;  
}

int main() {
  int h1, h2, k1, k2;
  int a, b, c, d;
  cin >> h1 >> h2 >> k1 >> k2;
  cin >> a >> b >> c >> d;

  int hiro = getScore(h1, h2, a, b, c, d);
  int ken = getScore(k1, k2, a, b, c, d);

  if      ( hiro > ken ) cout << "hiroshi" << endl;
  else if ( hiro < ken ) cout << "kenjiro" << endl;
  else cout << "even" << endl;
  
  return 0;
}
