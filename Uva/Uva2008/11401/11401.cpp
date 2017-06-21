#include<iostream>
using namespace std;
typedef unsigned long long ullong;

static const int MAX = 1000000;

ullong T[MAX+1];

void init(){
    T[0] = T[1] = T[2] = T[3] = 0;
    T[4] = 1;
    T[5] = T[4] + 2;
    for ( ullong n = 6; n <= MAX; n++ ){
	if ( n % 2 == 0 ){
	    T[n] = T[n-1] + ((n-2)*(n-2)/4);	
	} else {
	    T[n] = T[n-1] + ((n-3)*(n-1)/4);
	}
    }
}

main(){
    init();
    ullong n;
    while( cin >> n && n >= 3 ){
	cout << T[n] << endl;
    }
}

// comment
/*
Mathematics + DP
Sn = (1/2)n(2a+(n-1)d)
*/
