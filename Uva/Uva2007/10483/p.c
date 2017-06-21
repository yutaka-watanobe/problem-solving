// @JUDGE_ID:  17051CA  10483  C++
// @begin_of_source_code
/* Brute-Force */
#include<stdio.h>
#include<iostream>
#include<stl.h>

class Triple{
 public:
  int a, b, c;
  int sum;

  Triple(){}
  Triple( int a, int b, int c ): a(a), b(b), c(c){
    sum = a + b + c;
  }

  bool operator < ( const Triple &t ) const {
    if ( sum == t.sum ){
      return a < t.a;
    } else return sum < t.sum;
  }

};

class TheSumEqualsTheProduct{
 public:
  vector<Triple> T;
  int lower, upper;

  void init(){
    T.clear();
    int cnt = 0;
    long c;
    for ( long a = 1; a*a*a < 256000000 ; a++ ){
      for ( long b = a; a*b*b < 256000000 ; b++){
	if ( a + b > 25600 ) continue;
	if ( a * b == 10000 ) continue;

	if ( 10000 * ( a + b ) % ( a * b - 10000 ) != 0 ) continue;

	c = 10000 * ( a + b ) / ( a * b - 10000 );

	if ( c < b ) continue;

	if ( 10000 * ( a + b + c ) == a * b * c ){
	  if ( a + b + c < 25600 ){
	    T.push_back( Triple(a, b, c) ) ;
	  }
	}
      }
    }

    sort( T.begin(), T.end() );
  }

  void work(){
    Triple triple;
    int sum1, sum2, a1, a2, b1, b2, c1, c2;
    for ( int i = 0; i < T.size(); i++ ){
      triple = T[i];
      if ( lower <= triple.sum && triple.sum <= upper ){
	sum1 = triple.sum / 100;
	sum2 = triple.sum % 100;
	a1 = triple.a / 100;
	a2 = triple.a % 100;
	b1 = triple.b / 100;
	b2 = triple.b % 100;
	c1 = triple.c / 100;
	c2 = triple.c % 100;

	printf("%d.", sum1);
	if ( sum2 < 10 ) printf("0");
	printf("%d = ", sum2 );
	printf("%d.", a1);
	if ( a2 < 10 ) printf("0");
	printf("%d + ", a2 );
	printf("%d.", b1);
	if ( b2 < 10 ) printf("0");
	printf("%d + ", b2 );
	printf("%d.", c1);
	if ( c2 < 10 ) printf("0");
	printf("%d = ", c2 );
	printf("%d.", a1);
	if ( a2 < 10 ) printf("0");
	printf("%d * ", a2 );
	printf("%d.", b1);
	if ( b2 < 10 ) printf("0");
	printf("%d * ", b2 );
	printf("%d.", c1);
	if ( c2 < 10 ) printf("0");
	printf("%d\n", c2 );
      }
    }
  }

  void read(){
    int x, y;
    char ch;
    cin >> x >> ch >> y;
    lower = 100*x + y;
    cin >> x >> ch >> y;
    upper = 100*x + y;
  }
};

main(){
  TheSumEqualsTheProduct TSETP;
  TSETP.init();
  TSETP.read();
  TSETP.work();
}

// @end_of_source_code


