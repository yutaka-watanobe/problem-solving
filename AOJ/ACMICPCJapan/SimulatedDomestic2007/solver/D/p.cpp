// Problem D: Square Route
// @author yutaka
// @version 1: line classification
#include<iostream>
using namespace std;
#define MAX 1500
#define VMAX 1500000

int H[MAX], W[MAX], CH[VMAX+1], CW[VMAX+1];
int N, M;

int compute(){
    for ( int i = 0; i < VMAX + 1; i++ ) CH[i] = CW[i] = 0;

    for ( int i = 0; i < N; i++ ){
	for ( int t = 0, j = i; j < N; j++ ) {t += H[j]; CH[t]++;}
    }
    for ( int i = 0; i < M; i++ ){
	for ( int t = 0, j = i; j < M; j++ ) {t += W[j]; CW[t]++;}
    }
    
    int total = 0;
    for ( int i = 0; i <= VMAX+1; i++ ) total += (CH[i]*CW[i]);

    return total;
}

main(){
    while(1){
	cin >> N >> M;
	if ( N == 0 && M == 0 ) break;
	for ( int i = 0; i < N; i++ ) cin >> H[i];
	for ( int i = 0; i < M; i++ ) cin >> W[i];
	cout << compute() << endl;
    }
}
