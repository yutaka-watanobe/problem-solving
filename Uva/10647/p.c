// @JUDGE_ID:  17051CA  10647  C++
// @begin_of_source_code
#include<stdio.h>
#include<cmath>
#include<iostream>
#include<vector>
#define MAX 10001

typedef long long llong;

class OptimalHousePlacement{
 public:
  int n;
  llong H[MAX], R[MAX], L[MAX];
  
  bool read(){
    scanf("%d", &n);
    if ( n == 0 ) return false;
    for ( int i = 0; i < n; i++ ){
      scanf("%lld", &H[i]);
    }
    return true;
  }

  void init(){

    R[n-1] = 0;
    llong sum;
    llong mul = 1;
    for ( int i = n-2; i >= 0; i-- ){
	llong d = H[i] - H[i+1];
	R[i] = R[i+1] + d*d*mul;
	mul++;
    }

    L[0] = 0;
    mul = 1;
    for( int i = 1; i < n; i++ ){
      llong d = H[i] - H[i-1];
      L[i] = L[i-1] + d*d*mul;
      mul++;
    }
  }

  void work(){    

    init();

    double minimum = 9223372036854775807LL;
    double sum;
    double ans;
    double x;
    llong a, b;
    int l1, l2;

    for ( int i = 1; i < n; i++ ){
      a = H[i-1]; b = H[i];
      l1 = i;
      l2 = n - i;
      sum = 0.0;

      sum += L[i-1];
      sum += R[i];
      sum += a*a*l1 + b*b*l2;
      sum -= 1.0*(a*l1+b*l2)*(a*l1+b*l2)/(l1+l2);

      x = 1.0*(a*l1+b*l2)/(l1+l2);

      if ( sum < minimum ){
	minimum = sum;
	ans = x;
      }
    }

    printf("%.3lf\n", ans);
  }

};

main(){

  OptimalHousePlacement OHP;

  while ( OHP.read() ){
    OHP.work();
  }
}

// @end_of_source_code


