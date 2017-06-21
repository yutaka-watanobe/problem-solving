#include<stdio.h>
struct Point{int y, x;};

int W[100][50], w, h;

int bfs(){
  int i, j, r, head = 0, tail = 0, d[50][50];
  int dy[4] = {0, -1, 0, 1};
  int dx[4] = {1, 0, -1, 0};
  int ny, nx, ii, jj;
  struct Point s, u, v, Q[1000];
  s.y = s.x = 0;
  for(i = 0; i < h; i++) for(j = 0; j < w; j++) d[i][j] = (1<<21);
  d[0][0] = 1;
  Q[tail++] = s;

  while(head != tail){
    u = Q[head++];
    if ( u.y == h-1 && u.x == w-1 ) return d[u.y][u.x];
    for ( r = 0; r < 4; r++ ){
      nx = u.x + dx[r];
      ny = u.y + dy[r];
      if ( nx < 0 || ny < 0 || ny >= h || nx >= w || d[ny][nx] != (1<<21)) continue;
      if ( W[u.y*2+dy[r]][u.x-((r==2)?(1):0)] )	continue;
      d[ny][nx] = d[u.y][u.x] + 1;
      v.x = nx;
      v.y = ny;
      Q[tail++] = v;
    }
  }

  return 0;
}

int main(){
  int i, j;
  while( scanf("%d %d", &w, &h) && (w&&h)){
    for ( i = 0;  i < h*2-1; i++ ){
      for ( j = 0; j < ((i%2)?w:w-1); j++ ) scanf("%d", &W[i][j]);
    }
    printf("%d\n", bfs());
  }
  return 0;
}
