#include<iostream>
using namespace std;
#define MAX 30
typedef unsigned long long ullong;

ullong T[MAX+1];

void init(){
    T[0] = 1;
    T[1] = 0;
    T[2] = 3;
    T[3] = 0;
    T[4] = 11;
    T[5] = 0;
    for ( int i = 6; i <= MAX; i++ ){
	T[i] = T[i-2]*3;// + T[i-4]*2 + T[i-6]*2;
	int p = i;
	if ( p % 2 == 0 ){
	    while(1){
		T[i] += T[i-p]*2;
		p -= 2;
		if ( p <= 2 ) break;
	    }
	}
    }
}

main(){
    init();
    int n;
    while( cin >> n && n != -1 ) cout << T[n] << endl;
}
