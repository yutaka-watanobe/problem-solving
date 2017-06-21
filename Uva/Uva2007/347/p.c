// @JUDGE_ID:  17051CA  347  C++
// @begin_of_source_code
/* Number */
/* use Conbination generator */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
typedef unsigned long long ullong;

#define first(n) ((ullong)((1U << (n)) - 1U))

vector<int> V;
vector<int> R;

void is_run( vector<int> &v ){
  vector<int> visited;
  visited.resize( v.size(), 0 );

  int i = 0;
  int u;
  int cnt = 0;
  while ( 1 ){
    if( i == 0 && cnt == V.size() ) break;
    if(visited[i]) return;
    visited[i] = 1; cnt++;
    u = V[i];
    i = ( u + i ) % V.size();
  }

  /* is rounaround number ! */
  int val = 0;
  int p = 1;
  for ( int i = V.size()-1; i >= 0; i-- ){
    val += V[i] * p;
    p *= 10;
  }

  R.push_back( val );
}


ullong nextset(ullong x){
  ullong smallest, ripple, new_smallest, ones;
  smallest = x & -x;
  ripple = x + smallest;
  new_smallest = ripple & -ripple;
  ones = ((new_smallest / smallest) >> 1) -1;
  return ripple | ones;
}

void printset( ullong s, int &n ){
  V.clear();
  for ( int i = 1; i <= n; i++ ){
    if ( s & 1 ) V.push_back(i);
    s >>= 1;
  }
  
  do{
    is_run( V );
  }while ( next_permutation(V.begin(), V.end()) );
}

/**
 * nCk
 */
void generate(int n, int k){
  int i = 1;
  ullong x, y;
  x = first(k);
  while ( !( x & ~first(n) ) ){
    printset(x, n);
    x = nextset(x);
  }
}

void init(){
  for ( int i = 2; i <= 7; i++ ){
    generate(9, i);
  }
  sort( R.begin(), R.end() );
}

int n;
 
int read(){
  cin >> n;
  if ( n == 0 ) return 0;
  return 1;
}

main(){
  init();

  for ( int i = 1; read(); i++ ){
    cout << "Case " << i << ": ";
    cout << *lower_bound( R.begin(), R.end(), n ) << endl;
  }
}
// @end_of_source_code
