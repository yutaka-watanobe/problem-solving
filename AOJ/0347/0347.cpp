#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
  int N, a[1000];
  scanf("%d", &N);
  for ( int i = 0; i < N; i++ ) scanf("%d", &a[i]);

  double res = 0.0;
  sort(a, a + N);

  for ( int D = 0; D < N - 1; D++ ){
    int C = D + 1;
    int A = N - 1;
    int B = N - 2;
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
