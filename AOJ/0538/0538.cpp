#include<iostream>
#include<string>
using namespace std;
#define MAX 1000000

main(){
    int n, m, T[MAX];
    string str;
    while(1){
	cin >> n;
	if ( n == 0 ) break;
	cin >> m >> str;
	T[0] = T[1] = 0;
	for ( int i = 2; i < m; i++ ){
	    if ( str[i] == 'O' ) T[i] = 0;
	    else {
		if ( str[i-2] == 'I' && str[i-1] == 'O') T[i] = T[i-2] + 1;
		else T[i] = 0;
	    }
	}
	
	int cnt = 0;
	for ( int i = 0; i < m; i++ ){
	    if ( T[i] >= n ) cnt++;
	}
	cout << cnt << endl;

    }
}
