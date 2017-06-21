// @JUDGE_ID:  17051CA  221  C++
// @begin_of_source_code
#include<stdio.h>
#include<vector>
#include<stl.h>
#include<cmath>
#include<climits>
#include<iostream>
#include<cfloat>
#define MAX 102
#define EPS 0.000001
#define deq(a, b) (fabs(a-b) < EPS)

class Building{
 public:
  int id;
  double x, y, width, depth, height, left, right;
  Building(){}
  Building(int id, double x, double y, double width, double depth, double height):
    id(id), x(x), y(y), width(width), depth(depth), height(height){
    left = x;
    right = x + width;
  }
};

bool comp_y_x( const Building &b1, const Building &b2 ){
  if( deq( b1.y, b2.y ) ) return b1.x < b2.x;
  else return b1.y < b2.y;
}

bool comp_x_y( const Building &b1, const Building &b2 ){
  if( deq( b1.x, b2.x ) ) return b1.y < b2.y;
  else return b1.x < b2.x;
}

class  UrbanElevations{
 public:
  int n;
  Building B[MAX];
  bool V[MAX+1];

  bool intersect( Building target, double left, double right, double height, double &tleft, double &tright ){
    if ( fabs(target.height-height) < EPS || target.height < height ) return false;

    if ( (left < target.left && target.left < right) ||
	 (left < target.right && target.right < right) ||
	 target.left < right && right < target.right ||
	 target.left < left && left < target.right ||
	 (fabs(left-target.left) < EPS && fabs(right-target.right) < EPS) ){
      tright = min( target.right, right );
      tleft = max( target.left, left );
      return true;
    }

    return false;
  }

  void recursive( int pos, double left_most, double right_most, double lower ){
    if ( right_most < left_most || fabs(right_most-left_most) < EPS ) return;
    if ( pos >= n ) return;

    Building target = B[pos];
    double tleft, tright;

    if ( intersect( target, left_most, right_most, lower, tleft, tright ) ){
      V[target.id] = true;
      recursive( pos+1, left_most, tleft, lower );
      recursive( pos+1, tleft, tright, target.height );
      recursive( pos+1, tright, right_most, lower );
    } else {
      recursive( pos+1, left_most, right_most, lower );
    }
  }

  void init(){
    for ( int i = 0; i < n+1; i++ ) V[i] = false;
  }

  void work(){
    sort( B, B + n, comp_y_x );
    init();

    recursive( 0, INT_MIN, INT_MAX, INT_MIN );

    sort( B, B + n, comp_x_y );

    bool isfirst = true;
    for ( int i = 0; i < n; i++ ){
      if ( V[ B[i].id ] ) {
	//	if ( !isfirst ) printf(" ");
	printf("%d ", B[i].id );
	//	isfirst = false;
      }
    }

    printf("\n");
  }

  bool read(){
    double x, y, width, depth, height;
    scanf("%d", &n);
    if ( n == 0 ) return false;
    for ( int i = 0; i < n ;i++ ){
      scanf("%lf %lf %lf %lf %lf", &x, &y, &width, &depth, &height);
      B[i] = Building(i+1, x, y, width, depth, height );
    }
    return true;
  }

};


main(){
  UrbanElevations UE;
  for ( int i = 0; UE.read(); i++  ){
    //    if ( i ) printf("\n");
    printf("For map #%d, the visible buildings are numbered as follows:\n", i+1);
    UE.work();
    printf("\n");
  }
}

// @end_of_source_code


