#include<iostream>
#include<algorithm>
using namespace std;
int e[12];

bool check(){
  sort(e, e + 12);
  for ( int i = 0; i < 12; i += 4)
    if ( e[i] != e[i+3] ) return false;
  return true;
}

main(){
  for ( int i = 0; i < 12; i++ ) cin >> e[i];
  if ( check() ) cout << "yes" << endl;
  else cout << "no" << endl;
}
