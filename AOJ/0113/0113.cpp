#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;

int main(){
    int p, q;
    while( cin >> p >> q ){ 
	int rem = p % q;
	map<int, bool> V;
	map<int, int> P;
	V[p] = true;
	V[rem] = true;
	P[p] = 0;
	P[rem] = 1;
	int cur = 1;
	while( rem > 0 ){
	    rem *= 10;
	    cout << rem/q;
	    rem = rem%q;
	    if ( V[rem] ) {
	      int s= P[rem];
	      cout << endl;
	      for ( int i = 0; i < s-1; i++ ) cout << " ";
	      for ( int i = s; i <= cur; i++ ) cout << "^";
	      break;
	    }
	    V[rem] = true;
	    P[rem] = ++cur;
	}
    	cout << endl;
    }
    return 0;
}
