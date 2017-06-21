#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;
typedef unsigned long long ullong;
#define MAX 10

ullong gcd(ullong a, ullong b){
    return ( b == 0 ) ? a : gcd(b, a%b);
}

ullong lcm( ullong a, ullong b ){
    if ( b > a ) swap(a, b);
    return a/gcd(a, b)*b;
}

void compute(int n){
    assert( 2 <= n && n <= 10);
    ullong d1, d2, v1, v2, G;
    pair<ullong, ullong> S[MAX];
    for ( int i = 0; i < n ; i++ ){
	cin >> S[i].first >> S[i].second;
	G = gcd(S[i].first, S[i].second);
	S[i].first /= G;
	S[i].second /= G;
    }

    ullong l = lcm(S[0].first, S[1].first);
    for ( int i = 2; i < n; i++ ) l = lcm(l, S[i].first);
    
    ullong A[MAX];
    for ( int i = 0; i < n; i++ ) A[i] = S[i].second*(l/S[i].first);
    G = gcd(A[0], A[1]);
    for ( int i = 2; i < n; i++ ) G = gcd(G, A[i]);
    for ( int i = 0; i < n; i++ ) cout << A[i]/G << endl;
}

main(){
    int n;
    while( cin >> n && n ) compute(n);
}
