#include<cstdio>
main(){
    int n, x, t = 1;
    while(1){
	scanf("%d", &n);
	if ( n < 0 ) break;
	x = 1;
	int i;
	for ( i = 0; ;i++ ){
	    if ( x >= n ) break;
	    x *= 2;
	}
	printf("Case %d: %d\n", t++, i);

    }
}
