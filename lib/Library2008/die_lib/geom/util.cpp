#include <complex>
#include <cmath>

using namespace std;

const double EPS = 1e-8;

#define NEAR(a, b) (fabs(a-b) < EPS)

typedef complex<double> Pt;
typedef complex<double> Vec;

// 外積
double cross(const Vec &v, const Vec &w){
  return imag(conj(v)*w);
}

// 内積
double dot(const Vec &v, const Vec &w){
  return real(conj(v)*w);
}

// 線分 pq 上に、c があるかどうか
// checked @uva634
bool onSegment(const Pt &p, const Pt &q,
               const Pt &c){
  if(NEAR(abs(p-c), 0) || NEAR(abs(q-c), 0)) // 端点上か
    return true;
  return (abs(c-p) <= abs(q-p) && dot(c-p, q-p) > 0);
  /*/
  return (fabs(cross(q-p, c-p)) < EPS &&
          (min(p.real(), q.real()) <= c.real() &&
           c.real() <= max(p.real(), q.real())) &&
          (min(p.imag(), q.imag()) <= c.imag() &&
           c.imag() <= max(p.imag(), q.imag())));
  //*/
}

// 線分 ab と線分 cd が交差しているかどうか
bool isIntersectSS(const Pt &a, const Pt &b,
                   const Pt &c, const Pt &d){
  if(cross(b-a, c-a) * cross(b-a, d-a) < 0 &&
     cross(d-c, a-c) * cross(d-c, b-c) < 0)
    return true;
  // 端点で交差しているか
  return (onSegment(a, b, c) || onSegment(a, b, d) ||
          onSegment(c, d, a) || onSegment(c, d, b));
}

// 直線 L1 = p + mv と直線 L2 = q + nw が交差しているかどうか
// しているならば、true を返し、r にその点を格納
// checked @uva634
bool isIntersectLL(const Pt &p, const Vec &v,
                   const Pt &q, const Vec &w,
                   Pt &r){
  Vec pq(q - p);
  double c = cross(v, w);
  double d = cross(pq, w);
  if(fabs(c) < EPS) // L1 and L2 are parallel
    if(fabs(d) < EPS) // L1 and L2 is same line
      r = q; // also p is valid
    else
      return false;
  else
    r = p + (d / c) * v;
  return true;
}

// 半直線 R = p + tv (t >= 0) と線分 (q, w) が交差しているか
// しているなら、r に交点を格納
// 精度が不安
// checked @uva634
// checked @pku3082
bool isIntersectRS(const Pt &p, const Vec &v,
                   const Pt &q, const Pt &r, Pt &s){
  Vec a(q-p), b(r-p);
  double c = cross(v, a), d = cross(v, b);
  if(c*d <= 0){
    if(c < 0) swap(a, b);
    if(fabs(arg(a/b) - (arg(a/v) + arg(v/b))) < EPS){
      assert(isIntersectLL(p, v, q, r-q, s));
      return true;
    }
  }
  return false;
}


// 円と直線が交差しているか
// C : |z-c|=r
// L : p + tv (t is scalar)
bool isIntersectCL(const Pt &p, Vec v,
                   const Pt &c, double r,
                   Pt &x, Pt &y){
  double a = norm(v), b = dot(p-c, v), g = norm(p-c) - r*r;
  double D = b*b - a*g;
  //  if(D < 0) return false;
  if(D < -EPS) return false;
  if(fabs(D) < EPS) D = 0;
  x = p + v * ((-b+sqrt(D))/a);
  y = p + v * ((-b-sqrt(D))/a);
  return true;
}

// ある点 p から円への接線の単位ベクトル
// FIXME v.imag() == 0 の時
void tangentPC(const Pt& p, const Pt& q, double r,
               Vec& w1, Vec& w2){
  Vec v(q - p);
  double vv = norm(v);
  double d = sqrt(vv - r*r);
  if(NEAR(v.imag(), 0)){
    w1 = normalize(Vec(v.real(), r));
    w2 = conj(w1);
  }
  else{
    w1.real() = (v.real()*d - v.imag()*r) / vv;
    w1.imag() = (d - v.real()*w1.real()) / v.imag();
    w2.real() = (v.real()*d + v.imag()*r) / vv;
    w2.imag() = (d - v.real()*w2.real()) / v.imag();
  }
}

// 円と円の交差判定
bool isIntersectCC(const Pt &c1, double r1,
                   const Pt &c2, double r2,
                   Pt &p, Pt &q){
  double a = c2.real() - c1.real(), b = c2.imag() - c1.imag();
  double X = (r2*r2 - r1*r1) - (a*a + b*b);
  double x1, y1, x2, y2;
  if(solveQuadFormula(4*(a*a + b*b), 4*a*X, X*X - 4*b*b*r1*r1, x1, x2)){
    assert(solveQuadFormula(4*(a*a + b*b), 4*b*X, X*X - 4*a*a*r1*r1, y1, y2));
    if(fabs(abs(Pt(x1, y1))-r1) > fabs(abs(Pt(x1, y2))-r1))
      swap(y1, y2);
    p = Pt(x1, y1) + c1;
    q = Pt(x2, y2) + c1;
    return true;
  }
  return false;
}

bool solveQuadFormula(double a, double b, double c,
                      double &x1, double &x2){
  double D = b*b - 4*a*c;
  if(D < 0) return false;

  x1 = (-b + sqrt(D)) / a / 2.0;
  x2 = (-b - sqrt(D)) / a / 2.0;
  return true;
}
