// @JUDGE_ID:  17051CA  357  C++
// @begin_of_source_code
/* Dynamic Programming */
/* Dollar */
#include<stdio.h>
#include<iostream>
#include<string>
#define MAX 30000

int coin[5] = {1, 5, 10, 25, 50};
int change;
unsigned long long T[MAX+1];

void init(){
  for ( int i = 0; i < MAX+1; i++ ) T[i] = 1;
  for ( int k = 1; k < 5; k++ ){
    for ( int n = coin[ k ]; n < MAX+1; n++ ){
      T[ n ] += T[ n - coin[ k ] ];
    }
  } 
}

void work(){
  unsigned long long number = T[ change ];

  if ( number == 1 ) {
    cout << "There is only 1 way to produce " << change << " cents change." << endl;
  } else {
    cout << "There are " << number << " ways to produce " << change << " cents change." << endl;
  }
}
int read(){
  if ( !( cin >> change ) ) return false;
  return true;
}

main(){
  init();
  while ( read() ){
    work();
  }
}
// @end_of_source_code
