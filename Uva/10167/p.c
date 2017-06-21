// @JUDGE_ID:  17051CA  10167  C++
// @begin_of_source_code
/* geometory - mathmatic */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>

class Point{
 public:
  int x, y;
};

vector<Point> P;

int read(){
  int n;
  cin >> n;
  if ( n == 0 ) return 0;
  P.clear();
  P.resize( 2*n );
  int x, y;
  for ( int i = 0; i < 2*n; i++ ){
    cin >> P[i].x >> P[i].y;
  }
  return 1;
}

bool check( int a, int b ){
  int By, Ax;
  int up, low;
  up = low = 0 ;
  for ( int i = 0; i < P.size(); i++ ){
    By = b * P[i].y;
    Ax = -1 * a * P[i].x;

    if ( By > Ax ) up++;
    else if ( By < Ax ) low++;
    else if ( By == Ax ) return false;
  }
  return ( low == up );
}

void work(){
  for ( int a = -500; a <= 500; a++ ){
    for ( int b = 0; b <= 500; b++ ){
      if ( a == 0 || b == 0 ) continue;
      if ( check(a, b) ){
	cout << a << " " << b << endl;
	return;
      }
    }
  }
}

main(){
  while ( read() ) work();
}
// @end_of_source_code
