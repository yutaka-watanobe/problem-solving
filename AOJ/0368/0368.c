#include<stdio.h>

int main(){
  int H, W, i, j;
  char c;
  scanf("%d %d %c", &W, &H, &c);

  for ( i = 0; i < H; i++ ){ 
    for ( j = 0; j < W; j++ ){
      if ( i == 0 && j == 0 || i == 0 && j == W - 1 ||
	   i == H - 1 && j == 0 || i == H - 1 && j == W - 1 ) printf("+");
      else if ( i == 0 || i == H - 1 ) printf("-");
      else if ( j == 0 || j == W - 1 ) printf("|");
      else if ( i == H / 2 && j == W / 2 ) printf("%c", c);
      else printf(".");
    }
    printf("\n");
  }
  return 0;
}
