#include<iostream>
using namespace std;
#define MAX 512
int main(){
    int n, m;
    char T[MAX];
    char s, t;
    while( cin >>n && n ){
	for ( int i = 0; i < MAX; i++ ) T[i] = 0;
	for ( int i = 0; i < n; i++ ){
	    cin >> s >> t;
	    T[s] = t;
	}
	cin >> m;
	for ( int i = 0; i < m; i++ ){
	    cin >> s;
	    if ( T[s] == 0 ) cout << s;
	    else cout << T[s];
	}
	cout << endl;
    }
    return 0;
}
