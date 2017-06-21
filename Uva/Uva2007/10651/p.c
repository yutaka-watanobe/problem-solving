// @JUDGE_ID:  17051CA  10651  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<map>

class State{
 public:
  int cavities[12];
  int npebble;

  State(){}

  int getValue(){
    int sum = 0;
    int p = 1;
    for ( int i = 11; i >= 0; i-- ){
      if ( cavities[i] == 1 ){
	sum += p;
      }
      p *= 10;
    }
  }
};

class Pebble{
 public:
  State initial;
  int minimum;
  map<int, bool> used;

  void read(){
    char ch;
    int sum = 0;
    for ( int i = 0;  i < 12; i++ ){
      cin >> ch;
      if ( ch == 'o' ) {
	initial.cavities[i] = 1;
	sum++;
      }
      else initial.cavities[i] = 0;
    }
    initial.npebble = sum;

    /* init */
    used.clear();
  }

  void rec( State state ){
    
    used[ state.getValue() ] = true;

    if ( minimum > state.npebble ) minimum = state.npebble;
    

    State nstate;

    for ( int i = 0; i <= 9; i++ ){

      
      if ( state.cavities[i] == 0 && state.cavities[i+1] == 1 && state.cavities[i+2] == 1 ){
	nstate = state;
	nstate.cavities[i] = 1; nstate.cavities[i+1] = 0; nstate.cavities[i+2] = 0;
	nstate.npebble--;
	if ( !used[ nstate.getValue() ] ) rec( nstate );
      }

      if ( state.cavities[i] == 1 && state.cavities[i+1] == 1 && state.cavities[i+2] == 0 ){
	nstate = state;
	nstate.cavities[i] = 0; nstate.cavities[i+1] = 0; nstate.cavities[i+2] = 1;
	nstate.npebble--;
	if ( !used[ nstate.getValue() ] ) rec( nstate );
      }

    }
    

  }

  void work(){
    minimum = INT_MAX;

    rec( initial );

    cout << minimum << endl;
  }

};

main(){
  Pebble P;
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    P.read();
    P.work();
  }
}


// @end_of_source_code


