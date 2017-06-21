#include<iostream>
using namespace std;

void parse(int n){
    if ( n == 0 ) return;
    parse(n/3);
    cout << n%3;
}

main(){
    int n;
    while( cin >> n && n >= 0 ){
	if ( n == 0 ) {
	    cout << "0" << endl;
	    continue;
	}
	parse(n);
	cout << endl;
    }
}
