#include<stdio.h>

int main(){
  int i, N, K, P;
  scanf("%d", &N);
  for ( int i = 0; i < N; i++ ){
    scanf("%d %d", &K, &P);
    printf("%d\n", (K-1)%P + 1);
  }
  return 0;
}
  
