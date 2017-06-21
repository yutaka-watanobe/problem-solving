#include<stdio.h>
#include<cmath>
#include<iostream>

#define PI 3.14159265358979323846
using namespace std;

int length, angle, currentAngle;
double px, py;
 
void walk(){
    double dx = length * cos(currentAngle * PI / 180.0);
    double dy = length * sin(currentAngle * PI / 180.0);
    currentAngle -= angle;
    px += dx;
    py += dy;
}

main(){
    px = 0;
    py = 0;
    currentAngle = 90;
    while(1){
	scanf("%d,%d", &length, &angle);
	if ( length == 0 && angle == 0 ) break;
	walk();
    }
    int x = (int)px;
    int y = (int)py;
    printf("%d\n", x);
    printf("%d\n", y);
}
