#include<stdio.h>

int w, n;

void print(){
    int size = n*w;
    int ww = 2*w;
    int d, r;
    for ( int i = 0; i < size; i++ ){
	for ( int j = 0; j <= size+i; j++ ){
	    if ( j >= size-i-1){
		d = i/w; r = i%w;
		if ((j + r + 1 - w*(n-d))%ww == 0 ){
		    putchar('/');
		} else if ( (j - r - w*(n-d))%ww == 0 ){
		    putchar('\\');
		} else if ( (i+1) % w == 0 ) {
		    putchar('_');
		} else {
		    putchar(' ');
		}
	    } else {
		putchar(' ');
	    }
	}
	printf("\n");
    }

}

int main(){
    int tcase = 1;
    while(1){
	scanf("%d %d", &w, &n);
	if ( w == 0 && n == 0 ) break;
	printf("Triangular Museum %d\n", tcase++);
	print();
	printf("\n");
    }
    return 0;
}
