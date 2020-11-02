#include<stdio.h>

double max(double a, double b){
  return a > b ? a : b;
}

void bubbleSort(int n, int S[]){
  int i, j, t;
  for ( i = 0; i < n; i++ )
    for ( j = n-2; j >= i; j-- )
      if ( S[j] > S[j+1] ) {
	t = S[j]; S[j] = S[j+1]; S[j+1] = t;
      }
}

int main(){
  int N, i, A[1000], p1, p2, p3, p4;
  double res = 0.0;
  scanf("%d", &N);
  for ( i = 0; i < N; i++ ) scanf("%d", &A[i]);

  bubbleSort(N, A);

  for ( p4 = 0; p4 < N - 1; p4++ ){
    p3 = p4 + 1;
    p1 = N - 1;
    p2 = N - 2;
    if ( p4 == N - 3 ){
      p2 = p4 - 1;
    } else if ( p4 == N - 2 ){
      p1 = p4 - 2;
      p2 = p4 - 1;
    }
    res = max(res, 1.0 *
	      (A[p1] + A[p2]) / (A[p3] - A[p4]));
  }

  printf("%.8lf\n", res);
  return 0;
}
