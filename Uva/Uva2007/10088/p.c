// @JUDGE_ID:  17051CA  10088  C++
// @begin_of_source_code
/* Geometory Pick's theorem */
/* S = ( c - 1 ) + b / 2 */
/* c = S - b/2 + 1 */
/* S --> area */
/* b --> number of edge point ( include points ) */
/* c --> number of internal point */
#include<stdio.h>
#include<stdlib.h>
#include<stl.h>
#include<cmath>
#include<float.h>
#include<iostream>
#include<vector>
typedef long long llong;

class point{
 public:
  llong x, y;
  point(int x, int y ): x(x), y(y){}
};

/**
 * polygon の面積
 */
double getPolygonArea(vector<point> p){
  double sum = 0;
  for(int i=0; i<p.size()-1; i++){
    sum += p[i].x*p[i+1].y - p[i+1].x*p[i].y;
  }
  sum += p[p.size()-1].x*p[0].y - p[0].x*p[p.size()-1].y;
  return abs(sum/2.0);
}

/*
 * 最大公約数 (Greatest Common Divisor)
 * a > b > 0 を保証すること。
 * 要件: なし
 */
llong gcd(llong a, llong b){
  llong tmp;

  if(a<b) swap(a, b);

  while(b){
    a %= b;
    tmp = a;
    a = b;
    b = tmp;
  }

  return a;
}

int N;
vector< point > P;

int read(){
  cin >> N;
  if ( N == 0 ) return 0;
  P.clear();
  int x, y;
  for ( int i = 0; i < N; i++ ){
    cin >> x  >> y;
    P.push_back( point( x,  y ) );
  }

  return 1;
}

llong getEdgePoint( point p1, point p2 ){
  llong dx, dy;
  dx = max( p1.x, p2.x ) - min( p1.x, p2.x );
  dy = max( p1.y, p2.y ) - min( p1.y, p2.y );

  if ( dx != 0 && dy != 0 ) return gcd( dx, dy ) - 1;
  else if ( dx == 0 && dy != 0 ) return dy - 1;
  else if ( dx != 0 && dy == 0 ) return dx - 1;
}

void work(){
  double S = getPolygonArea( P );
  llong edge; 
  llong size = P.size();
  edge = 0;

  for ( int i = 0; i < size; i++ ){
    edge += getEdgePoint( P[i], P[(i+1)%size] );
  } 

  edge += N;

  llong c = (llong)S - edge/2 + 1;

  cout << c << endl;
}

main(){
  while ( read() ) work();
}
// @end_of_source_code

