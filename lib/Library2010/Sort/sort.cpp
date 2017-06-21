#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 2000000
main(){
  int n;
  int A[MAX];
  scanf("%d", &n);
  for ( int i = 0; i < n; i++ ) scanf("%d", &A[i]);

  sort( A, A + n );

  printf("%d\n", n);
  for ( int i = 0; i < n; i++ ) printf("%d\n", A[i]);
}
