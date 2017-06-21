#include<iostream>
using namespace std;

#define MAX 100

double power2(int n){
    double p = 1.0;
    for ( int i = 0; i < n; i++ ) p *= 2.0;
    return p;
}

main(){
  double T[MAX][MAX];

  for ( int i = 0; i < MAX; i++ ) for ( int j = 0; j < MAX; j++ )T[i][j] = 0;
  T[1][1] = 1.0;
  for ( int i = 1; i < MAX; i++ ){
    for ( int j = 1; j <= i; j++ ){
      T[i+1][j+1] += T[i][j]*(1.0/power2(j));
      T[i+1][j] += T[i][j]*(1.0-1.0/power2(j));
    }
  }

  int n;
  while( cin >> n && n ){
    double sum = 0;
    for ( int j = 1; j <= n; j++ ){
      sum += j*T[n][j];
    }
    printf("%.20lf\n", sum);
  }
}
