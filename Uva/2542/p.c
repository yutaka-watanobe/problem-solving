// @JUDGE_ID:  17051CA  2542  C++
// @begin_of_source_code
/* Simple Calculation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

#define PI 3.14159

class PolarExplore{
 public:
  int radius, gass, angle;

  void work(){
    angle = min( angle, 360 - angle );
    double dist = 2.0 * radius * ( angle * PI / 180.0 );
    
    double required = dist / 5;

    if ( required > gass ){
      cout << "NO " << gass * 5 << endl;
    } else {
      cout << "YES " << (int)(gass - required)  << endl;
    }
    
  }

  bool read(){
    string line;
    cin >> line;
    if ( line == "ENDOFINPUT" ) return false;
    cin >> radius >> gass >> angle;
    cin >> line; /* END */
    return true;
  }
};

main(){
  PolarExplore explore;
  while ( explore.read() ){
    explore.work();
  }
}

// @end_of_source_code


