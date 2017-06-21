// @JUDGE_ID:  17051CA  561  C++
// @begin_of_source_code
/* Logic */
#include<stdio.h>
#include<string>
#include<iostream>
#include<stl.h>

int x, y, z;
string X, Y, Z;
int XC[26];
int YC[26];
int ZC[26];

void read(){
  fill ( XC, XC + 26, 0 );
  fill ( YC, YC + 26, 0 );
  fill ( ZC, ZC + 26, 0 );

  cin >> x >> y >> z;
  cin >> X >> Y >> Z;
}

void work(){
  for ( int i = 0; i < x; i++ ){
    XC[ X[i] - 'A' ]++;
  }
  for ( int i = 0; i < y; i++ ){
    YC[ Y[i] - 'A' ]++;
  }
  for ( int i = 0; i < z; i++ ){
    ZC[ Z[i] - 'A' ]++;
  }

  int total = 0;
  for ( int i = 0; i < 26; i++ ){
    total += XC[i] * YC[i] * ZC[i] * 34;
  }

  printf( "%.4f\n", 1.0 * total / ( x * y * z ) ) ;
}

main(){
  int t;
  cin >> t;
  for ( int i = 0; i < t; i++ ){
    read();
    work();
  }
}
// @end_of_source_code
