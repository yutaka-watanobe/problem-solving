// @JUDGE_ID:  17051CA  10622  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<stl.h>
#include<cmath>
typedef long long llong;

llong x;

void work(){
  bool nagative = false;
  if ( x < 0 ) {
    x *= -1;
    nagative = true;
  }

  for ( int i = 2, limit = (int)sqrt(x); i <= limit; i++ ){
    if ( x % i != 0 ) continue;

    int p = 0;
    llong current = x;

    while ( 1 ){
      if ( current == i ){
	if ( nagative ){
	  if ( (p+1) % 2 != 0 ){
	    p++; printf("%d\n", p );
	    return;
	  }
	}else{
	  p++; printf("%d\n", p );
	  return;
	}
      } else if ( current % i != 0 ){
	break;
      }
      current /= i;
      p++;
    }
  }
  printf("1\n");

}

bool read(){
  cin >> x;
  if ( x == 0 ) return false;
  return true;
}

main(){
  while ( read() ) work();
}
// @end_of_source_code


