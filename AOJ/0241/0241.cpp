#include<iostream>
using namespace std;

main(){
  int n;
  int x1, y1, z1, w1, x2, y2, z2, w2;
  int a, b, c, d, e, f, g, h;
  while(1){
   
    cin >> n;
    if ( n == 0 ) break;
    for ( int i = 0; i < n; i++ ){
      cin >> a >> b >> c >> d;
      cin >> e >> f >> g >> h;
      cout << (a*e-b*f-c*g-d*h ) << " ";
      cout << (a*f+b*e+c*h-d*g) << " ";
      cout << (a*g+c*e+d*f-b*h) << " ";
      cout << (a*h+d*e+b*g-c*f) << endl;
    }
  }
}
