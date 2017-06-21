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

void rec(int p, int d, vector<int> &divisors, vector<pair<int, int> > &factpairs){
    if ( p == factpairs.size() ){
	divisors.push_back(d);
	return;
    }

    int v = d;
    for ( int i = 0; i <= factpairs[p].second; i++ ){
	rec(p+1, v, divisors, factpairs);
	v *= factpairs[p].first;
    }
}

int gcd( int x, int y ){
    int r;

    if ( x < y ) swap( x, y ); 
    
    while ( y > 0 ){
        r = x % y;
        x = y;
        y = r;
    }

    return x;
}

int compute(int n){
    vector<int> factors;
    vector<pair<int, int> > factpairs;

    factorize(n, factors);
    if ( factors.size() > 0 ) factpairs.push_back(make_pair(factors[0], 1));
    for ( int i = 1; i < factors.size(); i++ ){
	if( factpairs[factpairs.size()-1].first == factors[i] ){
	    factpairs[factpairs.size()-1].second++;
	} else {
	    factpairs.push_back(make_pair(factors[i], 1));
	}
    }
    
    /*
    for ( int i = 0; i < factpairs.size(); i++ ){
	cout << factpairs[i].first << "^" << factpairs[i].second << endl;
    }
    cout << endl;
    */

    vector<int> divisors;
    rec(0, 1, divisors, factpairs);
    
    if ( divisors.size() >= 2 && divisors[0] == 1 && divisors[1] == 1 ){
	divisors.erase(divisors.begin());
    }

    sort(divisors.begin(), divisors.end());
    //        for ( int i = 0; i < divisors.size(); i++ ) cout << divisors[i] << endl;

    int cnt = 0;
    for ( int i = 0; i < divisors.size(); i++ ){
	for ( int j = i; j < divisors.size(); j++ ){
	    if ( gcd(divisors[i], divisors[j] ) == 1 ) cnt++;
	}
    }
    return cnt;
}

main(){
    int n;
    while(1){
	cin >> n;
	if ( n == 0 ) break;
	cout << n << " " << compute(n) << endl;
    }
}
