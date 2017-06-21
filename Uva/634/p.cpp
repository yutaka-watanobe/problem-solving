#include<iostream>
#include<vector>
#include <algorithm>
#include <cfloat>
#include <cmath>
//#include <cstdlib>
//#include <cassert>

using namespace std;

#define M_PI 3.14159265358979323846
#define M_PI_2 1.57079632679489661923
#define M_PI_4 0.78539816339744830962

#define EPS DBL_EPSILON
#define deq(a, b) ( fabs((a)-(b)) < EPS )
#define dle(a, b) ( deq(a, b) || a < b )

// direction メソッド用
#define PARALLEL 0
#define CLOCKWISE (-1)
#define ANTI_CLOCKWISE 1

// intersect メソッド用
#define NOINTERSECT 0
#define ONPOINT 1
#define ONLINE 2

#define NIL (-1)

class Point {
public:

	double x, y;

	Point( double Xpos=0.0, double Ypos=0.0 ) {
		x = Xpos, y = Ypos;
	}

	bool operator == ( const Point &p ) const {
		return ( deq(x, p.x) && deq(y, p.y) );
	}

	bool operator < ( const Point &p ) const {
		if ( x < p.x ) return true;
		if ( x > p.x ) return false;
		return (y < p.y);
	}

	// 点 p との距離を返す.
	double dist( const Point &p ) const {
		return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));
	}

	// 原点 (0, 0) からの距離を返す.
	double dist() const {
		return sqrt(x*x + y*y);
	}

	// 点 o を原点とした場合, X 軸からの半時計回り方向の角度を返す.
	// 0 <= angle < 2pi
	double angle( const Point &o ) const {
		const double polar = atan2(y-o.y, x-o.x);

		// atan2 の結果範囲は -pi から pi までなので
		// それを 0 以上, 2pi 未満までの範囲にして返す.
		return (dle(0, polar))? polar : 2 * M_PI + polar;
	}

	// 原点を (0, 0) に取る場合の angle メソッドと同値.
	double angle() const {
		const Point o = Point(0, 0);
		return angle(o);
	}

	// 点 p との線分から, 点 q との線分への回転方向を返す.
	// 自点と点 p を通る直線上に点 q がのっていれ
	// ば PARALLEL となる. (たとえ反対方向でも)
	int direction( const Point &p, const Point &q ) const {
		const double r = (p.x-x) * (q.y-y) - (q.x-x) * (p.y-y);

		if ( deq(r, 0) )
			return PARALLEL;
		else
			return (r > 0)? ANTI_CLOCKWISE : CLOCKWISE;
	}

	// 点 p との線分を半時計回りにどれだけ回転すれば, 点 q との線分と
	// 重なるか計算する. 0 <= dangle < 2pi
	double dangle( const Point &p, const Point &q ) const {
		const double d = q.angle(*this) - p.angle(*this);
		return (d < 0)? d + 2 * M_PI : d;
	}

	// 点 o を原点として rad だけ半時計回りに回転した点に変更する.
	void rotate( const Point &o, const double rad ) {
		const double dx = x - o.x, dy = y - o.y;
		x = dx*cos(rad) - dy*sin(rad) + o.x;
		y = dx*sin(rad) + dy*cos(rad) + o.y;
	}

	// 原点を (0, 0) に取る場合の rotate メソッドと同値.
	void rotate( const double rad ) {
		Point o = Point(0, 0);
		rotate(o, rad);
	}

	// 点 o との距離を magnitude 倍するように移動する.
	void scale( const Point &o, const double magnitude ) {
		x = magnitude * (x - o.x) + o.x;
		y = magnitude * (y - o.y) + o.y;
	}

	// 原点を (0, 0) に取る場合の scale メソッドと同値.
	void scale( const double magnitude ) {
		Point o = Point(0, 0);
		scale(o, magnitude);
	}

	// 点 o を軸として点対称移動する.
	void symmetry( const Point &o ) {
		x -= 2 * (x - o.x);
		y -= 2 * (y - o.y);
	}

	// 0 に近い座標は 0 に落とす.
	void revise() {
		if ( deq(x, 0) ) x = 0;
		if ( deq(y, 0) ) y = 0;
	}

};


