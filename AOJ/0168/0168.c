#include<stdio.h>

#define MAX 30
int F[MAX+1];

int main(){
    int i, n, p, pp;
    F[0] = 1;
    F[1] = 1;
    F[2] = 2;
    for ( i = 3; i <= MAX; i++ ) F[i] = F[i-3] + F[i-2] + F[i-1];

    while( scanf("%d", &n) && n ){
	p = F[n]/10;
	if ( F[n]%10 ) p++;
	pp = p/365;
	if ( p%356) pp++;
	printf("%d\n", pp);
    }
    return 0;
}
