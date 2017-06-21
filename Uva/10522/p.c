// @JUDGE_ID:  17051CA  10522  C++
// @begin_of_source_code
/* Geometory */
/* Helon's formula */
#include<stdio.h>
#include<iostream>
#include<cmath>

double Ha, Hb, Hc;
int n;
int cnt;

int read(){
  cin >> Ha >> Hb >> Hc;
  if ( cin.eof() ) return 0;
  return 1;
}

bool work(){

  if ( Ha == 0 || Hb == 0 || Hc == 0 ){
    cout << "These are invalid inputs!" << endl;
    cnt++;
    if ( cnt == n ) return false;
    else return true;
  }

  double X;
  X = ( Ha*Hb + Hb*Hc + Ha*Hc ) / ( Ha*Hb*Hc );

  double S;
  double Y =  ( X*( X - 2/Ha)*( X - 2/Hb)*( X - 2/Hc) );
  S = 1 / Y;
  
  if ( Y <= 0  ){
    cout << "These are invalid inputs!" << endl;
    cnt++;
  }
  else printf("%.3f\n", sqrt( S ) );

  if ( cnt == n ) {
    return false;
  }
  return true;
}


main(){
  cin >> n;
  cnt = 0;
  while ( 1 ){
    read();
    if ( !work() ) break;
  }
}

// @end_of_source_code
