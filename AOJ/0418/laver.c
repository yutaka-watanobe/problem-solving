#include<stdio.h>

#define MAX_X 2000
#define MAX_Y 2000

//sはグローバル変数なので 宣言時に0に初期化される
int s[MAX_X][MAX_Y];

int main() {
  int i, j, k, c = 0;
  int x, y, w, h;
  for ( k=0; k<2; ++k ) {
    scanf("%d %d %d %d", &x, &y, &w, &h);
    for ( i = x; i < x + w; ++i ) 
      for ( j = y; j < y + h; ++j ) ++s[i][j];
  }
    
  for ( i = 0; i < MAX_X; ++i ) 
    for ( j = 0; j < MAX_Y; ++j ) 
      if ( s[i][j] == 1 ) ++c;
  printf("%d\n", c);
  return 0;
}
