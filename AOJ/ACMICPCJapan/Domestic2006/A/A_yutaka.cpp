// @author yutaka C++
// Sieve of Eratosthenes
#include<iostream>
#include<cmath>
#define PMAX 1000000

using namespace std;

void eratos( int n, bool prime[] ){
    for ( int i = 0; i <= n; i++ ) prime[i] = false;
    for ( int i = 3; i <= n; i += 2 ) prime[i] = true;
    prime[2] = true;
    int limit = (int)sqrt((double)n) + 1;
    for ( int i = 3; i <= limit; i += 2 ){
	if ( !prime[i] ) continue;
	for ( int j = i * i, k = i * 2; j <= n; j += k ) prime[j] = false;
    }
}

bool prime[PMAX +1];
int a, d, n;

void compute(){
    int curr = 0;
    for ( int i = a; ; i += d ){
	if ( prime[i] ) curr++;
	if ( curr == n ){
	    cout << i << endl;
	    break;
	}
    }
}

bool input(){
    cin >> a >> d >> n;
    if ( a == 0 && d == 0 && n == 0 ) return false;
    return true;
}

main(){
    eratos( PMAX, prime );
    while ( input() ) compute();
}
