#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<Pt> Poly;

double surface(const Poly &p){
  double answer = 0;
  int n = p.size();
  for(int i = 0; i < n; ++i)
    answer += ((p[i].real() - p[(i+1)%n].real()) *
               (p[i].imag() + p[(i+1)%n].imag()));
  return fabs(answer / 2.0);
}

// 力学的重心
Pt gravityPointP(const Poly &p){
  Pt g = Pt(0, 0);
  for(int i = 0; i < p.size(); ++i)
    g += p[i];
  g /= p.size();
  return g;
}

// 幾何的重心
Pt gravityPointG(const Poly &p){
  double s = 0, area;
  double real = 0, imag = 0;
  int n = p.size();
  
  for(int i = 1; i < n-1; i++){
    area = ::surface(p.front(), p[i], p[(i+1)%n]);
    s += area;
    real += area * (p[i].real() + p[(i+1)%n].real()) / 3.0;
    imag += area * (p[i].imag() + p[(i+1)%n].imag()) / 3.0;
  }
  return Pt(real / s, imag / s);
}

//******************************************************************
// 多角形内に点があるかどうか
// O(n log n)
// check @uva634
// check @pku3082
bool isInside(const Poly &poly, const Pt &p){
  Vec dir(1, 0);
  int n = poly.size();
  
  set<double> angle;
  for(int i = 0; i < n; ++i){
    if(p == poly[i]) // p is vertex of polygon
      return true;
    if(onSegment(poly[i], poly[(i+1)%n], p)) // p is a point on edge of polygon
      return true;
    angle.insert(arg(poly[i] - p));
  }
  bool found = false;
  for(int i = 0; i < n; ++i){
    dir = ((poly[i] + poly[(i+1)%n]) / 2.0) - p;
    if(angle.find(arg(dir)) == angle.end()){
      found = true;
      break;
    }
  }
  if(!found)
    return false;
  
  int cnt = 0;
  Pt r;
  for(int i = 0; i < n; ++i)
    if(isIntersectRS(p, dir, poly[i], poly[(i+1)%n], r))
      ++cnt;
  return cnt % 2 != 0;
}

//************************************************
// 頂点の座標は unique であること
// O(n)
// check @uva634
bool isInside2(const Poly &poly, const Pt &p){
  Vec ret;
  Vec dir(1, 0);
  
  int cnt = 0;
  int n = poly.size();
  for(int i = 0; i < n; ++i){
    if(p == poly[i] || onSegment(poly[i], poly[(i+1)%n], p)) // p on poly
      return true;

    // L = p + dir  over lap  same gradient segment
    if(arg(dir) == arg(poly[i] - p) && arg(dir) == arg(poly[(i+1)%n] - p)){
      // find not same gradient point A that is previous i
      int begin = i;
      while(arg(dir) == arg(poly[begin] - p)){
        --begin;
        if(begin < 0)
          begin = n - 1;
      }
      // find not same gradient point B that is following i
      int end = (i + 1) % n;
      while(arg(dir) == arg(poly[end] - p))
        end = (end + 1) % n;

      
      if(begin != end) // this branch is needed ?
        if(cross(dir, poly[begin] - p) * cross(dir, poly[end] - p) < 0) // A and B is different dir
          ++cnt;

      if(end < i) // if end exceed n, loop end
        break;
      i = end;
    }
    // 
    else if(// poly[i].imag() != poly[(i+1)%n].imag() &&  <=  this couldn't need !
            isIntersectRS(p, dir, poly[i], poly[(i+1)%n], ret)){ // need end-point intersection
      if(ret != poly[i]){
        if(ret == poly[(i+1)%n]){
          double c = cross(dir, poly[i] - ret);
          double d = cross(dir, poly[(i+2)%n] - ret);
          if(d != 0 && c != 0) // this branch is needed ?
                               // may be unnecessary (because same gradient segment check is)
            if(c * d <= 0)
              ++cnt;
        }
        else
          ++cnt;
      }
    }
  }
  return cnt % 2 != 0;
}
