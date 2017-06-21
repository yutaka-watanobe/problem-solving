#include<iostream>
using namespace std;

void compute(int n){
    int S = 0;


    //    for ( int i = 1; i < n; i++ ){
    //	if ( n % i == 0 ) S += i;
    //	}

    for ( int i = 1; i*i <= n; i++ ){
	if ( n % i == 0 ){
	    if ( i*i == n ) S += i;
	    else S += i + n/i;
	}
    }
    S -= n;

    if ( S == n ) cout << "perfect number" << endl;
    else if ( S > n ) cout << "abundant number" << endl;
    else cout << "deficient number" << endl;
}

int main(){
    int n;
    while( cin >> n && n ){
	compute(n);
    }
}
