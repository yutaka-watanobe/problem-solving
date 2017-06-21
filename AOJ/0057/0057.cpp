/*
  S(n) = R(n-1) + S(n-1)
  = n + S(n-1)
  = sig k + S(0) = n(n+1)/2 + 1
 */
#include<iostream>
using namespace std;

main(){
    int n;
    while( cin >>n ){
	cout << n*(n+1)/2 + 1 << endl;
    }
}