class Segment {
public:

	Point begin, end;

	Segment( Point p=Point(0, 0), Point q=Point(0, 0) ) {
		begin = p, end = q;
	}

	bool operator < ( const Segment &s ) const {
		if ( begin < s.begin ) return true;
		if ( begin == s.begin ) return (end < s.end);
		return false;
	}

	bool operator == ( const Segment &s ) const {
		return ( begin == s.begin && end == s.end );
	}

	// 線分長を返す.
	double length() const {
		return begin.dist(end);
	}

	// 線分の傾きを返す. begin を原点として end の angle をとる.
	double angle() const {
		return end.angle(begin);
	}

	// 点が線分を包む長方形内に存在するか判定する.
	bool inbox( const Point &p ) const {
		if ( min(begin.x, end.x) > p.x || max(begin.x, end.x) < p.x ) return false;
		if ( min(begin.y, end.y) > p.y || max(begin.y, end.y) < p.y ) return false;
		return true;
	}

	// 点が始点と終点を含む線分上に存在するか判定する.
	bool contain( const Point &p ) const {
		return (inbox(p) && begin.direction(end, p) == PARALLEL);
	}

	// 線分 s とインスタンス自身を直線と見なした場合に
	// 完全に重なるか判定する.
	bool overlap( const Segment &s ) const {
		if ( !deq(dist(s.begin), 0) ) return false;
		if ( !deq(dist(s.end), 0) ) return false;
		return true;
	}

	// 始点から終点方向での左側, 線分の垂直上方に点が存在するか判定する.
	bool onleft( const Point &p ) const {
		if ( begin.dangle(end, p) > M_PI/2 ) return false;
		if ( end.dangle(p, begin) > M_PI/2 ) return false;
		return true;
	}

	// 線分の垂直上方に点が存在するか判定する.
	bool above( const Point &p ) const {
		Point q = end, r = p;
		
		q.rotate(begin, -end.angle(begin));
		r.rotate(begin, -end.angle(begin));

		return ( r.x >= begin.x && r.x <= q.x );
	}

	// 始点と終点を交換する. (中点を支点とした 180 度回転と同じこと)
	void flip() {
		swap(begin, end);
	}

	// 始点を支点として線分を rad だけ半時計回りに回転する.
	// 終点のみが変更される.
	void rotate( const double rad ) {
		end.rotate(begin, rad);
	}

	// 始点を p まで移動する. 終点は適切に移動される.
	void move( const Point &p ) {
		end.x += p.x - begin.x;
		end.y += p.y - begin.y;
		begin = p;
	}

	// 始点と終点の距離を magnitude 倍にするように終点を変更する.
	void scale( const double magnitude ) {
		end.scale(begin, magnitude);
	}

	// 始点から終点方向での左側へ d だけ平行移動する.
	// d を負にすることで右側へ平行移動することが可能. 点は移動できない.
	void translate( const double d ) {
		Point p = end;

		p.rotate(begin, M_PI/2);
		p.scale(begin, d / length());
		move(p);
	}

	// 点と直線 (線分を含む直線) の距離.
	// 線分が点になっていないこと. 点になっている場合は abort する.
	double dist( const Point &p ) const {
		Segment r = Segment(begin, end);

		// 線分が点になっている場合は abort する.
		assert( !(begin == end) );

		// 線分に対して垂直かつ p を始点とする線分を作る.
		r.rotate(M_PI_2);
		r.move(p);

		return intersection(r).dist(p);
	}

	// 点と線分の最短距離.
	// 点が線分のどちらかの側面にあるならば, 点と直線の距離.
	// そうでないならば, 線分の両端点からの距離で短いもの.
	double shortest( const Point &p ) const {
		if ( above(p) ) return dist(p);
		return min(begin.dist(p), end.dist(p));
	}

