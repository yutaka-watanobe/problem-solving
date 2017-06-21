#include<iostream>
#include<cmath>
#include<map>
using namespace std;


long long cut( long long n, long long k ){
    long long l = 0;
    long long x = k;
    while(x){
	l++;
	x /= 10;
    }

    long long p = 1;
    for ( int i = 0; i < l-n; i++ ) p*= 10;
    return k/p;
}

int main(){
    int tcase; cin >> tcase;
    long long n, k;
    for ( int i = 0; i < tcase; i++ ){
	cin >> n >> k;
	long long maxv, v;
	map<long long, bool> V;
	v =  cut(n, k);
	V[v] = true;
	maxv = v;
	while(1){
	    v = cut(n, v*v);
	    maxv = max(maxv, v);
	    if ( V[v] ) break;
	    V[v] = true;
	}
	cout << maxv << endl;
    }
    return 0;
}
