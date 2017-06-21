#include<iostream>
#include<cmath>
#define MAX 100003
using namespace std;

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

int main(void){
    bool prime[MAX + 1];
    eratos(MAX, prime);

    int P[MAX];
    int size = 0;
    for ( int i = 2; i <= MAX; i++ ) if ( prime[i] ) P[size++] = i;

    int a, b, m, p, q, maxv, mp, mq;
    while(1){
	cin >> m >> a >> b;
	if ( a == 0 && b == 0 && m == 0 ) break;

	double r = 1.0*a/b;
	maxv = 0;
	mp = mq = -1;
	for ( int i = 0; i < size; i++ ){
	    p = P[i];
	    q = m/p;
	    for ( int q = m/p; q >= p; q-- ){
		if ( !prime[q] ) continue;
		if ( r > 1.0*p/q ) continue;
		if ( maxv < p*q ){
		    maxv = p*q;
		    mp = p;
		    mq = q;
		}
	    }
	}
	cout << mp << " " << mq << endl;

    }

    return 0;
}
