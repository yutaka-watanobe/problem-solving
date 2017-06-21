#include<iostream>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )
#define MAX 300
#define M 10000007
int A[MAX], n;

int compute(){
    int T[MAX][MAX];
    int B[MAX];
    rep(i, n) rep(j, n) T[i][j] = 0;
    rep(i, n) B[i] = 0;

    for ( int i = 1; i < n; i++ ){
	for ( int j = i-1; j >= 0; j-- ){
	    T[i][j] = (T[i][j] + 1)%M;
	    int d = A[i] - A[j];
	    for ( int k = j-1; k >= 0; k-- ){
		if ( A[j] - A[k] == d ) T[i][j] = (T[i][j] + T[j][k])%M;
	    }
	}
    }
    int sum = 0;
    for ( int j = 0; j < n-1; j++ ){
	for ( int i = 1; i < n; i++ ){
	    sum = (sum  + T[i][j])%M;
	}
    }

    sum = (sum+n)%M;
    return sum;

}

main(){
    int tcase; cin >> tcase;

    for ( int i = 1; i <= tcase; i++ ){
	cin >> n;
	for ( int j = 0; j < n; j++ ) cin >> A[j];
	cout << "Case " << i << ": " << compute() << endl;
    }
}
