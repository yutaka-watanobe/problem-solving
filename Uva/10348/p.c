// @JUDGE_ID:  17051CA  10348  C++
// @begin_of_source_code

#include<iostream>
#include<vector>
#include<cfloat>
#include<algorithm>
#include<cassert>
#define WATER -1
#define EPS DBL_EPSILON
#define deq(a, b) ( fabs((a)-(b)) < EPS )
#define dle(a, b) ( deq(a, b) || a < b )

class Point{
    public:
    double x, y;
    Point(){}
    Point( double x, double y ): x(x), y(y){}
};

class Polygon{
    public:
    vector<Point> v;

    Polygon(){
	v.clear();
    }
};

class Segment{
    public:
    Point head, tail;
    Segment(){}
    Segment(Point head, Point tail): head(head), tail(tail){}
};

using namespace std;


Polygon lands[51];
Segment ships[101];

int nship, nland;

int direction(Point pi, Point pj, Point pk){
  /* (pk - pi)*(pj - pi) */
  return (int)((pk.x - pi.x)*(pj.y - pi.y) - (pj.x - pi.x)*(pk.y - pi.y));
}

bool on_segment(Point pi, Point pj, Point pk){
  if( min(pi.x, pj.x) <= pk.x && pk.x <= max(pi.x, pj.x) &&
      min(pi.y, pj.y) <= pk.y && pk.y <= max(pi.y, pj.y)) return true;
  else return false;
}

int segments_intersect(const Point &p1, const Point &p2, 
		 const Point &p3, const Point &p4){
  int d1, d2, d3, d4;
  bool on1, on2, on3, on4;

  d1 = direction(p3, p4, p1);
  d2 = direction(p3, p4, p2);
  d3 = direction(p1, p2, p3);
  d4 = direction(p1, p2, p4);

  on1 = on_segment(p3, p4, p1);
  on2 = on_segment(p3, p4, p2);
  on3 = on_segment(p1, p2, p3);
  on4 = on_segment(p1, p2, p4);

  if( ((d1>0 && d2<0)||(d1<0 && d2>0)) &&
      ((d3>0 && d4<0)||(d3<0 && d4>0)) ) return true;
  else if( d1==0 && on1 ) return true;
  else if( d2==0 && on2 ) return true;
  else if( d3==0 && on3 ) return true;
  else if( d4==0 && on4 ) return true;
  else return false;
}

bool isIntersect( Segment seg ){
    for ( int i = 0; i < nland; i++ ){
	Polygon land = lands[i];

	for ( int j = 0; j < land.v.size(); j++ ){
	    Point p1 = land.v[j];
	    Point p2 = land.v[(j+1)%land.v.size()];

	    if ( segments_intersect( p1, p2, seg.head, seg.tail ) ) return true;
	}
    }
    return false;
}

// 境界上を含まない多角形内に点 p が存在するか判定する.
// 頂点上の場合も考慮されないことに注意. 境界を含みたい場合には
// onframe と併用すること.  inside の内部では境界上にあるか判定して
// 利用している.
bool inside( Polygon pol,  Point p )  {
    //if ( onframe(p) ) return false;

    // 境界上にないことが保証された.  ここで利用するアルゴリズムは
    // 境界の内側または外側にある場合を確実に判定し, 境界上の場合
    // は曖昧な結果しか与えられないものである.  ただし, ここでは境界上
    // にはないと保証しているので厳密に決定する.  文献の判定アルゴリズム
    // は曖昧さを排除できているが長いので, onframe との組み合わせで簡略化.
    // アルゴリズムのアイディアは点 p を通る X 軸に平行な直線の右側で
    // 多角形と交差する回数を判定するもの.
    // Computational Geometry in C
    bool outside = true;

    int size = pol.v.size();

    for ( int n = 0; n < size ; n++ ) {
	const Point begin = pol.v[n];
	const Point end = pol.v[(n+1)%size];
	
	if ( !(begin.y > p.y && dle(end.y, p.y))
	     && !(end.y > p.y && dle(begin.y, p.y)) ) continue;
	
	if ( p.x < (end.x - begin.x) * (p.y - begin.y) / (end.y - begin.y) + begin.x )
	    outside = !outside;
    }
    return !outside;
}

int getID( Point p ){
    
    for ( int i = 0; i < nland; i++ ){
	
	Polygon pol = lands[i];
	if ( inside( pol, p ) ) return i;
    }
    return WATER;
}


void work(){
    for ( int i = 0; i < nship; i++ ){
	cout << "Submarine " << i+1 << " is";
	Segment ship = ships[i];

	int headID, tailID;
	headID = getID( ship.head );
	tailID = getID( ship.tail );

	if ( isIntersect( ship ) ){
	    cout << " partially on land." << endl;
	} else if ( headID == tailID ){
	    if ( headID == WATER ){
		cout << " still in water." << endl;
	    } else {
		cout << " completely on land." << endl;
	    }
	} else {
	  assert(false);
	}
    }
}


void read(){
    cin >> nship;
    for ( int i = 0; i < nship; i++ ){
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	ships[i] = Segment(Point(x1, y1), Point(x2, y2));
    }
    cin >> nland;
    for ( int i = 0; i < nland; i++ ){
	Polygon land;
	int n; cin >> n;
	for ( int j = 0; j < n; j++ ){
	    double x1, y2;
	    cin >> x1 >> y2;
	    land.v.push_back( Point(x1, y2) );
	}
	
	lands[i] = land;
    }
}

main(){
    read();
    work();
}
// @end_of_source_code
