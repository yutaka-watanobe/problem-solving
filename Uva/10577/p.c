// @JUDGE_ID:  17051CA  10577  C++
// @begin_of_source_code
/* 数学 と 幾何学 */
/* 精度が怪しい */
#include<stdio.h>
#include<cmath>
#include<stl.h>
#include<float.h>
#include<climits>
#define INCLUDE_POINT
#define EPS DBL_EPSILON
#define M_PI 3.14159265358979323846
#define deq(a, b) (fabs(a-b) < EPS)
#define dlt(a, b) (!deq(a, b) && a<b)
#define dle(a, b) (deq(a, b) || a<b)

class point{
 public:
  double x, y;
  point(){}
  point(double x, double y): x(x), y(y){}
  point operator+(const point &p) const{ return point(x+p.x, y+p.y); }
  point operator-(const point &p) const{ return point(x-p.x, y-p.y); }
  point operator*(double a) const{ return point(a*x, a*y); }
  double operator*(const point &p) const{ return x*p.y - y*p.x; }
};

class BoundingBox{
 public:
  int n;
  double x1, y1, x2, y2, x3, y3;
  double cx, cy;
  double minX, maxX, minY, maxY;
  
  point intersection(point p1, point p2, point p3, point p4){
    double num, denom, r;
    
    num = (p1.y - p3.y) * (p4.x - p3.x)
      - (p1.x - p3.x) * (p4.y - p3.y);
    denom = (p2.x - p1.x) * (p4.y - p3.y)
      - (p2.y - p1.y) * (p4.x - p3.x);
    
    assert( ! deq(denom, 0) );
    r = num / denom;
    
    return point(p1.x + r*(p2.x - p1.x), p1.y + r*(p2.y - p1.y));
  }

  void rotate( double x, double y, double &xx, double &yy, double rad ){
    double tx, ty;
    tx = xx - x;
    ty = yy - y;

    xx = tx*cos( rad ) - ty*sin( rad );
    yy = tx*sin( rad ) + ty*cos( rad );
    
    xx += x;
    yy += y;
  }

  void computeCenter(){
    double m, l, a, b, c, d, a2, b2, c2, d2;
    a = (x1+x2)/2;
    b = (y1+y2)/2;
    c = (x2+x3)/2;
    d = (y2+y3)/2;
    
    a2 = x2, b2 = y2;
    c2 = x2, d2 = y2;

    rotate( a, b, a2, b2, M_PI/2);
    rotate( c, d, c2, d2, M_PI/2);
    
    point center = intersection( point(a, b), point(a2, b2),
				 point(c, d), point(c2, d2));

    cx = center.x;
    cy = center.y;
  }

  void work(){
    computeCenter();
    
    minX = 1000000000.0;
    maxX = -1000000000.0;
    minY = 1000000000.0;
    maxY = -1000000000.0;
    
    double currentX, currentY, x, y;
    currentX = x1;
    currentY = y1;
    double dr = 2*M_PI/n;

    update( currentX, currentY );

    for ( int i = 0; i < n; i++ ){
      //      cout << currentX << ".  " << currentY << endl;
      rotate( cx, cy, currentX, currentY, dr);
      update( currentX, currentY );
    }

    /*
    printf("%.3lf\n", minX );
    printf("%.3lf\n", maxX );
    printf("%.3lf\n", minY );
    printf("%.3lf\n", maxY );
    */
    double area = ( maxX - minX ) * ( maxY - minY );

    printf("%.3lf\n", area );
  }

  void update( double x, double y ){
    maxX = max( maxX, x );
    minX = min( minX, x );
    maxY = max( maxY, y );
    minY = min( minY, y );
  }

  bool read(){
    cin >> n;
    if ( n == 0 ) return false;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    return true;
  }
};

main(){
  BoundingBox BB;
  for ( int i = 1; BB.read(); i++ ){
    printf("Polygon %d: ", i );
    BB.work();
  }
}


// @end_of_source_code


