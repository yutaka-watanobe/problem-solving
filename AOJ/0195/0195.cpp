#include<iostream>
using namespace std;

main(){
    int x, y;
    while( cin >> x >> y && x && y ){
	int m = x+y;
	char ch = 'A';
	for ( int i = 1; i < 5; i++ ){
	    cin >> x >> y;
	    if ( x+y > m ){
		m = x+y;
		ch = (char)('A' + i);
	    }
	}
	cout << ch << " " << m << endl;
    }
}
