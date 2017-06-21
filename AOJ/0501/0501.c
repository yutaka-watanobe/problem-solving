#include<stdio.h>
#define MAX 512
int main(){
    int n, m, i;
    char T[MAX], s, t;

    sleep(3); // no effect
    while(1){
	scanf("%d", &n);
	if ( n == 0 ) break;
	for ( i = 0; i < MAX; i++ ) T[i] = 0;
	for ( i = 0; i < n; i++ ){
	    scanf("\n%c %c", &s, &t);
	    T[s] = t;
	}
	scanf("%d", &m);
	for ( i = 0; i < m; i++ ){
	    scanf("\n%c", &s);
	    if ( T[s] == 0 ) printf("%c", s);
	    else printf("%c",  T[s]);
	}
	printf("\n");
    }
    return 0;
}
