#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 100000

class Point{
    public:
    int id, x, y, next_v, next_h, pxid, pyid;
    Point(){}
    Point(int id, int x, int y): id(id), x(x), y(y){
	next_v = next_h = -1;
    }
};

Point P[MAX], SPX[MAX], SPY[MAX];
int n, lowerLeft;

class cmpX{
    public:
    bool operator()(const Point &p1, const Point &p2){
	if ( p1.y == p2.y ) return p1.x < p2.x;
	else return p1.y < p2.y;
    }
};

class cmpY{
    public:
    bool operator()(const Point &p1, const Point &p2){
	if ( p1.x == p2.x ) return p1.y < p2.y;
	else return p1.x < p2.x;
    }
};

bool intersect( Point p1, Point p2, Point p3, Point p4 ){
    return ( (min(p1.x, p2.x) < p3.x && p3.x < max(p1.x, p2.x)) &&
		 (min(p3.y, p4.y) < p1.y && p1.y < max(p3.y, p4.y) ) );
}

bool parse( int pre, int cur, int dir, int depth ){
    if ( cur == -1 ) return false;
    if ( cur == lowerLeft ) return depth == n;
    
    if ( dir == 0 ){
	if ( parse( cur, P[cur].next_v, (dir+1)%2, depth + 1 ) ) return true;
    } else {
	if ( parse( cur, P[cur].next_h, (dir+1)%2, depth + 1 ) ) return true;
    }
    
    return false;
}

int compute(){
    if ( n % 2 == 1 ) return -1;

    int length = 0;

    sort( SPX, SPX + n, cmpX() );
    for ( int i = 0; i < n; i += 2 ){
	if ( SPX[i].y != SPX[i+1].y ) return -1;
	P[SPX[i].id].next_h = SPX[i+1].id;
	P[SPX[i+1].id].next_h = SPX[i].id;
	length += (SPX[i+1].x - SPX[i].x );
	P[SPX[i].id].pxid = i;
	P[SPX[i+1].id].pxid = i+1;
    }

    sort( SPY, SPY + n, cmpY() );
    for ( int i = 0; i < n; i += 2 ){
	if ( SPY[i].x != SPY[i+1].x ) return -1;
	P[SPY[i].id].next_v = SPY[i+1].id;
	P[SPY[i+1].id].next_v = SPY[i].id;
	length += (SPY[i+1].y - SPY[i].y );
	P[SPY[i].id].pyid = i;
	P[SPY[i+1].id].pyid = i+1;
    }

    if (!parse(lowerLeft, P[lowerLeft].next_h, 0, 1) ) return -1;
    
    for ( int i = 0; i < n; i+=2 ){
	int s = P[SPX[i].id].pyid;
	if ( s % 2 == 1 ) s++;
	int e = P[SPX[i+1].id].pyid;
	if ( e % 2 == 1 ) e--;
	for ( int j = s; j <= e; j+=2 ){
	    if ( intersect( SPX[i], SPX[i+1], SPY[j], SPY[j+1] ) ) return -1;
	}
    }
    
    return length;
}

void input(){
    scanf("%d", &n);
    int x, y;
    lowerLeft = 0;
    for ( int i = 0; i < n; i++ ) {
	scanf("%d %d", &x , &y);
	P[i] = SPX[i] = SPY[i] = Point(i, x, y);
	if ( P[i].y < P[lowerLeft].y ){
	    lowerLeft = i;
	} else if ( P[i].y == P[lowerLeft].y ){
	    if ( P[i].x < P[lowerLeft].x ){
		lowerLeft = i;
	    }
	}
    }
}

int main(){
    int tcase; scanf("%d", &tcase);
    for ( int i = 0; i < tcase; i++ ){
	input();
	printf("%d\n", compute());
    }
    return 0;
}

