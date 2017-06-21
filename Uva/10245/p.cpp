// Good Performance!! 0.46 sec
// Sort + BF 
#include<stdio.h>
#include<iostream>
#include<cfloat>
#include<climits>
#include<algorithm>
#define MAX 10001
typedef long llong;

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
int next[MAX];

void computeNext(){
  next[N-1] = N-1;
  for ( int pos = N-1; pos >=0; pos-- ){
    if ( P[pos].y == P[pos+1].y ){
      next[pos] = next[pos+1];
    } else {
      next[pos] = pos+1;
    }
  }
}

void work(){
  if ( N == 1 ){
    printf("INFINITY\n");
    return;
  }

  sort( P, P + N );

  computeNext();

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
	// x 軸方向へこれ以上調べても無意味なとき,next[]によって飛ぶ
	if ( dx*dx > minLength ){
	  j = next[ j ];
	  j--;
	}
      } else {
	dx = source.x - target.x;
      }

      length = dx*dx + dy*dy;
      if ( minLength > length ){
	minLength = length;
      }
    }

  next:;
  }

  if ( minLength < 100000000 ){
    printf("%.4lf\n", sqrt( minLength ));
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
