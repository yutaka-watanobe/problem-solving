#include<stdio.h>
#define MAX 50

int main(){
    int B[MAX], n, sum, h, tcase;
    tcase = 1;
    while(1){
	scanf("%d", &n);
	if ( n == 0 ) break;
	sum = 0;
	for ( int i = 0; i < n; i++ ){
	    scanf("%d", &B[i]); sum += B[i];
	}
	h = sum/n;
	sum = 0;
	for ( int i = 0; i < n; i++ ){
	    if ( B[i] > h ) sum += (B[i] - h);
	}
	printf("Set #%d\n", tcase++);
	printf("The minimum number of moves is %d.\n\n", sum);
    }
    return 0;
}
