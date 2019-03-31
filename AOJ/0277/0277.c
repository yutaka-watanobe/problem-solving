#include<stdio.h>

int main(){
  int t, n, i;
  int V[5] = {0, 6000, 4000, 3000, 2000};

  for ( i = 0; i < 4; i++ ){
    scanf("%d %d", &t, &n);
    printf("%d\n", V[t]*n);
  }

  return 0;
}
