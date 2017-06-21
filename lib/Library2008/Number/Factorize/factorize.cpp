#include<iostream>
#include<vector>
using namespace std;

void factorize( int x, vector<int> &factors ){
    int d, q;
    while ( x >= 4 && x % 2 == 0 ) {
	factors.push_back(2);
	x /= 2;
    }
    d = 3; q = x / d;
    while ( q >= d ){
	if ( x % d == 0 ) {
	    factors.push_back(d);
	    x = q;
	} else {
	    d += 2;
	}
	q = x / d;
    }
    factors.push_back(x);
}

int main(void){
    int n; 
    cin >> n;
    vector<int> factors;
    factorize(n, factors);
    for ( int i = 0; i < factors.size(); i++ ){
	if ( i ) cout << " * ";
	cout << factors[i];
    }
    cout << endl;

    return 0;
}

