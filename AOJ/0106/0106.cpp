#include<iostream>
#include<cmath>
#include<algorithm>
#include<climits>
using namespace std;


int target;
static const int amount[3] = {200, 300, 500};
static const int value[3] = {380, 550, 850};
static const int per[3] = {5, 4, 3};
static const double ratio[3] = {0.8, 0.85, 0.88};

int minv;

int getValue( int store, int n ){
    int discount = per[store] * (n/per[store]);
    int nondisc = n%per[store];
    return ((int)ceil(value[store]*ratio[store]*discount) + value[store]*nondisc);
}

int compute(){
    minv = INT_MAX;
    
    int sa, sb, sc;
    for ( int a = 0; a <= target/amount[0]; a++ ){
	for ( int b = 0; b <= target/amount[1]; b++ ){
	    for ( int c = 0; c <= target/amount[2]; c++ ){

		int total = a*amount[0] + b*amount[1] + c*amount[2];
		int value = getValue(0, a) + getValue(1, b) + getValue(2, c);

		if ( total == target ){
		    if ( minv > value ){
			minv = value;
			sa = a;
			sb = b;
			sc = c;
		    }
		}
	    }
	}
    }

    return minv;
}

int main(){
    while( cin >> target && target ) cout << compute() << endl;
}
