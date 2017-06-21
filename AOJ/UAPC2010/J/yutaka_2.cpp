#include<iostream>
#include<vector>
using namespace std;

typedef long long llong;

void factorize( llong x, llong factors[], int &nfactors ){
    llong d, q;
    while ( x >= 4 && x % 2 == 0 ) {
	factors[nfactors++] = 2;
	x /= 2;
    }
    d = 3; q = x / d;
    while ( q >= d ){
	if ( x % d == 0 ) {
	    factors[nfactors++] = d;
	    x = q;
	} else {
	    d += 2;
	}
	q = x / d;
    }
    factors[nfactors++] = x;
}

void rec(int p, llong d, llong divisors[], pair<llong, llong> factpairs[], int &ndivisors, int &npairs){
    if ( p == npairs ){
	divisors[ndivisors++] = d;
	return;
    }

    llong v = d;
    for ( int i = 0; i <= factpairs[p].second; i++ ){
	rec(p+1, v, divisors, factpairs, ndivisors, npairs);
	v *= factpairs[p].first;
    }
}

llong gcd( llong x, llong y ){
    int r;

    if ( x < y ) swap( x, y ); 
    
    while ( y > 0 ){
        r = x % y;
        x = y;
        y = r;
    }

    return x;
}

int maxv;

int compute(llong n){
    llong factors[1000];
    int nfactors = 0;
    pair<llong, llong> factpairs[10000];
    int npairs = 0;

    factorize(n, factors, nfactors);

    if ( nfactors > 0 ) factpairs[npairs++] = make_pair(factors[0], 1);
    for ( int i = 1; i < nfactors; i++ ){
	if( factpairs[npairs-1].first == factors[i] ){
	    factpairs[npairs-1].second++;
	} else {
	    factpairs[npairs++] = make_pair(factors[i], 1);
	}
    }
    
    /*
    for ( int i = 0; i < factpairs.size(); i++ ){
	cout << factpairs[i].first << "^" << factpairs[i].second << endl;
    }
    cout << endl;
    */

    llong divisors[1000];
    int ndivisors = 0;

    rec(0, 1, divisors, factpairs, ndivisors, npairs);
    
    if ( ndivisors >= 2 && divisors[0] == 1 && divisors[1] == 1 ){
	//divisors.erase(divisors.begin());
	for ( int i = 0; i < ndivisors; i++ ){
	    divisors[i] = divisors[i+1];
	}
	ndivisors--;
    }

    sort(divisors, divisors + ndivisors);
    //        for ( int i = 0; i < divisors.size(); i++ ) cout << divisors[i] << endl;


    int cnt = 0;
    for ( int i = 0; i < ndivisors; i++ ){
	for ( int j = i; j < ndivisors; j++ ){
	    if ( gcd(divisors[i], divisors[j] ) == 1 ) cnt++;
	}
    }
    return cnt;
}

main(){
    llong n;

    while(1){
	cin >> n;
	if ( n == 0 ) break;
	//cout << n << " " << compute(n) << endl;
	cout << compute(n) << endl;
    }

}
