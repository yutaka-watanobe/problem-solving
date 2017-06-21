#include<stdio.h>

int w, n;

void print(){
    int size = n*w;
    for ( int i = 0; i < size; i++ ){
	for ( int j = 0; j <= size+i; j++ ){
	    if ( j >= size-i-1 &&  (j + i%w + 1 - w*(n-i/w))%(2*w) == 0 ){
		//printf("/");
		putchar('/');
	    } else if ( j >= size-i-1 && (j - i%w - w*(n-i/w))%(2*w) == 0 ){
		//printf("\\");
		putchar('\\');
	    } else if ( (i+1) % w == 0 && j >= size-i-1 ) {
		//printf("_");
		putchar('_');
	    } else {
		//printf(" ");
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
