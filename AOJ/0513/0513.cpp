#include<iostream>
using namespace std;

#define MAX 200

int C[MAX+2];
int T[MAX+2];
int n;

void riffle(){
    for ( int i = 0; i < 2*n; i++ ) T[i] = C[i];
    for ( int i = 0, j = 0; i < n; i++, j += 2 ) C[j] = T[i];
    for ( int i = n, j = 1; i < 2*n; i++, j += 2 ) C[j] = T[i];

}

void cut( int k ){
    for ( int i = 0; i < 2*n; i++ ) T[i] = C[i];
    for ( int i = 0; i < 2*n-k; i++ ) C[i] = T[i+k];
    for ( int i = 0; i < k; i++ ) C[i + (2*n-k)] = T[i];
}

int main(){
    int m, k;
    cin >> n >> m;
    for ( int i = 0; i < 2*n; i++ ) C[i] = i+1;
    
    for ( int i = 0; i < m; i++ ){
	cin >> k;
	//	    if ( k == 0 ) riffle();
	//	    else cut(k);
    }
    
    for ( int i = 0; i < 2*n; i++ ){
	cout << C[i] << endl;
    }

    return 0;
}
