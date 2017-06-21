#include <algorithm>
#include <climits>

#include "Util.hpp"

using namespace std;

bool xyCmp(const Pt &p, const Pt &q){
  if(p.real() == q.real())
    return p.imag() < q.imag();
  return p.real() < q.real();
}

// ! もっと速い実装がある
void find(Pt ps[], int len, double &ans){
  if(len <= 3){
    // 点が 3 つ以下なら全部調べる
    for(int i = 0; i < len-1; ++i)
      for(int j = i+1; j < len; ++j)
        ans = min(ans, abs(ps[i]-ps[j]));
  }
  else{
    int mid = len/2 + len%2;
    
    find(ps, mid, ans);
    find(ps+mid, len-mid, ans);

    for(int i = mid-1; i >= 0; --i){
      if(abs(ps[i].real()-ps[mid].real()) >= ans)
        break;
      for(int j = mid; j < len; ++j){
        if(abs(ps[i].real()-ps[j].real()) >= ans)
          break;
        ans = min(ans, abs(ps[i]-ps[j]));
      }
    }
  }
}

// closest pair の距離を求める
double closestPair(Pt ps[], int len){
  double ans = INF;
  sort(ps, ps + len, xyCmp);
  find(ps, len, ans);
  return ans;
}
