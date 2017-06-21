#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <cassert>

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
	double distance( const Point &p ) const {
		return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));
	}

	// 原点 (0, 0) からの距離を返す.
	double distance() const {
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
		return begin.distance(end);
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
		if ( !deq(distance(s.begin), 0) ) return false;
		if ( !deq(distance(s.end), 0) ) return false;
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
	double distance( const Point &p ) const {
		Segment r = Segment(begin, end);

		// 線分が点になっている場合は abort する.
		assert( !(begin == end) );

		// 線分に対して垂直かつ p を始点とする線分を作る.
		r.rotate(M_PI_2);
		r.move(p);

		return intersection(r).distance(p);
	}

	// 点と線分の最短距離.
	// 点が線分のどちらかの側面にあるならば, 点と直線の距離.
	// そうでないならば, 線分の両端点からの距離で短いもの.
	double shortest( const Point &p ) const {
		if ( above(p) ) return distance(p);
		return min(begin.distance(p), end.distance(p));
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


class Circle {
public:

	Point center;
	double radius;

	Circle( Point c=Point(0, 0), double r=0 ) {
		center = c, radius = r;
	}

	// 点が境界上を含まない円内に存在するか判定する.
	bool inside( const Point &p ) const {
		return (center.distance(p) < radius);
	}

	// 点が境界上に存在するか判定する.
	bool onframe( const Point &p ) const {
		return deq(center.distance(p), radius);
	}

	// 円周長.
	double perimeter() const {
		return M_PI * 2 * radius;
	}

	// 円の面積.
	double area() const {
		return M_PI * radius * radius;
	}

	// 原点から円に対して引いた接線を一つ返す.
	// 原点を円の内部に含まないこと.  円周上なら問題なし.
	// 得られた線分を 2*asin(radius / result.length()) 回転することで
	// 反時計回り方向の接線を得られる.
	Segment tangent() const {
		Segment result;

		const Point o = Point(0, 0);
		assert( !inside(o) );

		result = Segment(o, center);
		result.rotate(-asin(radius / result.length()));
	
		return result;
	}

};


class Triangle {
public:

	Point a, b, c;

	Triangle( Point p=Point(0, 0), Point q=Point(0, 0), Point r=Point(0, 0) ) {
		a = p, b = q, c = r;
	}

	// つぶれていない三角形かどうか判定する.
	bool valid() const {
		// つぶれていないとは 3 頂点が一直線上にならばないこと.
		return (a.direction(b, c) != PARALLEL);
	}

	// 三角形の面積.
	double area() const {
		// 内積を利用して求める.
		return fabs(((b.x-a.x) * (c.y-a.y) - (c.x-a.x) * (b.y-a.y)) / 2);
	}

	// 境界上を含まない三角形内に点が存在するか判定する.
	bool inside( const Point &p ) const {
		// つぶれた三角形に内側はない.
		if ( !valid() ) return false;

		if ( a.direction(b, c) != a.direction(b, p) ) return false;
		if ( b.direction(c, a) != b.direction(c, p) ) return false;
		if ( c.direction(a, b) != c.direction(a, p) ) return false;
		return true;
	}

	// 境界上に点が存在するか判定する.
	bool onframe( const Point &p ) const {
		if ( Segment(a, b).contain(p) ) return true;
		if ( Segment(b, c).contain(p) ) return true;
		if ( Segment(c, a).contain(p) ) return true;
		return false;
	}

	// 外接円の半径のみを計算.
	// 面積が定義できるつぶれていない三角形であること.
	double circumscribe() const {
		// 正弦定理 (a/sin(A) = 2R) を利用して求める.
		double bac = a.dangle(b, c);

		if ( bac > M_PI ) bac = 2*M_PI - bac;

		assert(sin(bac) != 0);
		return (b.distance(c) / sin(bac)) / 2;
	}

	// 外接円の半径と中心を計算し, Circle のインスタンスと
	// して生成する. 面積が定義できるつぶれていない三角形であること.
	Circle circumscribed() const {
		// 外接円の中心が 2 辺の垂直二等分線の交点として与えられることを利用する.
		Segment ab = Segment(a, b).bisector();
		Segment bc = Segment(b, c).bisector();

		assert( !ab.parallel(bc) );
		Point o = ab.intersection(bc);

		return Circle(o, o.distance(a));
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
	void translate( double dx, double dy ) {
		for ( int n = 0; n < pts.size(); n++ )
			pts[n].x += dx, pts[n].y += dy;

		for ( int m = 0; m < frame.size(); m++ ) {
			frame[n].begin.x += dx, frame[n].begin.y += dy;
			frame[n].end.x += dx, frame[n].end.y += dy;
		}
	}

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
		return ( p.distance(base) < q.distance(base) );
	}

private:

	Point base;

};


class ConvexHull {
public:

	void clear() {
		cvx.clear();
		pts.clear();
	}

	void push( Point &p ) {
		pts.push_back(p);
	}

	int size() {
		return cvx.size();
	}

	Point &operator [] ( int n ) {
		return cvx[n];
	}

	// Convex Hull アルゴリズムを実行し, pts から
	// とつ図形 cvx を生成する. 必要がなければ
	// 一連のコードを削除して問題ない.
	void compute() {
		assert( pts.size() >= 3 );
		grahamScan();
	}

	// 面積を計算する.
	double area() const {
		double result = 0.0;

		// とつ図形を基準点を含む三角形に分割して計算する.
		for ( int i = 2; i < (int)cvx.size() - 1; i++ )
			result += fabs((cvx[i-1].x-cvx[0].x)*(cvx[i].y-cvx[0].y) - (cvx[i].x-cvx[0].x)*(cvx[i-1].y-cvx[0].y));
		return result / 2;
	}

	// とつ図形の幾何学的重心を求める.
	Point gravity() const {
		Point result = Point(0.0, 0.0);
		double denom = 0.0;

		for ( int i = 2; i < (int)cvx.size() - 1; i++ ) {
			const double s = Triangle(cvx[0], cvx[i-1], cvx[i]).area();
			result.x += s * (cvx[i-1].x + cvx[i].x - 2 * cvx[0].x) / 3;
			result.y += s * (cvx[i-1].y + cvx[i].y - 2 * cvx[0].y) / 3;
			denom += s;
		}
		
		result.x = result.x / denom + cvx[0].x;
		result.y = result.y / denom + cvx[0].y;
		return result;
	}

	// 周上も含めて内側にあるか判定する.
	bool inside( const Point &p ) const {
		// 全ての辺に対して半時計周り方向または平行ならば良い (時計回りではないことと同値).
		// O(logn) のアルゴリズムに改良する余地がある (二分探索).
		for ( int i = 1; i < cvx.size(); i++ )
			if ( cvx[i-1].direction(cvx[i], p) == CLOCKWISE ) return false;
		return true;
	}

	// 周の全長を計算する.
	double perimeter() const {
		double result = 0.0;

		for ( int i = 1; i < cvx.size(); i++ )
			result += cvx[i].distance(cvx[i-1]);
		return result;
	}

private:

	vector<Point> pts, cvx;

	void grahamScan() {
		// 終端として始点を最後に追加しておく.
		grahamSort();
		pts.push_back(pts[0]);

		// グラハム走査本体
		cvx.push_back(pts[0]);
		cvx.push_back(pts[1]);

		for ( int i = 2; i < pts.size(); i++ ) {
			// この条件で 0 を入れると周上の直線に含まれる点を除くことができる.
			while ( cvx[cvx.size()-2].direction(cvx.back(), pts[i]) < 0 )
				cvx.pop_back();
			cvx.push_back(pts[i]);
		}
	}

	void grahamSort() {
		// 同一点を省き, Graham Scan を開始する基点を先頭にする.
		sort(pts.begin(), pts.end(), grahamLess);
		pts.erase(unique(pts.begin(), pts.end()), pts.end());

		sort(pts.begin(), pts.end(), AngleSortLess(pts.front()));
	}

	static bool grahamLess( const Point &p, const Point &q ) {
		if ( p.y < q.y ) return true;
		if ( p.y > q.y ) return false;
		return ( p.x < q.x );
	}

};


class SmallestEnclosingDisc {
public:

	void compute( vector<Point> &pts ) {
		assert(pts.size() >= 2);

		if ( pts.size() == 2 )
			smallest = Circle(Segment(pts[0], pts[1]).center(), pts[0].distance(pts[1]) / 2);
		else
			smallest = computeMiniDisc(pts);
	}

	Circle getSmallestDisc() const {
		return smallest;
	}

private:

	Circle smallest;

	Circle computeMiniDisc( vector<Point> pts ) {
		// random_shuffle をサポートしていない環境に注意せよ. (online は未対応)
		// 特にこれを実行しなくても効率に問題が生じるだけで実行は可能.
		random_shuffle(pts.begin(), pts.end());

		Circle D = Circle(Segment(pts[0], pts[1]).center(), pts[0].distance(pts[1]) / 2);
		for ( int n = 2; n < pts.size(); n++ )
			if ( !(D.inside(pts[n]) || D.onframe(pts[n])) )
				D = computeMiniDisc2(pts, n, pts[n]);
		return D;
	}

	Circle computeMiniDisc2( vector<Point> &pts, int npoint, Point &p ) {
		// random_shuffle をサポートしていない環境に注意せよ. (online は未対応)
		random_shuffle(pts.begin(), pts.begin()+npoint);

		Circle D = Circle(Segment(pts[0], p).center(), pts[0].distance(p) / 2);
		for ( int n = 1; n < npoint; n++ )
			if ( !(D.inside(pts[n]) || D.onframe(pts[n])) )
				D = computeMiniDisc3(pts, n, p, pts[n]);
		return D;
	}

	Circle computeMiniDisc3( vector<Point> &pts, int npoint, Point &p, Point &q ) {
		Circle D = Circle(Segment(p, q).center(), p.distance(q) / 2);
		for ( int n = 0; n < npoint; n++ )
			if ( !(D.inside(pts[n]) || D.onframe(pts[n])) )
				D = Triangle(p, q, pts[n]).circumscribed();
		return D;
	}

};

int main() {
	Circle C = Circle(Point(5, 5), 1);
	Segment tangent = C.tangent();
	Point house = Point(12, 12);

	cout << tangent.distance(house) << endl;

	return 0;
}
