#include<iostream>
using namespace std;

main(){
    int n, x;
    while( cin >> n ){
	if ( n == 0 ) break;
	int sum = 0;
	for ( int i = 0; i < n/4; i++ ){
	    cin >> x; 
	    sum += x;
	}
	cout << sum << endl;
    }
}
