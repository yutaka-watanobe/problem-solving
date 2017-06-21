#include<iostream>
#include<cmath>
using namespace std;
#define M 256

int I[M+1];
int R[M+1];
int O[M+1];
int N;

long double getEntropy( int S, int A, int C ){
    R[0] = S;
    for ( int i = 1; i <= N; i++ ){
	R[i] = (A*R[i-1]+C)%M;
    }
    for ( int i = 1; i <= N; i++ ){
	O[i] = (I[i] + R[i])%M;
    }

    long double H = 0;
    int cnt[M+1];
    for ( int i = 0; i <= M; i++ ) cnt[i] = 0;
    for ( int i = 1; i <= N; i++ ) cnt[O[i]]++;

    for ( int i = 0; i <= M; i++ ){
	if ( cnt[i] > 0){
	    long double x = 1.0*cnt[i]/N;
	    H += x*log(x);
	} 
    }
    return -1*H;
}
#define EPS (1e-12)
void compute(){
    int S, A, C;
    long double minv = (1<<21);
    for ( int s = 0; s <= 15; s++ ){
	for ( int a = 0; a <= 15; a++ ){
	    for ( int c = 0; c <= 15; c++ ){
		long double e = getEntropy(s, a, c);
		if ( minv-EPS > e ){
		    S = s; A = a; C = c;
		    minv = e;
		}
	    }
	}
    }
    cout << S << " " << A << " " << C << endl;
}

main(){
    while(1){
	cin >> N;
	if ( N == 0 ) break;
	for ( int i = 1; i <= N; i++ ) cin >> I[i];
	compute();
    }
}
