#include<stdio.h>

int main(){
  int a, t, r;
  scanf("%d %d %d", &a, &t, &r);
  printf("%.8lf\n", (1.0 * t / a) * r);
  return 0;
}
