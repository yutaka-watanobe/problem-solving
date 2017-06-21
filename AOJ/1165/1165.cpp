#include<iostream>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
struct Point{int x, y;};
main(){
  int n, t, d, minx, miny, maxx, maxy;
  Point P[200];
  while( cin >> n && n ){
    minx = miny = maxx = maxy = P[0].x = P[0].y = 0;
    for ( int i = 1; i < n; i++ ){
      cin >> t >> d;
      P[i].x = P[t].x + dx[d];
      P[i].y = P[t].y + dy[d];
      minx = min(minx, P[i].x);
      miny = min(miny, P[i].y);
      maxx = max(maxx, P[i].x);
      maxy = max(maxy, P[i].y);
    }
    cout << maxx-minx+1 << " " << maxy-miny+1 << endl;
  }
}
