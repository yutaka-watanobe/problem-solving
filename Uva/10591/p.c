// @JUDGE_ID:  17051CA  10591  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#define MAX 1000

class HappyNumber{
 public:

  bool compute( int N ){
    int current = N;
    bool used[ MAX ];
    for ( int i = 0; i < MAX; i++ ) used[i] = false;

    int sum, s;
    while ( 1 ){

      sum = 0;
      while ( 1 ){
	if ( current < 10 ){
	  sum += current * current;
	  goto next;
	} else {
	  s = current % 10;
	  current /= 10;
	  sum += s * s;
	}
      }
    next:
      current = sum;

      if ( current == 1 ) return true;
      if ( used[ current ] ) return false;
      used[ current ] = true;
    }

  }

  void work( int tcase ){
    int N;
    cin >> N;
    cout << "Case #" << tcase << ": " << N << " is ";
    if ( compute( N ) ) cout << "a Happy number." << endl;
    else cout << "an Unhappy number." << endl;
  }

};

main(){
  HappyNumber HN;
  int tcase;
  cin >> tcase;
  for ( int i = 1; i <= tcase; i++ ){
    HN.work( i );
  }
}

// @end_of_source_code


