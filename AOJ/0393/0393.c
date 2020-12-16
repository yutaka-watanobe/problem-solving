#include<stdio.h>

int main() {
  int H, A, B, i, cnt = 0; 
  scanf("%d %d %d", &H, &A, &B);

  for ( i = A; i <= B; i++ ){
    cnt += (H % i == 0 );
  }

  printf("%d\n", cnt);
  return 0;
}
