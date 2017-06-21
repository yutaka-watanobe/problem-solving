#include<stdio.h>

main(){
    int tcase; scanf("%d", &tcase);
    int n, m;
    for ( int i = 0; i < tcase; i++ ){
	scanf("%d %d", &n, &m);
	int cnt = 0;
	while(1){
	    if ( n <= m ){
		if ( n == m ) { cnt++; printf("%d\n", cnt);}
		else printf("cannot do this\n");
		break;
	    }
	    cnt += n/m;
	    n = n/m + n%m;
	}
    }
}
