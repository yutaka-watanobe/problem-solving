#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;

struct Line{
    bool isRightX, isRightY;
    double x, y, a, b;
};

Line getBisector(double x1, double y1, double x2, double y2){
    Line bisector;
    bisector.isRightX = bisector.isRightY = false;
    if ( y1 == y2 ){   
	bisector.isRightY = true;
	bisector.x = ( x1 + x2 ) / 2;
    } else if ( x1 == x2 ){    
	bisector.isRightX = true;
	bisector.y = ( y1 + y2 ) / 2;
    } else {
	bisector.a = ( x2 - x1 ) / ( y1 - y2 );
	bisector.b = ( y1 + y2 ) / 2 - bisector.a * (( x1 + x2 ) / 2);
    }

    return bisector;
}

void compute(){
    double x1, y1, x2, y2, x3, y3, x, y, r;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    Line AB = getBisector(x1, y1, x2, y2);
    Line AC = getBisector(x1, y1, x3, y3);
    if ( AB.isRightX ){
	if ( AC.isRightY ){
	    x = AC.x; y = AB.y;
	} else {
	    y = AB.y; x = (y - AC.b) / AC.a;
	}
    } else if ( AB.isRightY ){ //y ¼´¤ËÊ¿¹Ô
	if ( AC.isRightX ){
	    x = AB.x; y = AC.y;
	} else {
	    x = AB.x; y = AC.a * x + AC.b;
	}
    } else {
	if ( AC.isRightX ) {
	    y = AC.y; x = (y - AB.b) / AB.a;
	} else if ( AC.isRightY ) {
	    x = AC.x; y = AB.a * x + AB.b;			
	} else {
	    x = (AC.b - AB.b) / (AB.a - AC.a); 
	    y = AB.a * x + AB.b;
	}	
    }
    r = sqrt( (x - x1)*(x - x1) + (y - y1)*(y - y1) );

    printf("%.3lf %.3lf %.3lf\n", x, y, r);
}

int main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	compute();
    }
    return 0;
}

