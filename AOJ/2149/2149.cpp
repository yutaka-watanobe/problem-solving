#include<iostream>
using namespace std;
#define MAX 100
main(){
    int N, A, B, C, X, L[MAX];
    while( cin >> N >> A >> B >> C >> X && N ){
	for ( int i = 0; i < N; i++ ) cin >> L[i];
	int p = 0;
	for ( int f = 0; f <= 10000; f++, X = (A*X+B)%C ){
	    if ( L[p] == X ) p++;
	    if ( p >= N ) { cout << f << endl; break; }
	}
	if ( p < N ) cout << -1 << endl;
    }
}
