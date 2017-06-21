#include<iostream>
#include<vector>
#include<set>
#include<cassert>
#include<algorithm>
using namespace std;

typedef unsigned long long llong;

void factorize( llong x, vector<llong> &factors ){
    llong d, q;
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

void rec(int p, llong d, vector<llong> &divisors, vector<pair<llong, llong> > &factpairs, llong n){
    if ( p == factpairs.size() ){
	assert( d <= n );
	divisors.push_back(d);
	return;
    }

    llong v = d;
    for ( int i = 0; i <= factpairs[p].second; i++ ){
	rec(p+1, v, divisors, factpairs, n);
	v *= factpairs[p].first;
	//	cout << v << endl;
    }
}



llong gcd( llong x, llong y ){
    llong r;

    if ( x < y ) swap( x, y ); 
    
    while ( y > 0 ){
        r = x % y;
        x = y;
        y = r;
    }

    return x;
}

llong lcm( llong x, llong y ){
    return (x/gcd(x,y))*y;
}

int compute(llong n){
    vector<llong> factors;
    vector<pair<llong, llong> > factpairs;

    factorize(n, factors);
    if ( factors.size() > 0 ) factpairs.push_back(make_pair(factors[0], 1));
    for ( int i = 1; i < factors.size(); i++ ){
	if( factpairs[factpairs.size()-1].first == factors[i] ){
	    factpairs[factpairs.size()-1].second++;
	} else {
	    factpairs.push_back(make_pair(factors[i], 1));
	}
    }
    

    vector<llong> divisors;
    rec(0, 1, divisors, factpairs, n);
    
    if ( divisors.size() >= 2 && divisors[0] == 1 && divisors[1] == 1 ){
	divisors.erase(divisors.begin());
    }

    //set<llong> ss;
    //for ( int i = 0; i < divisors.size(); i++ ) ss.insert(divisors[i]);
    //assert( ss.size() == divisors.size());

    sort(divisors.begin(), divisors.end());
    //        for ( int i = 0; i < divisors.size(); i++ ) cout << divisors[i] << endl;


    //    cout << "---- " << divisors.size() << endl;
    int cnt = 0;
    for ( int i = 0; i < divisors.size(); i++ ){
	for ( int j = i; j < divisors.size(); j++ ){
	     if ( gcd(divisors[i], divisors[j] ) == 1 ){
		cnt++;
	    }
	}
    }
    return cnt;
}

main(){
    llong n;
    while(1){
	cin >> n;
	if ( n == 0 ) break;
	assert ( n <= 1000000000000LL );
	//cout << n << " " << compute(n) << endl;
	cout << compute(n) << endl;
    }
}
