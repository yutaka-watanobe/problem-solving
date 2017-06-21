#include<stdio.h>

using namespace std;

main(){
    int d, n;
    int sum;
    while ( scanf("%d", &d) != EOF ){
	sum = 0;
	int lim = 600 - d;
	for ( int x = d; x <= lim; x += d){
	    sum += x*x * d;
	}
	
	printf("%d\n", sum);
    }
}
