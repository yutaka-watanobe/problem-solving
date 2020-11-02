#include<stdio.h>
#define MAX_X 2000
#define MAX_Y 2000

int grid[MAX_X][MAX_Y]; /* 海苔が置かれる区画。 グローバル変数のため0に初期化される。*/

int main() {
  int i, j, k, c = 0;
  int x, y, w, h;
  for ( k = 0; k < 2; k++ ) {
    scanf("%d %d %d %d", &x, &y, &w, &h);
    for ( i = x; i < x + w; i++ ) 
      for ( j = y; j < y + h; j++ ) ++grid[i][j];
  }
    
  for ( i = 0; i < MAX_X; ++i ) 
    for ( j = 0; j < MAX_Y; ++j ) 
      if ( grid[i][j] == 1 ) ++c;
  printf("%d\n", c);
  return 0;
}
