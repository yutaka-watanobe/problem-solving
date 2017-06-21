// @JUDGE_ID:  17051CA  10648  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#define MAX 101

class ChocolateBox{
 public:
  int n, m;
  double T[MAX][MAX];

  void init(){
    T[0][0] = 1;
    for ( int i = 1; i < MAX; i++ ){
      T[i][1] = 1;
      T[i][i] = T[i-1][i-1]*i;
    }

    for ( int i = 3; i < MAX; i++ ){
      for ( int j = 2; j < i; j++ ){
	T[i][j] = (T[i-1][j] + T[i-1][j-1])*j;
      }
    }

  }

  bool read(){
    //    cin >> n;
    scanf("%d", &n);
    if ( n == -1 ) return false;
    scanf("%d", &m);
    //    cin >> m;
    return true;
  }
  
  void work(){
    double p = T[n][m];
    for ( int i = 0; i < n; i++ ) p /= m;

    //    p = 1.0 - p;

    printf("%.7lf\n", 1.0 - p );
  }
};

main(){
  ChocolateBox CB;

  CB.init();

  for ( int i = 1; CB.read(); i++ ){
    printf("Case %d: ", i );
    CB.work();
  }
    
}

// @end_of_source_code


