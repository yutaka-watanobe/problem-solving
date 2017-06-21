// @JUDGE_ID:  17051CA  10656  C++
// @begin_of_source_code
#include<stdio.h>
#define MAX 1001

class MaximumSum{
 public:
  int T[MAX];
  int n;

  bool read(){
    scanf("%d", &n);
    if ( n == 0 ) return false;
    return true;
  }

  void work(){
    bool isFirst = true;
    int x;
    for ( int i = 0; i < n; i++ ){
      scanf("%d", &x );
      if ( x != 0 ){
	if ( !isFirst ) printf(" ");
	printf("%d", x );
	isFirst = false;
      }
    }
    if ( isFirst ) printf("0");
    printf("\n");
  }
};

main(){
  MaximumSum MS;
  while ( MS.read() ) MS.work();
}

// @end_of_source_code


