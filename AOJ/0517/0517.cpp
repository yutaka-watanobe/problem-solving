#include<iostream>
using namespace std;
#define MAX 100000

int T[MAX+1], L[MAX+2], R[MAX+2];
int n, k;
bool hasEmpty;

int compute(){
    T[0] = 0;

    for ( int i = 1; i <= n; i++ ) L[i] = R[i] = 0;

    L[0] = L[n+1] = 0;
    R[0] = R[n+1] = 0;

    for ( int i = 1; i <= n; i++ ){
	if ( T[i] == 0 ) L[i] = 0;
	else L[i] += L[i-1] + 1;
    }
    for ( int i = n; i >= 1; i-- ){
	if ( T[i] == 0 ) R[i] = 0;
	else R[i] += R[i+1] + 1;
    }
    
    /*
    for ( int i = 0; i <= n+1; i++ ) cout << L[i] << " ";
    cout << endl;
    for ( int i = 0; i <= n+1; i++ ) cout << R[i] << " ";
    cout << endl;
    */

    int maxv = 0;
    for ( int i = 1; i <= n; i++ ) maxv = max( maxv, L[i] );

    if ( hasEmpty ){
	for ( int i = 1; i <= n; i++ ) {
	    if ( T[i] == 0 ){
		maxv = max( maxv, L[i-1] + R[i+1] + 1);
	    }
	}
    }
    
    return maxv;
}

int main(){
    int x;
    while(1){
	cin >> n >> k;
	if ( n == 0 && k == 0 ) break;
	
	for ( int i = 1; i <= MAX; i++ ) T[i] = 0;

	hasEmpty = false;
	for ( int i = 0; i < k; i++ ){
	    cin >> x; T[x] = 1;
	    if ( x == 0 ) hasEmpty = true;
	}
	cout << compute() << endl;
    }
    return 0;
}
