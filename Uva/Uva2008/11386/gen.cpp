#include<iostream>
using namespace std;
main(){
  int n = 5000;
  cout << n << endl;
  int p = 1;

  for ( int i=0; i < n;i++, p += rand()%10000 ) cout << p << " ";
  cout << endl;
}
