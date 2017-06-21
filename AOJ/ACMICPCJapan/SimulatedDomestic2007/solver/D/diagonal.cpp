// Problem D: Square Route
// @author yutaka
// @version 2: by diagonal lines
#include<iostream>
using namespace std;
#define MAX 1500
#define VMAX 1500000

int H[MAX], W[MAX], D[2*VMAX+1];
int N, M;

int compute(){
    for ( int i = 0; i < 2*VMAX+1; i++ ) D[i] = 0;

    for ( int i = 0, y = 0; i <= N; y -= H[i++] ){
	for ( int j = 0, x = 0; j <= M; x += W[j++] ) D[x+y+VMAX]++;
    }

    int total = 0;
    for ( int i = 0; i < 2*VMAX+1; i++ ) total += D[i]*(D[i]-1)/2;

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
