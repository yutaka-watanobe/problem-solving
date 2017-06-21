#include<iostream>
using namespace std;
#define MAX 100
#define LEFT 1
#define RIGHT (-1)
#define ONBACK (-1)
#define ONFRONT 1
#define ON 0

struct Point{ double x, y; };
struct Segment{ Point p1, p2; };

int crossProduct(Point p0, Point p1, Point p2){
    double dx1, dy1, dx2, dy2;
    dx1 = p1.x - p0.x; dy1 = p1.y - p0.y;
    dx2 = p2.x - p0.x; dy2 = p2.y - p0.y;
    if(dx1*dy2 > dy1*dx2) return LEFT; 
    if(dx1*dy2 < dy1*dx2) return RIGHT;
    if((dx1*dx2 < 0) || (dy1*dy2 < 0)) return ONBACK; /* p2--p0--p1 */
    if((dx1*dx1+dy1*dy1)<(dx2*dx2+dy2*dy2)) return ONFRONT; /* p0--p1--p3 */
    return ON; /* p0--p2--p1 */
}

int segments_intersect( Point p1, Point p2, Point p3, Point p4){
    return ((crossProduct(p1, p2, p3) * crossProduct(p1, p2, p4)) <= 0 &&
	    (crossProduct(p3, p4, p1) * crossProduct(p3, p4, p2)) <= 0 );
}

main(){
    int tcase, n; cin >> tcase;
    Segment S[MAX];
    for ( int t = 0; t < tcase; t++ ){
	cin >> n;
	for ( int i = 0; i < n; i++ ){
	    cin >> S[i].p1.x >> S[i].p1.y >> S[i].p2.x >> S[i].p2.y;
	}
	int total = 0;
	bool intersect;
	for ( int i = 0; i < n; i++ ){
	    intersect = false;
	    for ( int j = 0; j < n; j++ ){
		if ( i == j ) continue;
		if ( segments_intersect( S[i].p1, S[i].p2, S[j].p1, S[j].p2 )){
		    intersect = true; break;
		}
	    }
	    if ( !intersect ) total++;
	}
	cout << total << endl;
    }
}
