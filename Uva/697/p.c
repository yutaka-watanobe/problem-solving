// @JUDGE_ID:  17051CA  697  C++
// @begin_of_source_code
/* Simple calculation + Physics */
/* be careful about floating error ! */
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>

double UP, D, L, B, P, DOWN, V, REQ;

bool read(){
  cin >> UP;
  if ( UP <= 0.0 ) return false;
  cin >> D >> L >> B >> P >> DOWN >> V;
  return true;
}

void compute(){
  double PI = 2.0*acos( 0.0 );

  int nshuttle = (int)ceil( V / B - 0.000000000001 );
  double walkingTime = nshuttle * ( UP + DOWN );

  double r = (D/2) / 12.0; /* inchi --> feet */
  double increaseLevel = ( B /( r*r*PI ) ) * 12.0;
  double depth = L;
  double droppingTime = 0;
  double pullingTime = 0;
  double a = 32.2 * 12.0; /* feet --> inchi */

  for ( int i = 0; i < nshuttle; i++ ){
    droppingTime += sqrt( 2*depth/ a );
    pullingTime += depth / P ;

    depth += increaseLevel;
   }

  REQ = walkingTime + droppingTime + pullingTime;
}

void printResult(){
  cout << "     up hill           "; printf("%8.2lf", UP ); cout << " sec" << endl;
  cout << "     well diameter     "; printf("%8.2lf", D ); cout << " in" << endl;
  cout << "     water level       "; printf("%8.2lf", L ); cout << " in" << endl;
  cout << "     bucket volume     "; printf("%8.2lf", B ); cout << " cu ft" << endl;
  cout << "     bucket ascent rate"; printf("%8.2lf", P ); cout << " in/sec" << endl;
  cout << "     down hill         "; printf("%8.2lf", DOWN ); cout << " sec" << endl;
  cout << "     required volume   "; printf("%8.2lf", V ); cout << " cu ft" << endl;
  cout << "     TIME REQUIRED     "; printf("%8.2lf", REQ ); cout << " sec" << endl;
}

void work(){
  compute();
  printResult();
}

main(){
  for ( int i = 1; read(); i++ ){
    if ( i > 1 ) cout << endl;
    cout << "Scenario " << i << ":" << endl;
    work();

  }
}
// @end_of_source_code
