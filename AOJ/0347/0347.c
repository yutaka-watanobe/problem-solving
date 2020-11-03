#include<stdio.h>

double max(double x, double y){
  return x > y ? x : y;
}

void bubbleSort(int N, int a[]){
  int i, j, t;
  for ( i = 0; i < N; i++ )
    for ( j = N - 2; j >= i; j-- )
      if ( a[j] > a[j+1] ) {
	t = a[j]; a[j] = a[j+1]; a[j+1] = t;
      }
}

int main(){
  int N, i, a[1000], A, B, C, D;
  double res = 0.0;
  scanf("%d", &N);
  for ( i = 0; i < N; i++ ) scanf("%d", &a[i]);

  bubbleSort(N, a);

  for ( D = 0; D < N - 1; D++ ){
    C = D + 1;
    A = N - 1;
    B = N - 2;
    if ( D == N - 3 ){
      B = D - 1;
    } else if ( D == N - 2 ){
      A = D - 2;
      B = D - 1;
    }
    res = max(res, 1.0 *
	      (a[A] + a[B]) / (a[C] - a[D]));
  }

  printf("%.8lf\n", res);
  return 0;
}
