#include<stdio.h>

int overlap(int a, int b, int c, int d){
  if ( d <= a ) return 0;
  if ( b <= c ) return 0;
  return 1;
}

int main(){
  int a, b, s, f, n, i;
  scanf("%d %d %d", &a, &b, &n);
  for ( int i = 0; i < n; i++ ){
    scanf("%d %d", &s, &f);
    if ( overlap(a, b, s, f) ){
      printf("1\n");
      return 0;
    }
  }
  printf("0\n");
  return 0;
}

