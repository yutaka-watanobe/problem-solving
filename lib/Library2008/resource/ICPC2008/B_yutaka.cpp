#include<iostream>
using namespace std;
#define MAX 300001

bool prime[MAX];

void generate(){
    fill( prime, prime + MAX, false ) ;
    for ( int i = 1, k = 0; i <= MAX; k++){
	prime[i] = true;
	i += ((k % 2 == 0) ? 5 : 2);
    }
    prime[1] = false;
    for ( int i = 1, k = 0; i * i <= MAX; k++ ){
	if ( prime[i] ) {
	    for ( int j = 2*i; j <= MAX; j += i ) prime[j] = false;
	}
	i += ((k % 2 == 0) ? 5 : 2);
    }
}

main(){
    generate();
    int x;
    while( cin >> x ){
	if ( x == 1 ) break;
	cout << x << ":";
	for ( int i = 1; i <= MAX; i++ ){
	    if ( prime[i] && x % i == 0 ) cout << " " << i;
	}
	cout << endl;
    }
}
