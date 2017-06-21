#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<set>
using namespace std;
#define MAX 50

typedef  unsigned long long llong;

llong C[MAX];
int n;
set<llong> LCM;

llong gcd2(llong x, llong y){
    if ( y == 0 ) return x;
    return gcd2(y, x%y );
}

llong gcd( llong x, llong y ){
    llong r;
    
    if ( x < y ) swap( x, y );
    
    while ( y > 0 ){
	r = x % y;
	x = y;
	y = r;
    }
    
    return x;
}


llong lcm( llong x, llong y ){
    if ( x < y ) swap(x, y);
    return x*y/gcd(x, y);
}

void initialize(){
    LCM = set<llong>();
    for ( int i = 0; i < n-3; i++ )
	for ( int j = i+1; j < n-2; j++ )
	    for ( int k = j+1; k < n-1; k++ )
		for ( int l = k+1; l < n; l++ )
		    LCM.insert(lcm(lcm(C[i], C[j]), lcm(C[k], C[l])));
}


void compute(){
    llong g, s, t;
    scanf("%lld", &t);
    llong greatest = 0;
    llong smallest = INT_MAX;
    
    for ( set<llong>::iterator it = LCM.begin(); it != LCM.end(); it++ ){
	llong l = *it;
	if ( t % l == 0){
	    g = s = t;
	} else {
	    g = t - t % l;
	    s = t + l - t % l;
	}

	if ( g <= t ) greatest = max(greatest, g);
	if ( s >= t ) smallest = min(smallest, s);
	if ( l > t ) break;
    }

    printf("%lld %lld\n", greatest, smallest );
}

int main(){
    int  t;
    while(1){
	scanf("%d %d", &n, &t);
	if ( n == 0 && t == 0 ) break;
	for ( int i = 0; i < n; i++ ) scanf("%lld", &C[i]);
	initialize();
	for ( int i = 0; i < t; i++ ) compute();
    }
    return 0;
}
