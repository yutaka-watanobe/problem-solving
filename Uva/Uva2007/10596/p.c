// @JUDGE_ID:  17051CA  10596  C++
// @begin_of_source_code
/* may be wrong judge */
/* connected component?? */
#include<stdio.h>
#include<iostream>
#define MAX 205

class MorningWalk{
 public:
  int degree[MAX];

  int N, R;

  bool read(){
    int source, target;
    cin >> N;
    if ( cin.eof() ) return false;
    cin >> R;
    for ( int i = 0; i < N; i++ ){
      degree[i] = 0;
    }
    
    for ( int i = 0; i < R; i++ ){
      cin >> source >> target;
      degree[source]++;
      degree[target]++;
    }

    return true;
  }

  bool check(){
    for ( int i = 0; i < N; i++ ){
      if ( degree[i] % 2 != 0 || degree[i] == 0 ) return false;
    }
    return true;
  }

  void work(){
    if ( !check() ) printf("Not Possible\n");
    else printf("Possible\n");
  }

};

main(){
  MorningWalk MW;

  while ( MW.read() ) MW.work();
}

// @end_of_source_code


