// @JUDGE_ID:  17051CA  654  C++
// @begin_of_source_code
/* Number - Raional Number */
#include<stdio.h>
#include<iostream>
#include<stl.h>
#include<vector>
#include<cmath>
#define EPS 0.00000001
#define deq(a, b) (fabs(a-b) < EPS)

/*
 * 最大公約数 (Greatest Common Divisor)
 * a > b > 0 を保証すること。
 * 要件: なし
 */
int gcd(int a, int b){
  int tmp;

  if(a<b) swap(a, b);

  while(b){
    a %= b;
    
    tmp = a;
    a = b;
    b = tmp;
  }

  return a;
}

class Ratio{
 public:
  int numerator, denominator;
  vector<pair<int, int> > candidate;
  double error;
  double factor;

  bool addCandidate( int num, int den ){

    int div = gcd( num, den );
    num /= div;
    den /= div;

    double current_error = fabs( factor - 1.0 *num / den );

    for ( int i = 0; i < candidate.size(); i++ ){
      if ( den == candidate[i].second ) return false;
      if ( current_error > error || deq( current_error, error )  ) return false;
    }

    error = current_error;
    candidate.push_back( make_pair( num, den ) );

    if ( num == numerator && den == denominator ) return true;
    return false;
  }

  void work(){
    candidate.clear();

    int div = gcd( numerator, denominator );
    numerator /= div;
    denominator /= div;

    factor = 1.0 * numerator / denominator;
    
    int diameter = 1;
    
    error = INT_MAX;

    while ( 1 ){
      if ( addCandidate( (int)(factor * diameter + 0.5), diameter ) ){
	break;
      }
      diameter++;
    }

    for ( int i = 0; i < candidate.size(); i++ ){
      cout << candidate[i].first << "/" << candidate[i].second << endl;
    }
  }

  bool read(){
    if ( ! ( cin >> numerator >> denominator ) ) return false;
    return true;
  }

};

main(){
  Ratio R;
  for ( int i = 0; R.read(); i++ ){
    if ( i ) cout << endl;
    R.work();
  }
}

// @end_of_source_code


