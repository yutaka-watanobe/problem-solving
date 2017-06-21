#include<iostream>
#include<vector>
#include<algorithm>
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

int key(int n){
    vector<int> factors;
    factorize(n, factors);
    vector<int>::iterator it = unique(factors.begin(), factors.end());
    factors.erase(it, factors.end());

    int sum = 0;
    for ( int i = 0; i < factors.size()-1; i++ ) sum += factors[i];

    return factors.back() - sum;
}

int main(void){
    int a, b;

    while(1){
	cin >> a >> b;
	if ( a == 0 && b == 0 ) break;
	if ( key(a) > key(b) ) cout << "a" << endl;
	else cout << "b" << endl;
    }

    return 0;
}
