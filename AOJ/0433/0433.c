#include<stdio.h>

char P[12][4] = {"RBYG", "RGBY", "RYGB", "YGRB", "YBGR", "YRBG",
                "BYRG", "BGYR", "BRGY", "GBRY", "GYBR", "GRYB"};
int main(){
  char c1, c2;
  int x, y, n, i, j;
  scanf("%c %c %d", &c1, &c2, &n);

  for ( i = 0; i < n; i++ ){
    scanf("%d %d", &x, &y);
    x %= 4;
    y %= 2;
    if ( y == 1 ) x = 3 - x;
    for ( j = 0; j < 12; j++ ){
      if (P[j][0] == c1 && P[j][1] == c2 ){
	printf("%c\n", P[j][x]);
        break;
      }
    }
  }
  return 0;
}
