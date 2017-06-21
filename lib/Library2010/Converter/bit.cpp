#include<iostream>
#include<vector>
#include<cassert>
using namespace std;


void rec(int n, vector<int> &v){
  if ( n == 0 ) return;
  rec(n/2, v);
  v.push_back(n%2);
}

main(){
  double x;
  int n;
  vector<int> bit, bit2;
  cin >> n >> x;
  assert( x < 1.0 );

  rec(n, bit2);

  while(1){
    if ( x == 0 ) break;
    x *= 2;
    if ( x >= 1.0 ) { bit.push_back(1); x -= 1; }
    else bit.push_back(0);
  }

  for ( int i = 0; i < bit.size(); i++ ) cout << bit[i];
  cout << endl;

  for ( int i = 0; i < bit2.size(); i++ ) cout << bit2[i];
  cout << endl;
}
