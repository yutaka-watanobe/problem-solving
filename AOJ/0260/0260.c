#include<stdio.h>
static const int MAX = 65000;

void merge(long long *J, int l, int m, int r){
  long long T[MAX];
  int i, j, k;
  for ( i = l; i < m; i++ ) T[i] = J[i];
  for ( i = m; i < r; i++ ) T[(r-1)-(i-m)] = J[i];
  i = l;
  j = r - 1;
  for ( k = l; k < r; k++ ){
    if ( T[i] <= T[j] ) J[k] = T[i++];
    else J[k] = T[j--];
  }
}

void mergeSort(long long *J, int l, int r){
  if ( l+1 >= r ) return;
  int m = (l+r)/2;
  mergeSort(J, l, m);
  mergeSort(J, m, r);
  merge(J, l, m, r);
}

int main(){
  long long n, totalp, totalj, maxv;
  long long P[MAX], J[MAX];

  while(1){
    scanf("%lld", &n);
    if ( n == 0 ) break;
    totalp = 0;
    for ( int i = 0; i < n; i++ ) {
      scanf("%lld", &P[i]);
      totalp += P[i];
    }
    for ( int i = 0; i < n-1; i++ ) scanf("%lld", &J[i]);

    mergeSort(J, 0, (n-1)); /* ジョイントを長さの昇順に整列 */
    J[n-1] = 0;             /* 0 本使う場合 */
    
    maxv = 0;
    totalj = 0;
    for ( int k = 0; k <= n - 1; k++ ){
      totalj += J[n - 1 - k]; /* 長いものから選んでいく*/
      long long v = (n - k) * (totalj + totalp);
      maxv = v > maxv ? v : maxv;
    }

    printf("%lld\n", maxv);
  }
  
  return 0;
}
