#include<iostream>
using namespace std;

void eratos( int n, bool prime[] ){
    for ( int i = 0; i <= n; i++ ) prime[i] = true;
    prime[0] = prime[1] = false;
    for ( int i = 2; i*i <= n; i++ ){
	if ( prime[i] )
	    for ( int j = 2; i*j <= n; j++ ) prime[i*j] = false;
    }
}

main(){
    bool prime[110000];
    eratos(110000, prime);
    int T[10001];
    int k = 1;
    for ( int i = 2;; i++ ){
	if ( !prime[i] ) continue;
	T[k++] = i;
	if ( k == 10001 ) break;
    }
    int n;
    while( cin >> n && n ){
	int sum = 0;
	for ( int i = 1; i <= n; i++ ) sum += T[i];
	cout << sum << endl;
    }
    
}