	// 線分と線分の最短距離.
	// それぞれの両端点から, 線分への距離を取り, 最も短いもの
	// が最短距離となる.
	double shortest( const Segment &s ) const {
		double result = shortest(s.begin);
		result = min(result, shortest(s.end));
		result = min(result, s.shortest(begin));
		result = min(result, s.shortest(end));
		return result;
	}

	// 線分の中点を返す.
	Point center() const {
		return Point((begin.x+end.x)/2, (begin.y+end.y)/2);
	}

	// 垂直 2 等分線を返す.  始点を線分の中点にもち, 直交する
	// 線分をそれとみなしている.  特に長さなどは実装上, 元の
	// 線分と同じであるが, それを前提にした利用をしないこと.
	Segment bisector() const {
		Segment result = Segment(begin, end);

		result.move(center());
		result.rotate(M_PI_2);

		return result;
	}

	// 点から線分上に垂線を落とす. ただし, 直線として見なして垂線を
	// 落としているので, 必ずしも線分上とは限らない.
	Segment perpendicular( const Point &p ) const {
		Segment r = Segment(begin, end);

		assert( !(begin == end) );

		r.rotate(M_PI_2);
		r.move(p);
	
		return Segment(p, intersection(r));
	}

	// インスタンス自身を直線と見なした場合に点 p を線対称
	// 移動した点を返す.
	Point symmetry( const Point &p ) const {
		if ( contain(p) ) return p;

		Segment r = Segment(begin, end);

		r.rotate(M_PI_2);
		r.move(p);
		const Point q = intersection(r);

		Point result = p;
		result.rotate(q, M_PI);		

		return result;
	}

	// 線分 s と交差しているか判定する.
	int intersect( const Segment &s ) const {
		const int d1 = begin.direction(end, s.begin);
		const int d2 = begin.direction(end, s.end);
		const int d3 = s.begin.direction(s.end, begin);
		const int d4 = s.begin.direction(s.end, end);
		
		if ( d1 == PARALLEL && inbox(s.begin) ) return ONPOINT;
		if ( d2 == PARALLEL && inbox(s.end) ) return ONPOINT;
		if ( d3 == PARALLEL && s.inbox(begin) ) return ONPOINT;
		if ( d4 == PARALLEL && s.inbox(end) ) return ONPOINT;

		return ( d1 != d2 && d3 != d4 )? ONLINE : NOINTERSECT;
	}

	// 線分 s と平行か判定する.
	// 交点計算に用いる分母が 0 の場合に平行.
	// Computational Geometry in C
	bool parallel( const Segment &s ) const {
		double denom;

		// 文献のコードでは式を展開している. 精度が良いのか?
		denom = (end.x - begin.x) * (s.end.y - s.begin.y)
			- (end.y - begin.y) * (s.end.x - s.begin.x);
		return deq(denom, 0);
	}

	// 線分 s との交点を返す.
	// 線分 s と交わり, 平行でないことを確かめて実行すること.
	// 交わっていない場合も延長線上の交点を返すが, それは
	// 保証ではないので外部からは使うべきではない.
	// Computational Geometry in C
	Point intersection( const Segment &s ) const {
		double num, denom, r;
		
		num = (begin.y - s.begin.y) * (s.end.x - s.begin.x)
			- (begin.x - s.begin.x) * (s.end.y - s.begin.y);
		denom = (end.x - begin.x) * (s.end.y - s.begin.y)
			- (end.y - begin.y) * (s.end.x - s.begin.x);

		assert( ! deq(denom, 0) );
		r = num / denom;

		return Point(begin.x + r*(end.x - begin.x), begin.y + r*(end.y - begin.y));
	}

};




// 点を保持するのか, 辺を保持するのか, 形成後は固定する (constant)
// のかなど検討すること.
//
// UNDER DEVELOPMENT!!
class Polygon {
public:

