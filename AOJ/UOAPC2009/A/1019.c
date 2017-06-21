#include<stdio.h>

#define NMAX 100
#define KMAX 100

int check( int S[KMAX], int k ){
    int i;
    for ( i = 0; i < k; i++ ){
	if ( S[i] < 0 ) return 0;
    }
    return 1;
}

main(){
    int n, k, S[KMAX], i, j, c;
    while(1){
	scanf("%d %d", &n, &k);
	if ( n == 0 && k == 0 ) break;
	for ( i = 0; i < k; i++ ) scanf("%d", &S[i]);
	for ( i = 0; i < n; i++ ){
	    for ( j = 0; j < k; j++ ){
		scanf("%d", &c);
		S[j] -= c;
	    }
	}
	
	if ( check(S,k) ) printf("Yes\n");
	else printf("No\n");
    }
}
