#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
  int N, A[1000];
  scanf("%d", &N);
  for ( int i = 0; i < N; i++ ) scanf("%d", &A[i]);

  double res = 0.0;
  sort(A, A + N);

  for ( int p4 = 0; p4 < N - 1; p4++ ){
    int p3 = p4 + 1;
    int p1 = N - 1;
    int p2 = N - 2;
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
