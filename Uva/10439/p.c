// @JUDGE_ID:  17051CA  10439  C++
// @begin_of_source_code
/* Geometory */
/* 4.846 sec --> not so good */
/* £≥ ’§Œ»ÊŒ®§«»Ê§Ÿ§ø */ 
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#include<stl.h>
#define EPS 0.0001

double T[3];
double PI;

double getDist( double &x1, double &y1, double &x2, double &y2 ){
  double dx = x1 - x2;
  double dy = y1 - y2;
  return sqrt( dx * dx + dy * dy );
}

bool valid( double &x0, double &y0, double &x1, double &y1, double &x2, double &y2 ){
  double M[3];

  M[0] = getDist( x0, y0, x1, y1 );
  M[1] = getDist( x0, y0, x2, y2 );
  M[2] = getDist( x2, y2, x1, y1 );
  sort( M, M + 3 );

  double minimum = M[0];
  
  M[0] /= minimum;
  M[1] /= minimum;
  M[2] /= minimum;

  if ( abs( M[1] - T[1] ) >= EPS ) return false;
  if ( abs( M[2] - T[2] ) >= EPS ) return false;
  return true;

}

int compute(){
  double r = 1.0;
  double p = PI / 180.0;

  for ( int n = 3; n <= 200; n++ ){
    double theta = 360.0 / n;
    double x0 = r;
    double y0 = 0.0;
    double x1, y1, x2, y2;
    for ( int i1 = 1; i1 <= n / 2; i1++ ){
      for ( int i2 = i1 + 1; i2 < n; i2++ ){

	double theta1 = p * (theta * i1 );
	double theta2 = p * (theta * i2 );
	x1 = cos( theta1 );
	y1 = sin( theta1 );
	x2 = cos( theta2 );
	y2 = sin( theta2 );

	if ( valid( x0, y0, x1, y1, x2, y2 ) ) return n;

      }
    }
  }
  assert( false );
  return -1;
}


void work(){
  int n;
  n = compute();
  cout << n << endl;
}

void read(){
  double x0, y0, x1, y1, x2, y2;
  cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
  T[0] = getDist( x0, y0, x1, y1 );
  T[1] = getDist( x0, y0, x2, y2 );
  T[2] = getDist( x2, y2, x1, y1 );
  sort( T, T + 3 );
  double minimum = T[0];
  T[0] /= minimum;
  T[1] /= minimum;
  T[2] /= minimum;
}

main(){
  PI = 2*acos( 0.0 );
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    read();
    work();
  }
}
// @end_of_source_code
