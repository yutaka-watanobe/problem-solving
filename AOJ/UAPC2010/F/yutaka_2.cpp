#include<iostream>
#include<cstdio>
using namespace std;
#define rep(i, n) for ( int i= 0; i < n; i++)
#define MAX 100000
#define LIM 200

double power2(int n){
    double p = 1.0;
    for ( int i = 0; i < n; i++ ) p *= 2.0;
    return p;
}

main(){
  double P[LIM+1], T[LIM+1];
  double E[MAX+1];
  double R[LIM+1];
  
  for ( int i = 0; i <= LIM; i++ ) R[i] = 1.0/power2(i);
  
  rep(i, MAX+1) E[i] = 0.0;
  rep(j, LIM+1) P[j] = 0.0;
  P[1]  = E[1] = 1.0;

  for ( int i = 1; i <= MAX; i++ ){

    rep(a, LIM+1) T[a] = 0.0;
    for ( int j = 0; j <= min(i, LIM); j++ ){
      if ( j+1 <= LIM ){
	T[j+1] += P[j]*(R[j]);
      }
      T[0] += P[j]*(1.0 - R[j]);
    }

    for ( int j = 0; j <= min(i, LIM); j++ ){
      if ( i+1 <= MAX ) E[i+1] += P[j]*(R[j]);
    }
    rep(a, LIM+1) P[a] = T[a];
  }

  for ( int i = 2; i <= MAX; i++ ) E[i] += E[i-1];


  int n;
  while( cin>> n && n ) printf("%.12lf\n", E[n]);

}
