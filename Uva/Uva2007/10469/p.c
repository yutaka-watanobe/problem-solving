// @JUDGE_ID:  17051CA  10469  C++
// @begin_of_source_code
/* Bit set + 排他的論理和 */
#include<stdio.h>
#include<iostream>
#include<bitset>

class ToCarryOrNot{
 public:
  bitset<32> A, B;

  ToCarryOrNot(){}

  void work(){
    unsigned long sum = 0;
    int p = 1;
    for ( int i = 0; i < 32; i++ ){
      if ( A[i] ^ B[i] ) sum += p;
      p *= 2;
    }
    cout << sum << endl;
  }

  bool read(){
    int a, b;
    if ( !( cin >> a >> b ) ) return false;
    A = bitset<32>( a );
    B = bitset<32>( b );

    return true;
  }

};

main(){
  ToCarryOrNot carry;
  while ( carry.read() ){
    carry.work();
  }
}

// @end_of_source_code


