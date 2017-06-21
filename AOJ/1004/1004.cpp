#include<stdio.h>
#include<cmath>
using namespace std;

void eratos( int n, bool prime[]){
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

int main(){
    int N;
    bool prime[10001];
    eratos(10001, prime);

    while( scanf("%d", &N) != EOF){
	int cnt = 0;
	for ( int i = 1; i <= N; i++ ){
	    //	    if ( !prime[i] ) continue;
	    //	    if ( prime[N-i+1] ) cnt++;
	    if ( prime[i] && prime[N-i+1] ) cnt++;
	}
	printf("%d\n", cnt);
	}
    return 0;
}
