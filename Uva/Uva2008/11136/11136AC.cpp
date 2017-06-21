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
    while(1){
	scanf("%d", &n);
	if ( n == 0 ) break;

	// init
	for ( int i = 1; i <= MAX; i++ ) T[i] = 0;
	T[0] = T[MAX] = (1<<30);
	minv = MAX;
	maxv = 0;
	cost = 0;

	for ( int i = 0; i < n; i++ ){
	    scanf("%d", &k);
	    for ( int j = 0; j < k; j++ ){
		scanf("%d", &v);
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

	printf("%lld\n", cost);
    }
}
