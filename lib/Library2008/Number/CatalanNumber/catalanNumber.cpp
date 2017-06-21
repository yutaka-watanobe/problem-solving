// n の上限を検証すること
// solved 991
#include<stdio.h>
typedef long long llong;

llong factorial(int n){
    llong x = 1;
    for ( int i = 2; i <= n; i++ ) x *= i;
    return x;
}

llong getCatalanNumber(int n){
    return factorial(2*n)/factorial(n)/factorial(n+1);
}

int main(){
    int n;
    for(int i = 0; scanf("%d", &n) != EOF; i++ ) {
	if ( i ) printf("\n");
	printf("%lld\n", getCatalanNumber(n));
    }
    return 0;
}
