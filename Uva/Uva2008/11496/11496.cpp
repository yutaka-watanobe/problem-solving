#include<stdio.h>
#define MAX 10000

int main(){
    int n, M[MAX+2];
    while(1){
	scanf("%d", &n);
	if ( n == 0 ) break;
	for ( int i = 1; i <= n; i++ ) scanf("%d", &M[i]);
	M[n+1] = M[1];
	M[0] = M[n];
	int sum = 0;
	for ( int i = 1; i <= n; i++ ){
	    if ( M[i-1] > M[i] && M[i+1] > M[i] ||
		 M[i-1] < M[i] && M[i+1] < M[i] ) sum++;
	}
	printf("%d\n", sum);
    }
    return 0;
}
