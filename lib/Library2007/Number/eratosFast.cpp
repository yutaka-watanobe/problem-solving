#include<iostream>
#define MAX 1000000
using namespace std;

void eratos ( int n, bool prime[]){
    for ( int i = 0; i <= n; i++ ) prime[i] = false;
    for ( int i = 3; i <= n; i += 2 ) prime[i] = true;
    prime[2] = true;
    int limit = (int)sqrt((double)n) + 1;
    for ( int i = 3; i <= limit; i += 2 ){
	if ( !prime[i] ) continue;
	for ( int j = i * i, k = i * 2; j <= n; j += k ) 
	    prime[j] = false;
    }
}

int main(void){
    bool prime[MAX + 1];
    int size;
    eratos( size, prime );
    for ( int i = 0; i < size; i++ ) {
	if ( prime[i] ) cout << i << " ";
    }
    cout << endl;

    return 0;
}
