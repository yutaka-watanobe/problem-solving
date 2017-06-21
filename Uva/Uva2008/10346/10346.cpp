#include<stdio.h>

int main(){
    int n, k, butt, sum;
    while( scanf("%d %d", &n, &k) != EOF ){
	sum = butt = 0;
	while( n ){
	    sum += n;
	    butt += n;
	    n = butt/k;
	    butt = butt%k;

	}
	printf("%d\n", sum);

    }
    return 0;
}
