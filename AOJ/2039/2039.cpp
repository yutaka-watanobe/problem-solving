#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#define MAX 30001
using namespace std;

void eratos ( int n, bool prime[]){
    for ( int i = 0; i <= n; i++ ) prime[i] = false;
    for ( int i = 3; i <= n; i += 2 ) prime[i] = true;
    prime[2] = true;
    int limit = (int)sqrt((double)n) + 1;
    for ( int i = 3; i <= limit; i += 2 ){
	if ( !prime[i] ) continue;
	for ( int j = i + i; j <= n; j += i ) prime[j] = false;
    }
}

int main(void){
    bool prime[MAX + 1];
    int P[MAX];
    eratos( MAX, prime );
    int size = 0;
    for ( int i = 2; i <= MAX; i++ ){
	if ( prime[i] )  P[size++] = i;
    }
    int T;

    while(1){
	scanf("%d", &T);
	if ( T == 0 ) break;
	int sum = 0;
	for ( int i = 0; i < size; i++ ){
	    if ( P[i] > T ) { i = size; continue; }
	    for ( int j = i; j < size; j++ ){
		if ( P[i] + P[j] > T ) { j = size; continue; }
		int th = T - (P[i] + P[j]);
		if ( th >= P[j] && prime[th] ){
		    if ( th < P[i]+P[j] ) sum++;
		}
	    }
	}
	printf("%d\n", sum);
    }
    return 0;
}
