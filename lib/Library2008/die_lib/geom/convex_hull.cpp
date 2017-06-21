#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<Pt> Poly;

// y -> x で比較
bool yxCmp(const Pt &p, const Pt &q){
  if(p.imag() == q.imag()) return p.real() < q.real();
  return p.imag() < q.imag();
}

bool isRightTurn(const Pt &o, const Pt &p, const Pt &q){
  return cross(p-o, q-o) < 0;
}

// ある点 o を中心として、2 点をその極角で比較
class PolarAngleCmp {
private:
  Pt o;

public:

  PolarAngleCmp(const Pt &o) : o(o){
  }

  bool operator()(const Pt &p, const Pt &q) const {
    Vec v(p-o), w(q-o);
    int c = cross(v, w);
    if(c == 0)
      if(o.real() == p.real())
        if(o.imag() == p.imag() || o.imag() == q.imag())
          return abs(v) < abs(w);
        else
          return abs(v) > abs(w);
      else
        return abs(v) < abs(w);
    return c > 0;
  }
  bool operator()(const Pt &p, const Pt &q) const{
    Vec v(p-o), w(q-o);
    double c = cross(v, w);
    if(c == 0) return abs(v) < abs(w);
    return c > 0;
  }
};

// graham's scan で convex hull を生成
// O(n log n)
Poly &grahamScan(Poly poly, Poly &hull){
  sort(poly.begin(), poly.end(),
       PolarAngleCmp(*min_element(poly.begin(), poly.end(), yxCmp)));

  hull.clear();
  hull.push_back(poly[0]);
  hull.push_back(poly[1]);
  for(int i = 2; i < poly.size(); ++i){
    while(hull.size() >= 2 &&
          isRightTurn(hull[hull.size()-2], hull.back(), poly[i]))
      hull.pop_back();
    hull.push_back(poly[i]);
  }
  return hull;
}
