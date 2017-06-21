// @JUDGE_ID:  17051CA  10550  C++
// @begin_of_source_code
/* Simple Simulation */
#include<stdio.h>
#include<iostream>

int d1, d2, d3, current;

int counterClockWise( int source, int target ){
  if ( source <= target ){
    return target - source;
  } else {
    return 40 - ( source - target );
  }
}

int clockWise( int source, int target ){
  if ( target <= source ){
    return source - target;
  } else {
    return 40 - ( target - source );
  }
}

void work(){
  int rotate1, rotate2, rotate3;
  int sum = 0;
  sum += 720; /* 360 * 2 */

  rotate1 = (clockWise( current, d1 ) * 9 ); 

  sum += rotate1;

  current = d1;

  sum += 360;

  rotate2 =  (counterClockWise( current, d2 ) * 9);

  sum += rotate2;

  current = d2;

  rotate3 = (clockWise( current, d3 ) * 9);
  
  sum += rotate3;

  cout << sum << endl;
}

bool read(){
  cin >> current >> d1 >> d2 >> d3;
  if ( d1 == 0 && d2 == 0 && d3 == 0 && current == 0 ){
    return false;
  }
  return true;
}

main(){
  while ( read() ){
    work();
  }
}

// @end_of_source_code


