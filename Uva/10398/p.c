// @JUDGE_ID:  17051CA  10398  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>

long I;
double S;

double multiplier;

double function( double r ){
  return r*r*r*r*r - r*r*r*r - 1.0;
}

double bisection(){
  double lower, upper, mid;
  lower = 0; upper = 2.0;
  double EPS = 0.000000000000000001;
  
  while ( 1 ){
    mid = ( lower + upper ) /2.0;

    if ( abs( lower - upper ) / 2.0 < EPS ) return mid;

    double fc = function( mid );

    if ( fc > 0 ) upper = mid;
    else if ( fc < 0 ) lower = mid;
    else if ( fc == 0 ) return mid;
  }

}

void work(){
  
  double length = S;
  int digit;
  bool over = false;
  for ( int i = 0; i < I-1; i++ ){
    length *= multiplier;
    digit = (int)ceil(log10( length ));
    if ( digit >= 10 ){
      over = true;
      break;
    }
  }

  if ( !over ){
    cout << floor( length ) << endl;
  } else {
    cout << (long)(log10( S )) + 1 +  (long)((I - 1) * log10( multiplier ))+1   << endl;
  }

}

int read(){
  if ( !(cin >> S >> I ) ) return false;
  return true;
}

main(){
  /* bisection( ); */
  multiplier = 1.32471795724474605827;
  while ( read() ){
    work();
  }
}
// @end_of_source_code
