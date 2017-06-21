// @JUDGE_ID:  17051CA  10586  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#define MAX 10005

class PolynomialRemain{
 public:
  int n, k;
  int T[MAX];

  void work(){
    int cursor = n;

    if ( k == 0 ){
      printf("0\n");
      return;
    }

    while ( 1 ){
      while ( T[cursor] == 0 && cursor > 0 ) cursor--;

      if ( cursor < k ) break;
      int base = T[cursor];
      T[cursor] = 0;
      T[cursor - k ] -= base;
    }

    if ( k < n ) cursor = k;
    else cursor = n;

    while ( T[cursor] == 0 && cursor > 0 ) cursor--;

    for ( int i = 0; i <= cursor; i++ ){
      if ( i ) printf(" ");
      printf("%d", T[i]);
    }
    printf("\n");
  }

  bool read(){
    scanf("%d %d", &n, &k);
    if ( n == -1 && k == -1 ) return false;
    for ( int i = 0; i <= n; i++ ) scanf("%d", &T[i]);
    return true;
  }
};

main(){
  PolynomialRemain PR;
  while ( PR.read() ) PR.work();
}

// @end_of_source_code


