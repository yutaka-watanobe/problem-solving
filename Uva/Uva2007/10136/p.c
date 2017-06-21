// @JUDGE_ID:  17051CA  10136  C++
// @begin_of_source_code
#include<stdio.h>
#include<stl.h>
#include<vector>
#include<string>
#include<iostream>
#define MAX 201
#define EPS 0.000001 /* 小さすぎてもダメ！ */
#define R 2.5
#define D 5.0

class point{
 public:
  double x, y;
  point(){}
  point(double x, double y):x(x), y(y){}
};

class Choco{
 public:
  int npoint;
  point P[MAX];

  int check( point p1, point p2, double dist ){
    double ex, ey, cx, cy, a, b, x, y, X,h;
    ex = (p1.x - p2.x ) / dist;
    ey = (p1.y - p2.y ) / dist;
    a = (p1.x + p2.x ) / 2.0;
    b = (p1.y + p2.y ) / 2.0;

    double d = dist/2.0;
    h = sqrt( R*R - d*d );
    
    cx = -h*ey + a;
    cy = h*ex + b;

    int sum1, sum2;
    sum1 = sum2 = 0;

    for ( int i = 0; i < npoint; i++ ){
      x = P[i].x;
      y = P[i].y;
      X = ( x - cx )*( x - cx ) + ( y - cy )*( y - cy );
      if ( X <= R*R || fabs(X-R*R) < EPS) sum1++;
    }

    cx = h*ey + a;
    cy = -h*ex + b;

    for ( int i = 0; i < npoint; i++ ){
      x = P[i].x;
      y = P[i].y;
      X = ( x - cx )*( x - cx ) + ( y - cy )*( y - cy );
      if ( X <= R*R || fabs(X-R*R) < EPS ) sum2++;
    }

    return max( sum1, sum2 );
  }


  double getDistance( double x1, double y1, double x2, double y2 ){
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
  }

  void work(){

    double ex, ey, dist;
    point p1, p2;
    int maxValue;

    if ( npoint > 0 ) maxValue = 1;
    else maxValue = 0;

    for ( int i = 0; i < npoint-1; i++ ){
      for ( int j = i+1; j < npoint; j++ ){
	p1 = P[i];
	p2 = P[j];
	dist = getDistance( p1.x, p1.y, p2.x, p2.y );
	if ( dist <= D ){
	  maxValue = max( maxValue, check(p1, p2, dist) );
	}
      }
    }

    printf("%d\n", maxValue);
  }

  void read(){
    string line;
    double x, y;
    npoint = 0;
    vector<string> com;

    while (getline(cin, line) && !line.empty() && sscanf(line.c_str(), "%lf %lf", &x, &y) == 2 )
      P[npoint].x = x, P[npoint].y = y, npoint++;

    /*
    while ( 1 ){
      getline( cin, line );
      if ( line.size() == 0 || cin.eof() ) return;
      com.clear();
      split( com, line );
      sscanf(com[0].c_str(), "%lf", &x );
      sscanf(com[1].c_str(), "%lf", &y );

      P[npoint++] = point(x, y);
      }*/
  }

};

main(){
  Choco C;
  int tcase;
  cin >> tcase; 
  string line;
  getline(cin, line );
  getline(cin, line );

  for ( int i = 0; i < tcase; i++ ){
    if ( i ) printf("\n");
    C.read();
    C.work();
  }
}
// @end_of_source_code
