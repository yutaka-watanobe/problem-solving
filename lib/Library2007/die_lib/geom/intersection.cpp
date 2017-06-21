#include <iostream>
#include <complex>
#include <vector>

#include "Util.hpp"
#include "ConvexHull.hpp"

using namespace std;

// 凸多角形を線分 pq で切り落とす (pg の右側)
void cutRight(Poly &poly, const Pt &p, const Pt &q){
  Poly ret;
  Pt r;
  int n = poly.size();
  for(int i = 0; i < n; ++i){
    if(fabs(cross(q - p, poly[i] - p)) < EPS &&
       fabs(cross(q - p, poly[(i+1)%n] - p)) < EPS){ // same line
    }
    else{
      //      if(!(cross(q - p, poly[i] - p) >= 0)) // for clockwise
      if(!(cross(q - p, poly[i] - p) <= 0)) // for anti-clockwise
        ret.push_back(poly[i]);

      // end-point intersection is valid
      if(isIntersectSL(poly[i], poly[(i+1)%n], p, q - p, r))
        ret.push_back(r);
    }
  }
  poly = ret;
}

// 凸多角形の直積
Poly intersection(const Poly &p1, const Poly &p2){
  Poly ret = p1;
  for(int i = 0; i < p2.size(); ++i)
    cutRight(ret, p2[i], p2[(i+1)%p2.size()]); // for anti-clockwise
  //    cutLeft(ret, p2[i], p2[(i+1)%p2.size()]); // for clockwise
  return ret;
}

void gpOutput(const Poly &poly){
  for(int i = 0; i < poly.size(); ++i)
    cout << poly[i].real() << ' ' << poly[i].imag() << endl;
  cout << poly.front().real() << ' ' << poly.front().imag() << endl;
  cout << endl;
}

int main(void){
  Poly poly;
  poly.push_back(Pt(0, 0));
  poly.push_back(Pt(10, 0));
  poly.push_back(Pt(10, 10));
  poly.push_back(Pt(0, 10));
  
  Poly poly2;
  poly2.push_back(Pt(0, 0));
  poly2.push_back(Pt(10, 10));
  poly2.push_back(Pt(0, 20));

  Poly poly3 = intersection(poly, poly2);

  gpOutput(poly);
  gpOutput(poly2);
  gpOutput(poly3);
  
  return 0;
}
