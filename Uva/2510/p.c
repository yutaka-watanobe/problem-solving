// @JUDGE_ID:  17051CA  2510  C++
// @begin_of_source_code
/* Toppology */
#include<stdio.h>
#include<iostream>

class BeerLand{
 public:
  int n;

  int compute(){
    if ( n <= 3 ) return 0;
    if ( n % 2 == 0 ){
      return ( ( n - 1 ) / 2 - 1 ) * n + 1;
    } else {
      return ( n / 2 - 1 ) * n;
    }
  }

  void work(){
    cout << compute() << endl;
  }

  void read(){
    cin >> n;
  }

};

main(){
  int tcase;
  cin >> tcase;

  BeerLand land;
  
  for ( int i = 0; i < tcase; i++ ){
    land.read();
    land.work();
  }
}

// @end_of_source_code


