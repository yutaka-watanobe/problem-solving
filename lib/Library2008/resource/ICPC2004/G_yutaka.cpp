#include<iostream>
#include<string>
#include<map>
#define PMAX 100
#define TMAX 100
#define CMAX 10
using namespace std;

struct Point{ double x, y;};

class Territory{
    public:
    int npoint;
    string cname;
    Point points[PMAX];
    Territory(){}
    Territory(string cname):cname(cname){ npoint = 0; }

    void addPoint( int x, int y ){ 
	points[npoint].x = x;
	points[npoint++].y = y;
    }
};

int ncountry, nterritory;
Territory T[TMAX];
map<string, int> M; /* name to id */
bool G[CMAX][CMAX]; /* graph */

bool overlap( Point p1, Point p2, Point p3, Point p4 ){
    if ( (p2.x-p1.x)*(p4.y-p3.y) != (p2.y-p1.y)*(p4.x-p3.x) ) return false;
    if ( (p2.x - p1.x)*(p3.y-p1.y) != (p2.y - p1.y)*(p3.x-p1.x) ) return false;
    if ( p1.x != p2.x ){
	if ( max(p1.x, p2.x) <= min(p3.x, p4.x) ||
	     min(p1.x, p2.x) >= max(p3.x, p4.x) ) return false;
    }
    if ( p1.y != p2.y ){
	if ( max(p1.y, p2.y) <= min(p3.y, p4.y) ||
	     min(p1.y, p2.y) >= max(p3.y, p4.y) ) return false;
    }
    return true;
}

bool isAdj( Territory t1, Territory t2 ){
    for ( int i = 0; i < t1.npoint; i++ ){
	for ( int j = 0; j < t2.npoint; j++ ){
	    if ( overlap( t1.points[i], t1.points[(i+1)%t1.npoint],
			  t2.points[j], t2.points[(j+1)%t2.npoint] ) ){
		return true;
	    }
	}
    }
    return false;
}

void makeGraph(){
    for ( int i = 0; i < ncountry; i++ ){
	for ( int j = 0; j < ncountry; j++ ) G[i][j] = false;
    }
    for ( int i = 0; i < nterritory; i++ ){
	for ( int j = 0; j < nterritory; j++ ){
	    if ( T[i].cname == T[j].cname ) continue;
	    if ( isAdj( T[i], T[j] ) ){
		G[M[T[i].cname]][M[T[j].cname]] = true;
		G[M[T[j].cname]][M[T[i].cname]] = true;
	    }
	}
    }
}

int color[CMAX], mincolor;
bool used[CMAX+1];

void recursive( int pos, int ncolor ){
    if ( pos == ncountry ){
	mincolor = min( mincolor, ncolor );
	return;
    }
    if ( ncolor >= mincolor ) return;

    bool usedt;
    for ( int c = 1; c <= ncountry; c++ ){
	for ( int v = 0; v < ncountry; v++ ){
	    if ( G[pos][v] && color[v] == c ) goto nextcolor;
	}
	usedt = used[c];
	used[c] = true;
	color[pos] = c;
	recursive( pos + 1, usedt ? ncolor : ncolor+1 );
	used[c] = usedt;
    nextcolor:;
    } 
}

void compute(){
    makeGraph();
    for ( int i = 0; i <= ncountry; i++ ) used[i] = false;
    for ( int i = 0; i < ncountry; i++ ) color[i] = -1;
    mincolor = ncountry;
    recursive(0, 0);
    cout << mincolor << endl;
}

bool input(){
    ncountry = 0;
    M = map<string, int>();
    string cname;
    int x, y;
    cin >> nterritory;
    if ( nterritory == 0 ) return false;
    for ( int i = 0; i < nterritory; i++ ){
	cin >> cname;
	if ( M.find(cname) == M.end() ) M[cname] = ncountry++;
	T[i] = Territory(cname);
	while( cin >> x, x != -1 ){
	    cin >> y;
	    T[i].addPoint(x, y);
	}
    }
    return true;
}

main(){
    while( input() ) compute();
}
