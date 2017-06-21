// @JUDGE_ID:  17051CA  10252  C++
// @begin_of_source_code
/* String */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#define MAX 1001

class CommonPermutation{
 public:
  string line1, line2;
  int used[ MAX ];

  void work(){
    sort( line1.begin(), line1.end() );
    sort( line2.begin(), line2.end() );

    for ( int i = 0; i < line2.size(); i++ ) used[i] = false;

    for ( int i = 0; i < line1.size(); i++ ){
      char ch = line1[i];
      for ( int j = 0; j < line2.size(); j++ ){
	if ( used[j] ) continue;

	if ( ch == line2[j] ){
	  used[j] = true;
	  cout << ch;
	  goto next;
	}
      }
    next:;
    }
    cout << endl;
  }

  bool read(){
    getline( cin, line1 );
    if ( cin.eof() ) return false;
    getline( cin, line2 );
    return true;
  }
};

main(){
  CommonPermutation CP;
  while ( CP.read() ){
    CP.work();
  }
}
// @end_of_source_code
