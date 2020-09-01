#include<iostream>
#include<algorithm>
using namespace std;
static const int MAX = 65000;
typedef long long llong;

void merge(long long *J, int l, int m, int r){
  long long T[MAX];
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

void mergeSort(long long *J, int l, int r){
  if ( l+1 >= r ) return;
  int m = (l+r)/2;
  mergeSort(J, l, m);
  mergeSort(J, m, r);
  merge(J, l, m, r);
}

main(){
  llong n, totalp, totalj;
  llong P[MAX], J[MAX];

  while(1){
    cin >> n;
    if ( n == 0 ) break;
    totalp = 0;
    for ( int i = 0; i < n; i++ ) {
      cin >> P[i];
      totalp += P[i];
    }
    for ( int i = 0; i < n-1; i++ ) cin >> J[i];

    sort(J, J+(n-1));
    reverse(J, J+(n-1));
    
    llong maxv = 0;
    totalj = 0;
    for ( int j = 0, t = n; t >= 1; t--, j++ ){
      long long v = t*(totalj + totalp);
      totalj += J[j];
      maxv = max(v, maxv);
    }
    cout << maxv << endl;
  }
}
