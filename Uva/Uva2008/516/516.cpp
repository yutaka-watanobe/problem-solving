#include<iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;
typedef long long llong;

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

void compute(llong n){
    n--;
    vector<llong> v;
    factorize(n, v);
    
    reverse( v.begin(), v.end() );

    v.push_back(-1);
    int len = 1;
    llong pre = v[0];

    bool isFast = true;
    for ( int i = 1; i < v.size(); i++ ) {
	if ( pre != v[i] ) {
	    if ( isFast ) isFast = false;
	    else cout << " ";
	    cout << pre << " " << len;
	    len = 1;
	} else len++;
	pre = v[i];
    }
    cout << endl;

}

llong power( llong p, llong e ){
    llong a = 1;
    for ( int i = 0; i < e; i++ ) a *= p;
    return a;
}

llong input(){
    llong pro = 0;
    string line;
    getline( cin, line);
    llong p, e;
    stringstream sin(line);
    sin >> p;
    if ( p == 0 ) return 0;
    sin >> e;
    pro = power(p, e);
    while( sin >> p >> e ) pro *= power(p, e);
    return pro;
}

int main(){
    llong n;
    while(1){
	n = input();
	if ( n == 0 ) break;
	compute(n);
    }
    return 0;
}
