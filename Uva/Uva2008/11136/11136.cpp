#include<stdio.h>
#define MAX 1000001

int T[MAX];

void getNumber(int &x){
    char ch;
    x = 0;
    while(1){
	ch = getchar();
	if ( ch == ' ' || ch == '\n' ) break;
	x *= 10; x += (ch - '0');
    }
}

int main(){
    int n, minv, maxv, k, v;
    long long cost;
    int MAXV = (1<<30);
    for ( int i = 1; i <= MAX; i++ ) T[i] = 0;
    T[0] = T[MAX] = MAXV;
    while(1){
	getNumber(n);
	if ( n == 0 ) break;

	// init
	
	minv = MAX;
	maxv = 0;
	cost = 0;

	for ( int i = 0; i < n; i++ ){
	    getNumber(k);
	    for ( int j = 0; j < k; j++ ){
		getNumber(v);
		T[v]++;
		if ( v < minv ) minv = v;
		if ( v > maxv ) maxv = v;
	    }
	    cost += (maxv - minv);
	    T[maxv]--;
	    T[minv]--;
	    while( T[maxv] == 0 ) maxv--;
	    while( T[minv] == 0 ) minv++;
	}

	for ( int i = minv; i <= maxv; i++ ) T[i] = 0;
	printf("%lld\n", cost);
    }
}
