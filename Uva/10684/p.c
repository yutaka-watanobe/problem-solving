// @JUDGE_ID:  17051CA  10684  C++
// @begin_of_source_code
#include<stdio.h>
#include<climits>
#include<algorithm>
#define MAX 10000

int n;
int A[ MAX + 1 ], S[ MAX + 1 ];

bool read(){
  scanf("%d", &n); if ( n == 0 ) return false;
  for ( int i = 0; i < n; i++ ) scanf("%d", &A[i]);
  return true;
}

void compute(){
  int maxValue = -INT_MAX;
  S[0] = A[0];
  maxValue = max(S[0], maxValue);
  for ( int i = 1; i < n; i++ ){
    S[i] = A[i] + max( 0, S[i-1] );
    maxValue = max(S[i], maxValue);
  }
  if ( maxValue <= 0 ) printf("Losing streak.\n");
  else printf("The maximum winning streak is %d.\n", maxValue );
}

int main(){
  while ( read() ){
    compute();
  }
  return 0;
}
// @end_of_source_code
