#include<iostream>
#include<set>
using namespace std;

void gen(int n){
  cout << n << endl;
  set<int> s;

  while( s.size() < n ) s.insert( rand()%100 + 1);

  bool isf = true;
  for ( set<int>::iterator it = s.begin(); it != s.end(); it++ ){
    if ( !isf ) cout << " ";
    isf = false;
    cout << *it;
  }
  cout << endl;
  
}

main(){
  for ( int i = 0; i < 20; i++ ){
    gen(50);
  }
  cout << 0 << endl;
}
