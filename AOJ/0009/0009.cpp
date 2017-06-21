#include<iostream>
#include<cmath>
#define MAX 1000000

using namespace std;

bool prime[MAX+1];
int T[MAX];

void eratos( int n ){
    for ( int i = 0; i < n; i++ ) prime[i] = false;
    for ( int i = 3; i <= n; i += 2 ) prime[i] = true;
    prime[2] = true;
    for ( int i = 3, limit = (int)sqrt(n); i <= limit; i += 2 ) {
	if ( !prime[i] ) continue;
	for ( int j = i * i, k = i * 2; j <= n; j += k ) prime[j] = false;
    }
}

void initialize(){
    eratos( MAX );
    for ( int i = 0; i < MAX; i++ ){
	T[i] = T[i - 1];
	if ( prime[i] ) T[i]++;
    }
}

main(){
    initialize();
    int n;
    while ( cin >> n ) cout << T[n] << endl;
}
