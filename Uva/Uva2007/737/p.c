// @JUDGE_ID:  17051CA  737  C++
// @begin_of_source_code
/* Geometory */
/* Cube の全てのIntersection の体積を求める */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

class Cube{
 public:
  int x1, x2, y1, y2, z1, z2;

  Cube(){}
  Cube( int x1, int y1, int z1, int x2, int y2, int z2):
    x1(x1), y1(y1), z1(z1), x2(x2), y2(y2), z2(z2){


  }
  
  bool intersect( Cube n ){

    if ( n.x1 <= x1 && x1 <= n.x2 && n.x2 <= x2 ){
      x2 = n.x2;
    } else if ( x1 <= n.x1 && n.x1 <= x2 && x2 <= n.x2 ){
      x1 = n.x1;
    } else if ( x1 <= n.x1 && n.x1 <= n.x2 && n.x2 <= x2 ){
      x1 = n.x1;
      x2 = n.x2;
    } else if ( n.x1 <= x1 && x1 <= x2 && x2 <= n.x2 ){

    } else {
      x1 = x2 = 0;
      return false;
    }

    if ( n.y1 <= y1 && y1 <= n.y2 && n.y2 <= y2 ){
      y2 = n.y2;
    } else if ( y1 <= n.y1 && n.y1 <= y2 && y2 <= n.y2 ){
      y1 = n.y1;
    } else if ( y1 <= n.y1 && n.y1 <= n.y2 && n.y2 <= y2 ){
      y1 = n.y1;
      y2 = n.y2;
    } else if ( n.y1 <= y1 && y1 <= y2 && y2 <= n.y2 ){

    } else {
      y1 = y2 = 0;
      return false;
    }

    if ( n.z1 <= z1 && z1 <= n.z2 && n.z2 <= z2 ){
      z2 = n.z2;
    } else if ( z1 <= n.z1 && n.z1 <= z2 && z2 <= n.z2 ){
      z1 = n.z1;
    } else if ( z1 <= n.z1 && n.z1 <= n.z2 && n.z2 <= z2 ){
      z1 = n.z1;
      z2 = n.z2;
    } else if ( n.z1 <= z1 && z1 <= z2 && z2 <= n.z2 ){

    } else {
      z1 = z2 = 0;
      return false;
    }

    return true;
  }

  int volume(){
    return abs( (x2-x1)*(y2-y1)*(z2-z1) );
  }

};

int n;
vector<Cube> C;

int read(){
  C.clear();
  cin >> n;
  if ( n == 0 ) return 0;

  int x, y, z, d;
  
  Cube c;
  for ( int i = 0; i < n; i++ ){
    cin >> x >> y >> z >> d;
    d = abs( d );
    c = Cube( x, y, z, x + d, y + d, z + d );
    C.push_back ( c );
  }

  return 1;
}

void work(){
  
  for ( int i = 1; i < C.size(); i++ ){
    if ( ! (C[0].intersect( C[i] )) ) break;
  }

  cout << C[0].volume() << endl;
}

main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code








