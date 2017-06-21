#include<stdio.h>

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
struct Point{int x, y;};

int min(int a, int b) { return ((a<b)?a:b); }
int max(int a, int b) { return ((a>b)?a:b); }

int main(){
  int n, t, d, minx, miny, maxx, maxy, i;
  struct Point P[200];
  while( scanf("%d", &n) && n ){
    minx = miny = maxx = maxy = P[0].x = P[0].y = 0;
    for ( i = 1; i < n; i++ ){
      scanf("%d %d", &t, &d);
      P[i].x = P[t].x + dx[d];
      P[i].y = P[t].y + dy[d];
      minx = min(minx, P[i].x);
      miny = min(miny, P[i].y);
      maxx = max(maxx, P[i].x);
      maxy = max(maxy, P[i].y);
    }
    printf("%d %d\n", maxx - minx + 1, maxy - miny + 1);
  }
  return 0;
}
