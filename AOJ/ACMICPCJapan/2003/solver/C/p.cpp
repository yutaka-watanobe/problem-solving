#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>
#include<cmath>
using namespace std;

#define MAX 100
#define SHIFT 2000
#define EPS 0.00000001

class Point{
    public:
    double x, y;
    Point(){}
    Point(int x, int y):x(x), y(y){}
};

class Segment{
    public:
    int left, right;
    Segment(){}
    Segment( int left, int right ): left(left), right(right){}

    bool operator < ( const Segment &s ) const{
	if ( left == s.left ) return right < s.right;
	else return left < s.left;
    }
};

int n;
Point P[MAX+1];
int minY, maxY;

double getX( Point p1, Point p2, int y ){
    assert( p1.y != p2.y );
    return 1.0*(p2.x - p1.x)*(y - p1.y)/(p2.y - p1.y) + p1.x;
}

void compute(){
    int total = 0;

    for ( int y = minY; y <= maxY - 1; y++ ){
	vector<Segment> targets;
	for ( int i = 0; i < n; i++ ){
	    if ( P[i].y <= y && P[i+1].y <= y ||
		 P[i].y >= y+1 && P[i+1].y >= y+1 ) continue;
	    double x1, x2;
	    int left, right;
	    x1 = getX(P[i], P[i+1], y);
	    x2 = getX(P[i], P[i+1], y+1);
	    left = (int)(min( x1, x2 ));
	    right = (int)(max( x1, x2 ) + 1 - EPS);
	    targets.push_back( Segment( left, right ) );
	}

	assert( targets.size() % 2 == 0 );
	sort ( targets.begin(), targets.end() );

	int prev = 0;
	for ( int i = 0; i < targets.size(); i += 2 ){
	    total += targets[i+1].right - max( targets[i].left, prev );
	    prev = targets[i+1].right;
	}
    }

    cout << total << endl;
}

bool input(){
    cin >> n;
    if ( n == 0 ) return false;
    int x, y;
    minY = 2001;
    maxY = -2001;

    for ( int i = 0; i < n; i++ ){
	cin >> x >> y;
	x += SHIFT; y += SHIFT;
	minY = min( minY, y );
	maxY = max( maxY, y );
	P[i] = Point(x, y);
    }
    P[n] = P[0];

    return true;
}

main(){
    while( input() ) compute();
}
