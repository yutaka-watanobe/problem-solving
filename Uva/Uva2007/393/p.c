// @JUDGE_ID:  17051CA  393  C++
// @begin_of_source_code
/* Geometory + Dynamic Programming */
#include<stdio.h>
#include<iostream>
#include<stl.h>
#include<cmath>
#define MAX 20

class point{
 public:
  double x, y;
  point(){}
  point(double x, double y): x(x), y(y){}
};

int direction(point pi, point pj, point pk){
  return (int)((pk.x - pi.x)*(pj.y - pi.y) - (pj.x - pi.x)*(pk.y - pi.y));
}

bool on_segment(point pi, point pj, point pk){
  if( min(pi.x, pj.x) <= pk.x && pk.x <= max(pi.x, pj.x) &&
      min(pi.y, pj.y) <= pk.y && pk.y <= max(pi.y, pj.y)) return true;
  else return false;
}

int segments_intersect(const point &p1, const point &p2, 
		 const point &p3, const point &p4){
  int d1, d2, d3, d4;
  bool on1, on2, on3, on4;

  d1 = direction(p3, p4, p1);
  d2 = direction(p3, p4, p2);
  d3 = direction(p1, p2, p3);
  d4 = direction(p1, p2, p4);

  on1 = on_segment(p3, p4, p1);
  on2 = on_segment(p3, p4, p2);
  on3 = on_segment(p1, p2, p3);
  on4 = on_segment(p1, p2, p4);

  if( ((d1>0 && d2<0)||(d1<0 && d2>0)) &&
      ((d3>0 && d4<0)||(d3<0 && d4>0)) ) return true;
  else if( d1==0 && on1 ) return true;
  else if( d2==0 && on2 ) return true;
  else if( d3==0 && on3 ) return true;
  else if( d4==0 && on4 ) return true;
  else return false;
}

class Wall{
 public:
  double x;
  double y[4];
  Wall(){}
  Wall( double x, double y1, double y2, double y3, double y4): x(x){
    y[0] = y1;
    y[1] = y2;
    y[2] = y3;
    y[3] = y4;
  }
};

class TheDoors{
 public:
  int N;
  Wall W[ MAX + 2 ];
  double T[ MAX + 2 ][ 4 ];
  double finalPoint;

  bool intersect( double x1, double y1, double x2, double y2, int source, int target ) {

    for ( int w = source + 1; w < target; w++ ){
      Wall wall = W[w];
      if ( segments_intersect( point( x1, y1 ), point( x2, y2 ), point( wall.x, 0.0 ), point( wall.x, wall.y[0] ) ) ) return true;
      if ( segments_intersect( point( x1, y1 ), point( x2, y2 ), point( wall.x, wall.y[1] ), point( wall.x, wall.y[2] ) ) ) return true;
      if ( segments_intersect( point( x1, y1 ), point( x2, y2 ), point( wall.x, wall.y[3] ), point( wall.x, 10.0 ) ) ) return true;
    }

    return false;
  }

  double getDistance( double x1, double y1, double x2, double y2 ){
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
  }

  void work(){
    /* start --> all */
    for ( int i = 1; i <= N; i++ ){
      Wall wall = W[i];
      for ( int j = 0; j < 4; j++ ){
	if ( !intersect( 0, 5.0, wall.x, wall.y[j], 0, i ) ){
	  T[i][j] = min( T[i][j], getDistance( 0, 5.0, wall.x, wall.y[j] ) );
	}
      }
    }
    if( !intersect( 0, 5.0, 10.0, 5.0, 0, N+1 ) ){
      finalPoint = min( finalPoint, 10.0 );
    }

    /* 1 --> N  --> final Point */
    for ( int source = 1; source <= N; source++ ){
      Wall sourceWall = W[source];
      for ( int target = source + 1; target <= N; target++ ){
	Wall targetWall = W[target];
	
	for ( int s = 0; s < 4; s++ ){
	  for ( int t = 0; t < 4; t++ ){
	    if ( !intersect( sourceWall.x, sourceWall.y[s], targetWall.x, targetWall.y[t], source, target ) ){
	      double cost = T[source][s] +  getDistance( sourceWall.x, sourceWall.y[s], targetWall.x, targetWall.y[t] );
	      T[target][t] = min( T[target][t], cost );
	    }
	  }
	}
      }
      for ( int s = 0; s < 4; s++ ){
	if ( !intersect( sourceWall.x, sourceWall.y[s], 10.0, 5.0, source, N + 1 ) ){
	  finalPoint = min( finalPoint, T[source][s] + getDistance( sourceWall.x, sourceWall.y[s], 10.0, 5.0 ) );
	}
      }
    }


    printf("%.2lf\n", finalPoint );
  }

  bool read(){
    cin >> N;
    if ( N == -1 ) return false;
    double x, y1, y2, y3, y4;
    for ( int i = 1; i <= N; i++ ){
      cin >> x >> y1 >> y2 >> y3 >> y4;
      Wall wall = Wall ( x, y1, y2, y3, y4 );
      W[i] = wall;
    }

    /* init */
    for ( int i = 1; i <= N; i++ ){
      for ( int j = 0; j < 4; j++ ){
	T[i][j] = INT_MAX;
      }
    }
    finalPoint = INT_MAX;
    return true;
  }

};

main(){
  TheDoors TD;
  while ( TD.read() ) TD.work();
}

// @end_of_source_code