	// 頂点の集合を与えて多角形を作成する.
	// ただし点はユニークにせよ. そうでなければ辺を点にしないように変更する
	// 必要がある.  面積などは問題ないが, 内外判定が働かなくなる.
	void build( vector<Point> &v ) {
		pts = v;

		// 辺の配列を作成する.  辺の配列と点の配列を同期させるために,
		// 点を後から追加することを禁止する.
		frame.clear();
		for ( int n = 1; n < pts.size(); n++ )
			frame.push_back(Segment(pts[n-1], pts[n]));
		frame.push_back(Segment(pts.back(), pts.front()));
	}

	const Point &operator [] ( int n ) const {
		return pts[n];
	}

	const int size() const {
		return pts.size();
	}

	// 多角形の面積を求める. 時計回りに格納しても半時計回りに格納
	// しても絶対値を取るので面積計算に差はない.  必ず非負の値になる.
	double area() const {
		double result = 0.0;

		for ( int n = 0; n < frame.size(); n++ )
			result += frame[n].begin.x * frame[n].end.y - frame[n].end.x * frame[n].begin.y;
		return fabs(result) / 2;
	}

	// 多角形を構成する全ての点を指定量だけシフトする. 多角形の平行移動
	// となる.
  /*
	void translate( double dx, double dy ) {
		for ( int n = 0; n < pts.size(); n++ )
			pts[n].x += dx, pts[n].y += dy;

		for ( int m = 0; m < frame.size(); m++ ) {
			frame[n].begin.x += dx; frame[n].begin.y += dy;
			frame[n].end.x += dx; frame[n].end.y += dy;
		}
		}*/

	// 境界上を含まない多角形内に点 p が存在するか判定する.
	// 頂点上の場合も考慮されないことに注意. 境界を含みたい場合には
	// onframe と併用すること.  inside の内部では境界上にあるか判定して
	// 利用している.
	bool inside( const Point &p ) const {
		if ( onframe(p) ) return false;

		// 境界上にないことが保証された.  ここで利用するアルゴリズムは
		// 境界の内側または外側にある場合を確実に判定し, 境界上の場合
		// は曖昧な結果しか与えられないものである.  ただし, ここでは境界上
		// にはないと保証しているので厳密に決定する.  文献の判定アルゴリズム
		// は曖昧さを排除できているが長いので, onframe との組み合わせで簡略化.
		// アルゴリズムのアイディアは点 p を通る X 軸に平行な直線の右側で
		// 多角形と交差する回数を判定するもの.
		// Computational Geometry in C
		bool outside = true;

		for ( int n = 0; n < frame.size(); n++ ) {
			const Point &begin = frame[n].begin;
			const Point &end = frame[n].end;

			if ( !(begin.y > p.y && dle(end.y, p.y))
				&& !(end.y > p.y && dle(begin.y, p.y)) ) continue;

			if ( p.x < (end.x - begin.x) * (p.y - begin.y) / (end.y - begin.y) + begin.x )
				outside = !outside;
		}
		return !outside;
	}

	// 多角形の境界上に点 p が存在するか判定する.
	bool onframe( const Point &p ) const {
		for ( int n = 0; n < frame.size(); n++ )
			if ( frame[n].contain(p) ) return true;
		return false;
	}

private:

	vector<Point> pts;
	vector<Segment> frame;

};

/*
class AngleSortLess {
public:

	AngleSortLess( Point &o ) {
		base = o;
	}

	bool operator () ( const Point &p, const Point &q ) const {
		double pa = p.angle(base);
		double qa = q.angle(base);

		if ( pa < qa ) return true;
		if ( pa > qa ) return false;
		return ( p.dist(base) < q.dist(base) );
	}

private:

	Point base;

	};*/




int n;
Polygon P;
Point target;

void work(){
  if ( P.inside( target ) ) cout << "T" << endl;
  else cout << "F" << endl;

}

bool read(){
  cin >> n;
  if ( n == 0 ) return false;

  vector<Point> pv;
  double x, y;

  for ( int i= 0; i < n; i++ ){
    cin >> x >> y;
    pv.push_back(Point(x, y));
  }
  P.build(pv);
  cin >> x >> y;
  target = Point(x, y);

  return true;
}

main(){
  while ( read() ) work();
}
