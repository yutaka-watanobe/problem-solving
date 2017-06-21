#include<iostream>
using namespace std;

main(){
  bool C[3];
  C[1] = C[2] = false;
  C[0] = true;
  char s, t, k;
  while( cin >> s >> k >> t ) swap(C[s-'A'], C[t-'A']);
  if ( C[0] ) cout << "A" << endl;
  if ( C[1] ) cout << "B" << endl;
  if ( C[2] ) cout << "C" << endl;
}
