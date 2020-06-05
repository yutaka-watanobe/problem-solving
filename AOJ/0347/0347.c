#include<stdio.h>

double max(double a, double b){ return a > b ? a : b; }

void bubbleSort(int n, int S[]){
  int i, j, t;
  for ( i = 0; i < n; i++ )
    for ( j = n-2; j >= i; j-- )
      if ( S[j] > S[j+1] ) {
	t = S[j]; S[j] = S[j+1]; S[j+1] = t;
      }
}

int main(){
  int n, i, S[1000], a, b, c, d;
  double res = 0.0;
  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) scanf("%d", &S[i]);

  bubbleSort(n, S);

  for ( d = 0; d < n-1; d++ ){
    c = d+1;
    a = n-1;
    b = n-2;
    if ( d == n-3 ){
      b = d-1;
    } else if ( d == n-2 ){
      a = d-2;
      b = d-1;
    }
    res = max(res, 1.0*(S[a]+S[b])/(S[c]-S[d]));
  }

  printf("%.8lf\n", res);

  return 0;
}
