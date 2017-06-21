// @JUDGE_ID:  17051CA  2281  C++
// @begin_of_source_code
/* Simple Calculation */
#include<stdio.h>
#include<iostream>
#include<vector>

class Color{
 public:
  int r, g, b;
  Color(){}
  Color( int r, int g, int b ): r(r), g(g), b(b){}
};

vector<Color> T; /* color table */

int getDistance ( Color &c1, Color &c2 ){
  int R1, G1, B1, R2, G2, B2;
  R1 = c1.r; R2 = c2.r;
  G1 = c1.g; G2 = c2.g;
  B1 = c1.b; B2 = c2.b;
  return (R2 - R1)*(R2 - R1) + (G2 - G1)*(G2 - G1) + (B2 - B1)*(B2 - B1);
}

void search_nearest( Color q ){
  Color nearestColor;
  int nearest = INT_MAX;
  for ( int i = 0; i < T.size(); i++ ){
    int d = getDistance( T[i], q );
    if ( nearest > d ){
      nearest = d;
      nearestColor = T[i];
    }
  }
  cout << "(" << q.r << "," << q.g << "," << q.b << ")";
  cout << " maps to ";
  cout << "(" << nearestColor.r << "," << nearestColor.g << "," << nearestColor.b << ")";
  cout << endl;
}

void work(){
  int x, y, z;
  while ( 1 ){
    cin >> x >> y >> z;
    if ( x == -1 && y == -1 && z == -1 ) return ;
    search_nearest( Color( x, y, z ) );
  }
}

void read(){
  int r, g, b;
  for ( int i = 0; i < 16; i++ ){
    cin >> r >> g >> b;
    T.push_back( Color( r, g, b ) );
  }
}

main(){
  read();
  work();
}
// @end_of_source_code
