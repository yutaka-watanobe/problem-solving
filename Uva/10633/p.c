// @JUDGE_ID:  17051CA  10633  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
typedef unsigned long long ullong;

class RareEasyProblem{
 public:
  ullong NM;

  bool read(){
    cin >> NM;
    if ( NM == 0 ) return false;
    return true;
  }

  void work(){
    ullong ans;

    if ( NM % 9 == 0 ){
      ans = 10 * NM / 9;
      cout << ans - 1 << " " << ans << endl;
      //      if ( (ans - 1) - (ans-1)/10 != NM ) cout << "try1" << endl;
      //      if ( ans - ans/10 != NM ) cout << "try2" << endl;
    } else {
      ans = 10 * (NM / 9) + NM % 9;
      cout << ans << endl;
      //      if ( ans - ans/10 != NM ) cout << "try3" << endl;
    }
  }
};

main(){
  RareEasyProblem REP;
  while ( REP.read() ){
    REP.work();
  }
}

// @end_of_source_code


