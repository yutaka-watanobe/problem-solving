#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long ullong;
#define MAX 10
int n;
pair<ullong, ullong> S[MAX], O[MAX];

ullong gcd(ullong a, ullong b){
    if ( b > a ) swap(a, b);
    return ( b == 0 ) ? a : gcd(b, a%b);
}

ullong lcm( ullong a, ullong b ){
    return a/gcd(a, b)*b;
}

void compute(){
    ullong d1, d2, v1, v2;

    for ( int i = 0; i < n ; i++ ) cin >> S[i].first >> S[i].second;
    for ( int i = 0; i < n ; i++ ) O[i] = S[i];
    ullong G;


    G = gcd(S[0].first, S[0].second);
    for ( int i = 1; i < n; i++ ){
	G = gcd(G, S[i].first);
	G = gcd(G, S[i].second);
    }
    for ( int i = 0; i < n; i++ ){
	S[i].first /= G;
	S[i].second /= G;
	}

    ullong l = lcm(S[0].second, S[1].second);
    for ( int i = 2; i < n; i++ ) l = lcm(l, S[i].second);
    for ( int i = 0; i < n; i++ ){
	S[i].first *= l/S[i].second;
	S[i].second = l;
    }

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
    for ( int i = 2; i < n; i++ ) L = lcm(L, S[i].first);
    //G = gcd(L, l); L /= G; l /= G;

    for ( int i = 0; i < n; i++ ){
	//cout << (L / O[i].first)*O[i].second/l << endl;
	cout << (L / S[i].first) << endl;
    }
}

main(){
    while( cin >> n && n ) compute();
}
