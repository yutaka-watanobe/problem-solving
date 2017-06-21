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
	if ( x % d == 0 ) { factors.push_back(d); x = q; }
	else d += 2;
	q = x / d;
    }
    factors.push_back(x);
}

void getNumber( vector<int> f ){
    int n2 = 0;
    int n3 = 0;
    vector<int> factor;
    for ( int i = 0; i < f.size(); i++ ){
	if ( f[i] == 2 ) n2++;
	else if ( f[i] == 3 ) n3++;
	else if ( f[i] < 10 ) factor.push_back(f[i]);
	else if ( f[i] >= 10 ) {
	    cout << -1 << endl; return;
	}
    }
    while( n2 >= 3 ){
	factor.push_back(8);
	n2 -= 3;
    }
    while( n3 >= 2 ){
	factor.push_back(9);
	n3 -= 2;
    }
    while( n2 >= 1 && n3 >= 1 ){
	factor.push_back(6);
	n2--;
	n3--;
    }
    while( n2 >= 2 ){
	factor.push_back(4);
	n2 -= 2;
    }
    while( n2 > 0 ) {
	factor.push_back(2);
	n2--;
    }
    while( n3 > 0 ) {
	factor.push_back(3);
	n3--;
    }

    sort( factor.begin(), factor.end() );
    
    for ( int i = 0; i < factor.size(); i++ ) cout << factor[i];
    cout << endl;

}

void compute(){
    int n; 
    cin >> n;
    vector<int> factors;
    factorize(n, factors);
    getNumber(factors);
}

int main(void){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ) compute();
    return 0;
}



