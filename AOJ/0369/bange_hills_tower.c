#include<stdio.h>

int main() {
  int i, N;
  double t, slope, maxSlope = 0.0, xi, hi;
  scanf("%d %lf", &N, &t);

  for ( i = 0; i < N; i++ ) {
    scanf("%lf %lf", &xi, &hi);
    slope = hi / xi;
    if ( slope > maxSlope ) maxSlope = slope;
  }

  printf("%lf\n", t * maxSlope);
  return 0;
}
