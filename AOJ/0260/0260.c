#include<stdio.h>
static const int MAX = 65000;
typedef long long llong;

void merge(llong *J, int l, int m, int r){
  llong T[MAX];
  int i, j, k;
  for ( i = l; i < m; i++ ) T[i] = J[i];
  for ( i = m; i < r; i++ ) T[(r-1)-(i-m)] = J[i];
  i = l;
  j = r - 1;
  for ( k = l; k < r; k++ ){
    if ( T[i] >= T[j] ) J[k] = T[i++];
    else J[k] = T[j--];
  }
}

void mergeSort(llong *J, int l, int r){
  int m;
  if ( l+1 < r ){
    m = (l+r)/2;
    mergeSort(J, l, m);
    mergeSort(J, m, r);
    merge(J, l, m, r);
  }
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
    mergeSort(J, 0, (n-1));

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
