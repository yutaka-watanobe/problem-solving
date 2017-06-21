// @JUDGE_ID:  17051CA  10646  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

class WhatIsTheCard{
 public:
  vector<string> pile, hand;
  int y;

  void read(){
    pile.clear();
    hand.clear();
    string card;
    for ( int i = 0; i < 27; i++ ){
      cin >> card;
      pile.push_back( card );
    }
    for ( int i = 0; i < 25; i++ ){
      cin >> card;
      hand.push_back( card );
    }

    reverse( pile.begin(), pile.end() );
  }

  int getValue( string card ){
    int x;
    if ( isdigit( card[0] ) ){
      x = card[0] - '0';
    } else {
      x = 10;
    }

    return x;
  }

  void compute(){
    string card = pile[0];
    pile.erase( pile.begin() + 0 );
    int x = getValue( card );
    int w = 10 - x;
    y += x;

    for ( int i = 0; i < w; i++ ){
      pile.erase( pile.begin() + 0 );
    }

    
  }

  void work(){
    y = 0;
    for ( int i = 0; i < 3; i++ ) compute();

    if ( y > pile.size() ) cout << hand[ y-pile.size()-1 ] << endl;
    else cout << pile[pile.size() - y ] << endl;
  }

};

main(){
  WhatIsTheCard WI;

  int tcase;
  cin >> tcase;

  for ( int i = 1; i <= tcase; i++ ){
    cout << "Case " << i << ": ";
    WI.read();
    WI.work();
  }
	
}


// @end_of_source_code


