#include<stdio.h>

int main(){
    int tcase, n; 
    scanf("%d", &tcase);
    for ( int i = 0; i < tcase; i++ ){
	scanf("%d", &n);
	n = (((n*567)/9 + 7492)*235)/47 - 498;
	if ( n < 0 ) n *= -1;
	printf("%d\n", (n%100 - n%10)/10);
    }
}
