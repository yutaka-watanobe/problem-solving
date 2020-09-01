#include<stdio.h>
#include<stdlib.h>
static const int MAX = 65000;
typedef long long llong;

int compare(const void *a, const void *b){
    return *(llong*)a - *(llong*)b;
}

int main(){
  llong n, totalp, totalj, j, t, v, maxv;
  llong P[MAX], J[MAX];
  int i;
  while(1){
    scanf("%lld", &n);
    if ( n == 0 ) break;
    totalp = 0;
    for ( i = 0; i < n; i++ ) {
      scanf("%lld", &P[i]);
      totalp += P[i];
    }
    for ( i = 0; i < n-1; i++ ) scanf("%lld", &J[i]);

    maxv = 0;
    qsort(J, n - 1, sizeof(llong), compare);

    totalj = 0;
    for ( j = 0, t = n; t >= 1; t--, j++ ){
      v = t*(totalj + totalp);
      totalj += J[j];
      maxv = v > maxv ? v : maxv;
    }
    printf("%lld\n", maxv);
  }
  return 0;
}
