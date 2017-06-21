#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long ullong;
#define MAX 10
int tcase;

ullong gcd(ullong a, ullong b){
    if ( b > a ) swap(a, b);
    return ( b == 0 ) ? a : gcd(b, a%b);
}

ullong lcm( ullong a, ullong b ){
    return a/gcd(a, b)*b;
}

void compute(int n){
    ullong d1, d2, v1, v2;
    pair<ullong, ullong> S[MAX], O[MAX];
    for ( int i = 0; i < n ; i++ ) cin >> S[i].first >> S[i].second;
    for ( int i = 0; i < n ; i++ ) O[i] = S[i];

    ullong G = gcd(S[0].first, S[0].second);
    for ( int i = 1; i < n; i++ ){
	G = gcd(G, S[i].first);
	G = gcd(G, S[i].second);
    }
    for ( int i = 0; i < n; i++ ){
	S[i].first /= G;
	S[i].second /= G;
    }

    int N[MAX];

    ullong l = lcm(S[0].second, S[1].second);
    for ( int i = 2; i < n; i++ ) l = lcm(l, S[i].second);
    for ( int i = 0; i < n; i++ ){
	N[i] = S[i].first*(l/S[i].second);
	S[i].first *= l/S[i].second;
	S[i].second = l;
    }

    G = gcd(N[0], N[1]);
    for ( int i = 2; i < n; i++ ) G = gcd(G, N[i]);
    for ( int i = 0; i < n; i++ ) N[i] /= G;


    G = gcd(S[0].first, S[0].second);
    for ( int i = 1; i < n; i++ ){
	G = gcd(G, S[i].first);
	G = gcd(G, S[i].second);
    }
    for ( int i = 0; i < n; i++ ){
	S[i].first /= G;
	S[i].second /= G;
    }

    ullong L = lcm(S[0].first, S[1].first);
    for ( int i = 2; i < n; i++ ) {
      L = lcm(L, S[i].first);
      if ( L % l == 0 ) L /= l;
      cout << "L ---- " << L << endl;
    }

    L = lcm(N[0], N[1]);
    for ( int i = 2; i < n; i++ ) {
	L = lcm(L, N[i]);
	cout << "L====" << L << endl;
    }
    for ( int i = 0; i < n; i++ ){
	cout << L/S[i].first << endl;
    }

    ullong A[10];
    for ( int i = 0; i < n; i++ ){
	A[i] = (L / S[i].first);
    }

    G = gcd(A[0], A[1]);
    for ( int i = 2; i < n; i++ ) G = gcd(G, A[i]);
    //    for ( int i = 0; i < n; i++ ) cout << A[i]/G << endl;
    tcase++;
}

main(){
    int n;
    tcase = 1;
    while( cin >> n && n ) compute(n);
}
