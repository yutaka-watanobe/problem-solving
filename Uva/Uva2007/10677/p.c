// @JUDGE_ID:  17051CA  10677  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<vector>

class BaseEquality{
 public:
  int B1, B2, R1, R2;

  vector<int> createBit( int a, int base ){
    vector<int> bit;
    int next;
    while(a>0 ){
      bit.push_back( a%base );
      a = a/base;
    }
    return bit;
  }

  int getValue( vector<int> bit, int base ){
    int p = 1;
    int sum = 0;
    for ( int i = 0; i < bit.size(); i++ ){
      sum += bit[i] * p;
      p *= base;
    }
    return sum;
  }

  bool compute( int i ){
    vector<int> bit = createBit(i, B1);
    if ( getValue( bit, B2 ) % i == 0 ) return true;
    else return false;
  }

  void work(){
    for ( int i = R2; i >= R1; i-- ){
      if ( compute(i) ) {
	printf("%d\n", i );
	return;
      }
    }
    printf("Non-existent.\n");
  }

  void read(){
    scanf("%d %d %d %d", &B1, &B2, &R1, &R2 );
  }
};

main(){
  int tcase;
  scanf("%d", &tcase );
  BaseEquality BE;
  for ( int i = 0; i < tcase; i++ ){
    BE.read();
    BE.work();
  }
}
// @end_of_source_code
