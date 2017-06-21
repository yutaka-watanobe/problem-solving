// @JUDGE_ID:  17051CA  10465  C++
// @begin_of_source_code
/* ¡Ì≈ˆ§ø§Í */
#include<stdio.h>
#include<iostream>
#include<stl.h>

class HomerSimpson{
 public:
  int m, n, t;
  HomerSimpson(){}

  void work(){
    int nburger = 0;
    int burgerTime;
    int restTime;
    int maximum_burger = 0;
    int maximum_wasted_burger = 0;
    int beer = t;
    bool wasted = true;

    while ( 1 ){
      burgerTime = nburger * m;
      restTime = t - burgerTime;
      if ( burgerTime > t ) break;
      if ( restTime % n == 0 ){
	maximum_burger = max( maximum_burger, nburger + restTime / n );
	wasted = false;
      } else {
	if ( beer > restTime % n ){
	  maximum_wasted_burger = nburger + restTime / n;
	  beer = restTime % n;
	} else if ( beer == restTime % n ){
	  if ( maximum_wasted_burger < nburger + restTime / n ){
	    maximum_wasted_burger = nburger + restTime / n;
	    beer = restTime % n;
	  }
	}
      }

      nburger++;
    }

    if ( !wasted ){
      cout << maximum_burger << endl;
    } else {
      cout << maximum_wasted_burger << " " << beer << endl;
    }

  }

  bool read(){
    if ( !( cin >> m >> n >> t ) ) return false;
    return true;
  }
};

main(){
  HomerSimpson simpson;
  while ( simpson.read() ){
    simpson.work();
  }
}

// @end_of_source_code


