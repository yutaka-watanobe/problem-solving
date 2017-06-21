// @JUDGE_ID:  17051CA  10421  C++
// @begin_of_source_code
/* Greedy Algorithm */
#include<stdio.h>
#include<iostream>
#include<set>
#include<stl.h>

class Point{
 public:
  int x, y;
  Point(){}
  Point ( int x, int y ): x(x), y(y){}
  
  bool operator < ( const Point &p ) const {
    return x > p.x;
  }
};

int N;
int max_index;
int min_index;
int shift;
int size;

vector<set<int> > S;
vector<Point> P;

int read(){
  cin >> N;
  if ( cin.eof() ) return false;

  S.clear();
  P.clear();
  max_index = 0;
  min_index = INT_MAX;

  int x, y;
  for ( int i = 0; i < N; i++ ){
    cin >> x >> y;
    P.push_back( Point( x, y ) );
    if ( i == 0 ){
      max_index = y;
      min_index = y;
    }else{
      max_index = max( max_index, y );
      min_index = min( min_index, y );
    }
  }

  if ( min_index >= 0 ){
    shift = 0 - min_index;
  } else {
    shift = abs( min_index );
  }

  size = abs(max_index - min_index) + 1;
  if ( N == 0 ) size = 0;

  S.resize( size );
  for ( int i = 0; i < P.size(); i++ ){
    S[ P[i].y + shift ].insert( P[i].x );
  }

  return true;
}

int compute(int i, int j){
  set<int> S1, S2;

  if ( *(S[i].begin()) < *(S[j].begin() ) ){
    S1 = S[i];
    S2 = S[j];
  }else{
    S1 = S[j];
    S2 = S[i];
  }

  if ( S1.size() == 0 && S2.size() == 0 ) return 0;
  if ( S1.size() == 0 || S2.size() == 0 ) return 1;
  
  int pre = 0 - INT_MAX;
  int sum1 = 0;
  int sum2 = 0;
  set<int>::iterator pos;

  while ( 1 ){
    pos = upper_bound( S1.begin(), S1.end(), pre );
    if ( pos == S1.end() ) break;
    sum1++; 
    pre = *pos;
    pos = upper_bound( S2.begin(), S2.end(), pre );
    if ( pos == S2.end() ) break;
    sum1++; 
    pre = *pos;
  }

  if (  *(S[i].begin()) !=  *(S[j].begin()) ) return sum1;

  pre = 0 - INT_MAX;
  while ( 1 ){
    pos = upper_bound( S2.begin(), S2.end(), pre );
    if ( pos == S2.end() ) break;
    sum2++; 
    pre = *pos;
    pos = upper_bound( S1.begin(), S1.end(), pre );
    if ( pos == S1.end() ) break;
    sum2++; 
    pre = *pos;
  }

  return max( sum1, sum2 );
}

void work(){
  int maximum = 0;
  if ( size == 1 ){
    if ( S[0].size() ) maximum = 1;
  }else if ( size == 2 ){
    if ( S[0].size() || S[1].size() ) maximum  = 1;
  }

  for ( int i = 1; i < size-1; i++ ){
    maximum = max( maximum, compute( i-1, i+1 ) );
  }
  cout << maximum << endl;
}

main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code
