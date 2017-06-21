#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 100000

main(){
    int tcase; 
    scanf("%d", &tcase);
    int n, k, pre, lm, rm, p, cur, D[MAX];
    
    for ( int t = 0; t < tcase; t++ ){
	scanf("%d %d", &n, &k);
	scanf("%d", &lm); pre = lm;
	for ( int i = 1; i < n; i++ ) {
	    scanf("%d", &p); D[i-1] = p - pre; pre = p;
	    if ( i == n-1 ) rm = p;
	}
	sort(D, D + (n-1));
	reverse(D, D + (n-1));
	int l = 0;
	for ( int i = 0; i < k-1; i++ ) l += D[i];
	printf("%d\n", max(0, rm-lm-l));
    }
}

