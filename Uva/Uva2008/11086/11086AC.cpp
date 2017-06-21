#include<stdio.h>
#include<iostream>
using namespace std;
#define MAX (1<<20) + 1
typedef unsigned long long llong;

bool M[MAX];

void init(){
    for ( int i = 0; i < MAX; i++ ) M[i] = false;

    for ( llong x = 2; x <= MAX/2 + 1; x++ ){
	for ( llong y = x; x*y < MAX; y++ ){
	    M[x*y] = true;
	}
    }

    for ( llong i = 4; i < MAX; i++ ){
	if ( !M[i] ) continue;
	for ( llong j = i*2; j < MAX; j += i ) M[j] = false;
    }
}

int main(){
    init();

    int n, x;
    while( scanf("%d", &n) != EOF ){
	int sum = 0;
	for ( int i = 0; i < n; i++ ){
	    scanf("%d", &x);
	    if ( M[x] ) sum++;
	}
	printf("%d\n", sum);
    }

    return 0;
}
