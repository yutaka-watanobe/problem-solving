#include<stdio.h>
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
        for ( int j = i * i, k = i * 2; j <= n; j += k )
        prime[j] = false;
    }
}

int T[MAX];
bool prime[MAX];

bool check( int x, int d){
    static const int dx[7] = {0, 1, 10, 100, 1000, 10000, 100000};
    int p = dx[d];

    if ( !prime[x] ) return false;
    for ( int i = 0; i < d; i++ ){
	x = (x%p)*10 + x/p;
	if ( !prime[x] ) return false;
    }
    
    return true;
}

void init(){
    eratos(MAX, prime);
    
    bool C[MAX];
    for ( int i = 0; i < MAX; i++ ) C[i] = false;
    int x;

    for ( int i = 1; i <= 9; i+=2 ){
	for ( int j = 1; j <= 9; j+=2 ){
	    for ( int k = 1; k <= 9; k+=2 ){
		for ( int l = 1; l <= 9; l+=2 ){
		    for ( int m = 1; m <= 9; m += 2 ){
			for ( int n = 1; n <= 9; n+=2){
			    x = n*100000+m*10000+l*1000+k*100+j*10+i;
			    C[x] = check(x, 6);
			}
			x = m*10000+l*1000+k*100+j*10+i;
			C[x] = check(x, 5);
		    }
		    x = l*1000+k*100+j*10+i;
		    C[x] = check(x, 4);
		}
		x = k*100+j*10+i;
		C[x] = check(x, 3);
	    }
	    x = j*10+i;
	    C[x] = check(x, 2);
	}
	C[i] = check(i, 1);
    }

    T[0] = T[1] = 0;
    T[2] = 1;
    for ( int i = 3; i < MAX; i++ ){
	if ( C[i] ) T[i] = T[i-1] + 1;
	else T[i] = T[i-1];
    }
}

int main(){
    init();
    int a, b;
    while(1){
	scanf("%d", &a);
	if ( a == -1 ) break;
	scanf("%d", &b);
	int cnt = T[b] - T[a-1];
	if ( cnt == 0 ) printf("No Circular Primes.\n");
	else if ( cnt == 1 ) printf("1 Circular Prime.\n");
	else printf("%d Circular Primes.\n", cnt);
    }
    return 0;
}
