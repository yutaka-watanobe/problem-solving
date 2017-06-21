// begin_of_source
#include<stdio.h>
#define MAX 50

int n, r;
int D[MAX+1], tmp[MAX+1];

void cut( int p, int c ){
    int i;
    for ( i = p; i < p + c; i++ ) tmp[i-p+1] = D[i];
    for ( i = 1; i < p; i++ ) tmp[i+c] = D[i];
    for ( i = 1; i < p + c; i++ ) D[i] = tmp[i];
}

void simulate(){
    int p, c, i, rest;

    for ( i = 1; i <= n; i++ ) { D[i] = n-i+1; }
    for ( i = 0; i < r; i++ ){
	scanf("%d %d", &p, &c);
	cut( p, c );
    }
    
    printf("%d\n", D[1]);
}

int input(){
    scanf("%d %d", &n, &r);
    if ( n == 0 && r == 0 ) return 0;
    return 1;
}

int main(){
    while ( input() ) simulate();
    return 0;
}
// end_of_source
