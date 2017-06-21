#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
#define MAX 32

long long T[MAX];
int N;

void init(){
    long long p = 1;
    for ( int i = 0; i < MAX; i++ ){
	T[i] = p;
	p *= 2;
    }
    //for ( int j = 0; j < MAX; j++ ) cout << T[j] << endl;
}

bool match(int t, int s){
    if ( s == 0 ) return false;
    //    cout << t << " - " << s << endl;
    int sd = (int)log10(s) + 1;
    int td = (int)log10(t) + 1;
    for ( int i = 0; i < td/2+1; i++ ) t /= 10;
    if ( t <= 0 ) return false;
    td = (int)log10(t) + 1;
    for ( int i = 0; i < td - sd; i++ ) t /= 10;
    return t == s;
}

void compute(){
    for ( int i = 1; i < 32; i++ ){
	if ( match(T[i], N) ){
	    printf("%d\n", i); return;
	}
    }
    printf("no power of 2\n");
}

int main(){
    init();
    while( scanf("%d", &N) != EOF ){
	compute();
    }
}
