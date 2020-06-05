#include<cstdio>
#include<algorithm>
using namespace std;

main(){
  int n, S[1000];
  scanf("%d", &n);
  for ( int i = 0; i < n; i++ ) scanf("%d", &S[i]);

  double res = 0.0;
  sort(S, S + n);

  for ( int d = 0; d < n-1; d++ ){
    int c = d+1;
    int a = n-1;
    int b = n-2;
    if ( d == n-3 ){
      b = d-1;
    } else if ( d == n-2 ){
      a = d-2;
      b = d-1;
    }
    res = max(res, 1.0*(S[a]+S[b])/(S[c]-S[d]));
  }

  printf("%.8lf\n", res);
}
