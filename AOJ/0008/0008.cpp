#include<iostream>
using namespace std;
main(){
    int n;
    while( cin >> n ){
	int sum = 0;
	for ( int i = 0; i < 10; i++ ){
	    for ( int j = 0; j < 10; j++ ){
		for ( int k = 0; k < 10; k++ ){
		    if ( i + j + k > n ) continue;
		    int m = n - (i+j+k);
		    if ( 0 <= m && m <= 9 ) sum++;
		}
	    }
	}
	cout << sum << endl;
    }
}
