#include<iostream>
#include<queue>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++)
struct Point{int y, x;};

int W[100][50], w, h;

int bfs(){
  Point s;
  s.y = s.x = 0;
  queue<Point> Q;
  int d[50][50];
  rep(i, h) rep(j, w) d[i][j] = (1<<21);
  d[0][0] = 1;
  Q.push(s);
  Point u, v;
  int dy[4] = {0, -1, 0, 1};
  int dx[4] = {1, 0, -1, 0};
  int ny, nx, ii, jj;

  while(!Q.empty()){
    u = Q.front(); Q.pop();
    if ( u.y == h-1 && u.x == w-1 ) return d[u.y][u.x];
    rep(r, 4){
      nx = u.x + dx[r];
      ny = u.y + dy[r];
      if ( nx < 0 || ny < 0 || ny >= h || nx >= w || d[ny][nx] != (1<<21)) continue;
      if ( W[u.y*2+dy[r]][u.x-((r==2)?(1):0)] )	continue;
      d[ny][nx] = d[u.y][u.x] + 1;
      v.x = nx;
      v.y = ny;
      Q.push(v);
    }
  }

  return 0;
}

main(){
  while(cin>> w >> h && (w&&h)){
    rep(i, h*2-1) rep(j, ((i%2)?w:w-1)) cin >> W[i][j];
    cout << bfs() << endl;
  }
}
