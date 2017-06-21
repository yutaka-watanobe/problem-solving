#include<iostream>
using namespace std;
#define MAX 32

void compute(){
    int B[MAX];
    for ( int i = 0; i < MAX; i++ ) B[i] = 0;

    int n; cin >> n;
    int bit = 0;

    if ( n == 0 ){
	cout << "0";
	return;
    }

    bool isMinus = ((n < 0)?true:false);

    if ( isMinus ) n *= (-1);

    while(n){
	if ( n%2 ){
	    if ( !isMinus ){
		if ( bit%2 ){
		    if ( B[bit] == 1 ) B[bit] = 0;
		    else B[bit] = B[bit+1] = 1;
		} else {
		    if ( B[bit] == 0 ) {
			B[bit] = 1;
		    } else {
			B[bit+1] = B[bit+2] = 1;
			B[bit] = 0;
		    }
		}
	    } else {
		if ( bit%2 == 0){
		    if ( B[bit] == 1 ) B[bit] = 0;
		    else B[bit] = B[bit+1] = 1;
		} else {
		    if ( B[bit] == 0 ) {
			B[bit] = 1;
		    } else {
			B[bit+1] = B[bit+2] = 1;
			B[bit] = 0;
		    }
		}
		
	    }
	}

	bit++;
	n /= 2;
    }

    int last = MAX-1;
    while( B[last] == 0 ) last--;

    for ( int i = last; i >= 0; i-- ) cout << B[i];

}

int main(){
    int tcase; cin >> tcase;
    for ( int i = 1; i <= tcase; i++ ){
	cout << "Case #" << i << ": ";
	compute();
	cout << endl;
    }
    return 0;
}
