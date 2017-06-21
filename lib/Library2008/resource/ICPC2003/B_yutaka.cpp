#include<iostream>
using namespace std;
#define MAX 32768

int T[MAX+1];

main(){
    for ( int i = 1; i <= MAX; i++ ) T[i] = 0;
    for ( int i = 0; i*i <= MAX; i++ ) {
	for ( int j = i; i*i + j*j <= MAX; j++ ) {
	    for ( int k = j; i*i+j*j+k*k <= MAX; k++ ){
		for ( int l = k; i*i+j*j+k*k+l*l <= MAX; l++ ){
		    T[i*i + j*j + k*k + l*l]++;
		}
	    }
	}
    }

    int n;

    while (1){
	cin >> n;
	if ( n == 0 ) break;
	cout << T[n] << endl;
    }
}
