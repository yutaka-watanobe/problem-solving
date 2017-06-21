#include<iostream>
using namespace std;
#define MAX 100

int n, T[MAX][MAX];

int main(){
    int tcase = 1;
    while( cin >> n && n ){
	cout << "Case " << tcase++ << ":";
	for ( int i = 0; i < n; i++ )
	    for ( int j = 0; j < n; j++ ) cin >> T[i][j];

	for ( int s = 0; s <= n/2 -1; s++ ){
	    int sum = 0;
	    for ( int j = s; j < n-s; j++ ){
		sum += T[s][j];
		sum += T[n-s-1][j];
	    }
	    for ( int i = s+1; i < n-s-1; i++ ){
		sum += T[i][s];
		sum += T[i][n-s-1];
	    }
	    cout << " " << sum;
	}
	if ( n % 2 == 1 ) cout << " " << T[n/2][n/2];
	cout << endl;

    }
    return 0;
}
