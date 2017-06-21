#include<iostream>
#include<cmath>
#define MAX 1000

using namespace std;

struct Point{
    double x, y;
};

/**
 * 水平線からの角度 (degree)
 */
double getRealTheta(Point p1, Point p2){
  double k;
  double dx, dy;

  dx = p2.x - p1.x;
  dy = p2.y - p1.y;

  if( dx == 0 ){
    if( dy > 0 ) return 90;
    else  return 180+90;
  }

  k = atan( dy/dx )/ M_PI * 180;
  if( dx < 0 ) k += 90 + 90;
  else if( dy < 0 ) k += 90 + 180 + 90;

  return k;
}

Point polygon[MAX];
int size;

int giftWrapping(){
    int minIndex = 0;
    double theta;
    double currentAngle;
    int cvxSize;

    for ( int i = 0; i < size; i++ ){
	if ( polygon[i].y < polygon[minIndex].y ||
	     (polygon[i].y == polygon[minIndex].y && polygon[i].x > polygon[minIndex].x) ) minIndex = i;
    }

    polygon[size] = polygon[minIndex]; theta = 0.0;

    for ( cvxSize = 0; cvxSize < size; cvxSize++ ){
	Point tmp = polygon[cvxSize]; polygon[cvxSize] = polygon[minIndex]; polygon[minIndex] = tmp;
	minIndex = size; currentAngle = theta; theta = 360.0;

	for ( int i = cvxSize + 1; i <= size; i++ ){
	    double currentTheta = getRealTheta(polygon[cvxSize], polygon[i]);
	    if ( currentTheta > currentAngle && currentTheta < theta ){
		minIndex = i; theta = currentTheta;
	    }
	}
	if ( minIndex == size ) return cvxSize + 1;
    }
}

void work(){
    int n = giftWrapping();
    for (  int i = 0; i < n; i++ ){
	cout << polygon[i].x << " " << polygon[i].y << endl;
    }
}

void read(){
    size = 0;
    double x, y;
    Point point;
    while ( cin >> x >> y ){
	point.x = x; point.y = y;
	polygon[ size++ ] = point;
    }
}

int main(){
    read();
    work();

    return 0;
}
