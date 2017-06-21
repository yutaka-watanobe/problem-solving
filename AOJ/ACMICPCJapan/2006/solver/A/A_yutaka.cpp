#include<iostream>
#include<cmath>
using namespace std;
#define SMAX 500
#define TMAX 50

struct Point{ double x, y, z; };
struct Star{ Point point; bool counted;};
struct Telescope{ Point center; double phi;};

int n, m;
Star stars[SMAX];
Telescope scopes[TMAX];

double getTheta( Point a, Point b ){
    return (a.x*b.x+a.y*b.y+a.z*b.z)/
    	(sqrt(a.x*a.x+a.y*a.y+a.z*a.z)*sqrt(b.x*b.x+b.y*b.y+b.z*b.z));
}

void compute(){
    int sum = 0;
    for ( int i = 0; i < m; i++ ){
	for ( int j = 0; j < n; j++ ){
	    if ( stars[j].counted ) continue;
	    double theta = acos(getTheta(stars[j].point, scopes[i].center));
	    if ( scopes[i].phi > theta && !stars[j].counted ){
		sum++; stars[j].counted = true;
	    }
	}
    }
    cout << sum << endl;
}

bool input(){
    cin >> n;
    if ( n == 0 ) return false;
    for ( int i = 0; i < n; i++ ){
	cin >> stars[i].point.x >> stars[i].point.y >> stars[i].point.z;
	stars[i].counted = false;
    }
    cin >> m;
    for ( int i = 0; i < m; i++ ){
	cin >> scopes[i].center.x >> scopes[i].center.y >> scopes[i].center.z 
	    >> scopes[i].phi;
    }
    return true;
}

main(){
    while( input() ) compute();
}
