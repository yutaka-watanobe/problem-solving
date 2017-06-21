#include<stdio.h>
#define MAX 32

void compute(){
    int B[MAX];
    for ( int i = 0; i < MAX; i++ ) B[i] = 0;

    int n; scanf("%d", &n);
    int bit = 0;

    if ( n == 0 ){
	printf("0");
	return;
    }

    bool isMinus = ((n < 0)?true:false);
    if ( isMinus ) n *= (-1);
    int shift = (isMinus)?0:1;

    while(n){
	if ( n%2 ){
	    if ( bit%2 == shift){
		if ( B[bit] == 1 ) B[bit] = 0;
		else B[bit] = B[bit+1] = 1;
	    } else {
		if ( B[bit] == 0 ) {
		    B[bit] = 1;
		} else {
		    B[bit+1] = B[bit+2] = 1;
		    B[bit] = 0;
		}
	    }
	}
	bit++;
	n /= 2;
    }

    int last = MAX-1;
    while( B[last] == 0 ) last--;

    for ( int i = last; i >= 0; i-- ) printf("%d", B[i]);
}

int main(){
    int tcase; scanf("%d", &tcase);
    for ( int i = 1; i <= tcase; i++ ){
	printf("Case #%d: ", i);
	compute();
	printf("\n");
    }
    return 0;
}
