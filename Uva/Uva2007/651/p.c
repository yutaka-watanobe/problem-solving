// @JUDGE_ID:  17051CA  651  C++
// @begin_of_source_code
/* Math */
#include<stdio.h>

class Deck{
 public:
  int n;
  
  void compute( int n ){
    double sum = 0.0;

    for ( int k = 1; k <= n; k++ ){
      sum += 1.0 / k;
    }

    printf("%5d%10.3lf\n", n, sum / 2 );
  }

  void work(){
    printf("# Cards Overhang\n");
    while ( 1 ){
      if ( scanf("%d", &n) == EOF ) break;
      compute( n );
    }
  }

};

main(){
  Deck D;
  D.work();
}

// @end_of_source_code


