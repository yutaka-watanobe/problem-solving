#include<stdio.h>

int main(){
  int a, t, r;
  double elapse; // 経過時間
  scanf("%d %d %d", &a, &t, &r);
  elapse = (1.0 * t / a) * r;
  printf("%.8lf\n", elapse);
  return 0;
}
