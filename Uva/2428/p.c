// @JUDGE_ID:  17051CA  2428  C++
// @begin_of_source_code
/* Bisection Method */
#include<stdio.h>
#include<iostream>
#include<cmath>
#include<vector>
#include<stl.h>

class Cistern{
 public:
  double base, height, width, depth;
  Cistern(){}
  Cistern( double base, double height, double width, double depth ):
    base(base), height(height), width(width), depth(depth){
  }

  double getVolume( double h ){
    if ( h <= base ) return 0;

    double level = h - base;
    if ( level > height ) level = height;

    return level * width * depth;
  }
};

class WaterShortage{
 public:
  int N;
  vector<Cistern> cisterns;
  double maxLevel;
  double V;

  double function( double h ){
    double vsum = 0;
    for ( int i = 0; i < N; i++ ){
      vsum += cisterns[i].getVolume( h );
    }
    return vsum - V;
  }

  double bisection(){
    double lower = 0.0;
    double upper = maxLevel * 2;
    double EPS = 0.00001;
    double mid;

    while ( 1 ){
      if ( abs( lower - upper ) <= EPS ) return  lower;
      mid = ( lower + upper ) / 2.0;
      double fc = function( mid );

      if ( fc > 0 ) upper = mid;
      else if ( fc <= 0 ) lower = mid;
    }
  }


  void work(){
    double reach = bisection();

    if ( reach > maxLevel ) cout << "OVERFLOW" << endl;
    else printf("%.2lf\n", reach );
  }

  void read(){
    cin >> N;
    double base, height, width, depth;
    cisterns.clear();
    maxLevel = 0;
    for ( int i = 0; i < N; i++ ){
      cin >> base >> height >> width >> depth;
      maxLevel = max( maxLevel, base + height );
      cisterns.push_back( Cistern( base, height, width, depth ) );
    }
    cin >> V;
  }
  
};

main(){
  WaterShortage WS;
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    if ( i ) cout << endl;
    WS.read();
    WS.work();
  }
}

// @end_of_source_code


