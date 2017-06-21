#include<stdio.h>
#include<iostream>
#include<cfloat>
#include<climits>
#include<algorithm>
#define MAX 10001
typedef long long llong;

int N;

class Point{
public:
  double x, y;
  Point(){}
  Point ( double x, double y ): x(x), y(y){}

  bool operator < ( const Point &p ) const{
    if ( p.y == y ){
      return x < p.x;
    } else {
      return y < p.y;
    }
  }
};

Point P[MAX];

void work(){
  if ( N == 1 ){
    printf("INFINITY\n");
    return;
  }

  sort( P, P + N );

  double minLength = DBL_MAX;
  double cdx, cdy;

  Point source, target;
  double dx, dy, length;
  for ( int i = 0; i < N - 1; i++ ){
    source = P[i];
    for ( int j = i + 1; j < N; j++ ){
      
      target = P[j];

      dy = target.y - source.y;

      if ( dy*dy > minLength ) goto next;
      
      if ( source.x < target.x ){
	dx = target.x - source.x;
      } else {
	dx = source.x - target.x;
      }

      if ( dx*dx <= minLength ){
	length = dx*dx + dy*dy;
	if ( minLength > length ){
	  minLength = length;
	  cdx = dx;
	  cdy = dy;
	}
      }
    }

  next:;
  }


  double closest =  cdx*cdx + cdy*cdy ;


  if ( closest < 100000000 ){
    printf("%.4lf\n", sqrt( closest ));
  } else {
    printf("INFINITY\n");
  }
}

main(){
  double x, y;
  while(1){
    scanf("%d", &N);
    if ( N == 0 ) break;
    for ( int i = 0; i < N; i++ ){
      scanf("%lf %lf", &x, &y);
      P[i] = Point(x, y);
    }
    work();
  }
}
