// @JUDGE_ID:  17051CA  10012  C++
// @begin_of_source_code
/* miminum value ¡Ì≈ˆ§ø§Í */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

vector<double> R;
vector<double> C;
double smallest;

int read(){
  R.clear();
  C.clear();
  int k;
  cin >> k;
  R.resize( k );
  C.resize( k );
  for ( int i = 0; i < k; i++ ){
    cin >> R[i];
  }
  sort ( R.begin(), R.end() );
}

double getDist(double r1, double r2){
  return sqrt( (r1 + r2)*(r1 + r2) - (r1 - r2)*(r1 - r2) );
}

double howBig(){
  
  C[0] = R[0];
  double longest;

  for ( int i = 1; i < R.size(); i++ ){
    longest = 0;
    for ( int j = 0; j <= i-1; j++ ){
      double d = C[j] + getDist(R[j], R[i] );
      longest = max( longest, d );
    }
    C[i] = longest;
  }

  double left, right;

  left = INT_MAX;
  right = 0;

  for ( int i = 0; i < C.size(); i++ ){
    if ( left > C[i] - R[i] ) { left = C[i] - R[i]; }
    if ( right < C[i] + R[i] ) { right = C[i] + R[i]; }
  }

  return right - left;
}

void work(){
  smallest = INT_MAX;
  do{
    smallest = min( smallest, howBig() );
  }while ( next_permutation ( R.begin(), R.end() ) );
  printf( "%.3f\n", smallest );
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
