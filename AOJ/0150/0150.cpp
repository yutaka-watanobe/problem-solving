#include<iostream>
#include<cmath>
using namespace std;

#define LIMIT 10000

void eratos ( int n, bool prime[]){
    for ( int i = 0; i <= n; i++ ) prime[i] = false;
    for ( int i = 3; i <= n; i += 2 ) prime[i] = true;
    prime[2] = true;
    int limit = (int)sqrt((double)n) + 1;
    for ( int i = 3; i <= limit; i += 2 ){
	if ( !prime[i] ) continue;
	for ( int j = i + i; j <= n; j += i ) prime[j] = false;
    }
}

bool prime[LIMIT+1];

void compute( int n ){
    int i;
    for ( i = n; i >= 5; i-- ){
	if ( prime[i] && prime[i-2] ) break;
    }
    cout << i - 2 << " " << i << endl;
}

main(){
    eratos(LIMIT, prime);
    int n;
    while ( cin >> n, n) compute(n);
}
