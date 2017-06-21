#include<stdio.h>

int main(){
  int a, b, c, nrhombo = 0, nrectangle = 0;
  while ( scanf("%d,%d,%d", &a, &b, &c) != EOF ) {
    if ( a == b ) nrhombo++;
    else if ( a*a + b*b == c*c ) nrectangle++;
  }
  printf("%d\n%d\n", nrectangle, nrhombo);
}
