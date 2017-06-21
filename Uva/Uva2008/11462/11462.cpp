#include<stdio.h>
#define MAX 100 // bucket

int main(){
    int T[MAX+1], size, x;

    while(1){
	scanf("%d", &size);
	if ( size == 0 ) break;
	for ( int i = 0; i <= MAX; i++ ) T[i] = 0;
	for ( int i = 0; i < size; i++ ){
	    scanf("%d", &x); T[x]++;
	}
	
	bool isFirst = true;
	for ( int i = 0; i <= MAX; i++ ){
	    for ( int j = 0; j < T[i]; j++ ){
		if ( isFirst ) {
		    printf("%d", i);
		    isFirst = false;
		} else {
		    printf(" %d", i);
		}
	    }
	}
	printf("\n");
    }

    return 0;
}
