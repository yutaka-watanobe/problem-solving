// prime + calculation
// fuckin input. 1 is prime ?
#include<iostream>
#include<string>
#include<algorithm>
#define MAX 1100

bool prime[MAX+1];
void eratos( int n){
    fill(prime, prime+MAX, false);
    /* 奇数を素数候補とする */
    for ( int i = 3; i <= n; i += 2 ) prime[i] = true;
    prime[2] = true;
    
    /* 合成数でない奇数だけを残す */
    for ( int i = 3, limit = (int)sqrt(n); i <= limit; i += 2 ) {
	if ( !prime[i] ) continue;
	
	for ( int j = i * i, k = i * 2; j <= n; j += k ) prime[j] = false;
    }
}

string line;

int getValue( char ch ){
    if ( 'a' <= ch && ch <= 'z' ){
	return (ch - 'a') + 1;
    } else {
	return (ch - 'A') + 27;
    }
}

void compute(){
    int sum = 0;
    for ( int i = 0; i < line.size(); i++ ) sum += getValue( line[i] );

    if( prime[sum] ) cout << "It is a prime word." << endl;
    else cout << "It is not a prime word." << endl;
}

main(){
    eratos(MAX);
    prime[1] = true;
    while ( cin >> line ) compute();
}
