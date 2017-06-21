#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

#define MAX 25

class Task{
public:
  int d, lim;
  Task(int d=0, int lim=0): d(d), lim(lim){}
  bool operator < ( const Task &t) const{
    if ( lim == t.lim ) return d < t.d;
    return lim < t.lim;
  }
};

main(){
  int n;
  Task T[MAX];
  while( cin >> n && n ){
    assert( 1 <= n && n <= 25 );
    for ( int i = 0; i < n; i++ ){
      cin >> T[i].d >> T[i].lim;
      assert( 1 <= T[i].d  && T[i].d <= 100);
      assert( 1 <= T[i].lim  && T[i].lim <= 365);
    }
    sort( T, T + n );
    bool success = true;
    int cur = 0;
    for ( int i = 0;  i < n; i++ ){
      cur += T[i].d;
      if ( T[i].lim < cur ) success = false;
    }
    if ( success ) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
