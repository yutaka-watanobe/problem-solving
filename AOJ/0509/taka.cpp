#include <iostream>
#include <queue>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <map>
#include <set>

using namespace std;

const int B = 0;
const int U = 1;
int n, m;

class Rec{
public:
  int x1, x2, y1, y2;
  int mode;

  Rec(int x1, int y1, int x2, int y2, int mode = B)
    : x1(x1), y1(y1), x2(x2), y2(y2), mode(mode) {}

  int getH() const {
    if( mode == B )
      return y1;
    else
      return y2;
  }

  bool operator>(const Rec &r) const {
    if( getH() != r.getH() )
      return getH() > r.getH();
    
    if( x1 != r.x1 )
      return x1 > r.x1;

    return false;
  }
};

inline bool isOver(int l1, int r1, int l2, int r2){
  return max(l1, l2) <= min(r1, r2);
}

int getW(multiset< pair<int, int> > &wid, int &chunk){
  int width = 0;
  int l = -1, r = -1;

  for(multiset< pair<int,int> >::iterator i=wid.begin(); i!=wid.end(); ++i){
    if( isOver(l, r, i->first, i->second) ){
      l = min(l, i->first);
      r = max(r, i->second);
    } else {
      ++chunk;
      width = r - l;
      l = i->first;
      r = i->second;
    }
  }

  width += r - l;

  return width;
}

void solve(priority_queue< Rec, vector<Rec>, greater<Rec> > &q, int mode = -1){
  multiset< pair<int,int> >wid;
  int s = 0, l = 0;
  int chunk = 0;
  int preH = 0, curH = 0;
  int curW = 0, preW = 0;

  while( !q.empty() ){
    Rec r = q.top();
    q.pop();

    curH = r.getH();
    s += curW * (curH - preH);
    l += 2 * chunk * (curH - preH);

    if( r.mode == B )
      wid.insert( make_pair(r.x1, r.x2) );
    else if( r.mode == U )
      wid.erase(wid.find( make_pair(r.x1, r.x2) ));
    else
      assert(false);

    //cout << r.id << ' ' << s << ' ' << l << " - " << curH << ' ' << preH << ' ' << curW << ' ' << chunk << endl;

    preH = curH;
    preW = curW;

    chunk = 0;
    curW = getW(wid, chunk);

    if( r.mode == B )
      l += curW - preW;
    else
      l += preW - curW;
  }

  printf("%d\n", s);
  
  if( mode == 2 )
    printf("%d\n", l);
}

int main(){
  while( scanf("%d %d", &n, &m) == 2 && (n|m) != 0 ){
    priority_queue< Rec, vector<Rec>, greater<Rec> > q;

    for(int i=0; i<n; ++i){
      int x1, y1, x2, y2;
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

      Rec r = Rec(x1, y1, x2, y2, B);
      q.push(r);
      
      r.mode = U;
      q.push(r);
    }

    solve(q, m);
  }

  return 0;
}

