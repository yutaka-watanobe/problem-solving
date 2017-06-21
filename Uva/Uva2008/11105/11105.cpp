#include<stdio.h>
#define MAX 1000000

int T[MAX+1];

void initialize(){
    bool HP[MAX+1];
    bool HSP[MAX+1];

    for ( int i = 0; i <= MAX; i++ ) HP[i] = HSP[i] = false;
    for ( int i = 5; i <= MAX; i+=4 ) HP[i] = true;

    for ( int i = 1; i*i <= MAX; i+=4 ) {
	if ( !HP[i] ) continue;
	for ( int j = 2; i*j<= MAX; j++ ){
	    HP[i*j] = false;
	}
    }

    for ( int i = 5; i*i <= MAX; i+=4 ){
	if ( !HP[i] ) continue;
	for ( int j = i; j*i <= MAX; j+=4 ){
	    if ( !HP[j] ) continue;
	    HSP[i*j] = true;
	}
    }

    for ( int i = 0; i <= 25; i++ ) T[i] = 0;
    for ( int i = 25; i <= MAX; i++ ){
	if ( HSP[i] ) T[i] = T[i-1] + 1;
	else T[i] = T[i-1];
    }
}

int main(){
    initialize();
    int n;
    while( scanf("%d", &n) && n){
	printf("%d %d\n", n, T[n]);
    }
    return 0;
}
