#include<stdio.h>
#include<iostream>
#include<map>
using namespace std;

int N, M, H[1500], W[1500];

void compute(){
    map<int, int> CH, CW;
    map<int, int>::iterator pH, pW;
    int total = 0;

    for ( int i = 0; i < N; i++ ){
	for ( int t = 0, j = i; j < N; j++ ) {t += H[j]; CH[t]++;}
    }
    for ( int i = 0; i < M; i++ ){
	for ( int t = 0, j = i; j < M; j++ ) {t += W[j]; CW[t]++;}
    }

    for ( pH = CH.begin(); pH != CH.end(); pH++ ){
	total += (*pH).second*CW[(*pH).first];
    }

    cout << total << endl;

}

main(){
    while(1){
	scanf("%d %d", &N, &M);
	if ( N == 0 && M == 0 ) break;
	for ( int i = 0; i < N; i++ ) scanf("%d", &H[i] );
	for ( int i = 0; i < M; i++ ) scanf("%d", &W[i] );
	compute();
    }
}