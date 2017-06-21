#include<iostream>
using namespace std;

void convert(int x){
    if ( x == 0 ) return;
    convert(x/4); cout << x%4;
}

main(){
    int n;
    while( cin >> n && n >= 0 ) {
	if ( n == 0 ) cout << 0 << endl;
	else {
	    convert(n); cout << endl;
	}
    }
}
