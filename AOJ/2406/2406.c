#include<stdio.h>

main(){
  int N, T, E, x, ans = -1, i, e;
  scanf("%d%d%d", &N, &T, &E);
  
  for ( i = 0; i < N; i++ ){
    scanf("%d", &x);
    for ( e = -E; e <= E; e++ ){
      if ((T+e)%x == 0 ) ans = i+1;
    }
  }
  printf("%d\n", ans);
  return 0;
}
