#include<iostream>
#include<cmath>
using namespace std;
#define MAX 1000000

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


int main(){
    bool prime[MAX+1];
    eratos(MAX, prime);
    int n, sum, q;
    while( cin >> n && n){
	sum = 0;
	for ( int p = 2; p <= n; p++ ){
	    if ( !prime[p] ) continue;
	    q = n - p;
	    if ( p > q ) break;
	    if ( prime[q] ) sum++;
	}
	cout << sum << endl;
    }
    return 0;
}
