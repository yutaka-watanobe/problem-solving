#include<iostream>
#include<cstdio>
using namespace std;
#define rep(i, n) for ( int i= 0; i < n; i++)
#define MAX 100000
#define LIM 10

double power2(int n){
    double p = 1.0;
    for ( int i = 0; i < n; i++ ) p *= 2.0;
    return p;
}

main(){
  double P[MAX+1][LIM+1];
  double E[MAX+1];
  
  rep(i, MAX+1) E[i] = 0.0;
  rep(i, MAX+1) rep(j, LIM+1) P[i][j] = 0.0;
  P[0][0] = P[1][1] = 1.0;

  for ( int i = 1; i <= MAX; i++ ){
    for ( int j = 0; j <= min(i, LIM); j++ ){
      if ( i+1 <=MAX && j+1 <= LIM ){
	P[i+1][j+1] += P[i][j]*(1.0/power2(j));
      }
      P[i+1][0] += P[i][j]*(1.0 - 1.0/power2(j));
    }
  }

  for ( int i = 1; i <= MAX; i++ ){
    for ( int j = 1; j <= min(i, LIM); j++ ){
      E[i] += P[i-1][j-1]*(1.0/power2(j-1));
    }
    E[i] += E[i-1];
  }

  int n;
  while( cin>> n && n ) printf("%.12lf\n", E[n]);

}
