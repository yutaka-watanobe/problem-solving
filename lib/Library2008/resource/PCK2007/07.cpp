#include<iostream>
using namespace std;
#define MAX 7

int m, n, counter;
int value[MAX], amount[MAX];

void recursive( int k, int v ){
    if ( v == n ) {
	counter++; return;
    } else if ( v > n || k >= m ) return;
    
    for ( int a = 0; a <= amount[k]; a++ ){
	recursive( k + 1, v + value[k]*a );
    }
}

int main(){
    while( cin >> m, m ){
	for ( int i = 0; i < m; i++ ){
	    cin >> value[i] >> amount[i];
	}
	int g; cin >> g;
	for ( int i = 0; i < g; i++ ){
	    cin >> n;
	    counter = 0;
	    recursive(0, 0);
	    cout << counter << endl;
	}
    }
    return 0;
}
