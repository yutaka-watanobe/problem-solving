#include<stdio.h>
#include<iostream>
using namespace std;

#define MAX 43

int F[MAX+1];

void init(){
    F[0] = 1;
    F[1] = 2;
    for ( int i = 2; i <= MAX; i++ ) F[i] = F[i-1] + F[i-2];
}

void compute(){
    int n;
    scanf("%d", &n);
    bool printed = false;
    for ( int i = MAX; i >= 0; i-- ){
	if ( F[i] <= n ) printf("1"), n -= F[i], printed = true;
	else if ( printed ) printf("0");
    }
    printf("\n");
}

int main(){
    init();
    int tcase; scanf("%d", &tcase);
    for ( int i = 0; i < tcase; i++ ) compute();
    return 0;
}
