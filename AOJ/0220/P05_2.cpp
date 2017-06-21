#include<iostream>
using namespace std;

void convert(int x, int p){
    if ( p == 12 ) return;
    convert(x/2, p+1);
    if ( p == 3 ) cout << ".";
    cout << x%2;
}

int main(){
    for ( double x; cin >> x && x >= 0; ){
	int shift = (int)(x*16);
	if ( x == shift/16.0 && shift < 4096 ){
	    convert(shift, 0);
	    cout << endl;
	} else {
	    cout << "NA" << endl;
	}
    }
    return 0;
}
