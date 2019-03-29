#include<stdio.h>

#define NMAX 100000
#define PMAX 100000

int N, T[2*PMAX+20+1];

int main(){
  int i, a, b;
  scanf("%d", &N);
  for ( i = 0; i < N; i++ ){
    scanf("%d %d", &a, &b);
    T[a+b]++;
  }
  for ( i = 0; i < 2*PMAX+20; i++ ){
    T[i+1] += T[i]/2;
    T[i] = T[i]%2;
    if ( T[i] ) printf("%d %d\n", i, 0);
  }

  return 0;
}
