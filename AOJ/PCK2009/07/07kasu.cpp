#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long ullong;
#define MAX 10
int n;
pair<ullong, ullong> S[MAX];

ullong gcd(ullong a, ullong b){
    if ( b > a ) swap(a, b); 
    if ( b == 0 ) return a;
    return gcd(b, a%b);
}

ullong lcmd( ullong d1, ullong v1, ullong d2, ullong v2 ){
    ullong a = d1*v2;
    ullong b = d2*v1;
    ullong g = gcd(a, b);
    a /= g;
    b /= g;
    return (a/v2)*d2;
}

void compute(){
    ullong d1, d2, v1, v2;
    for ( int i = 0; i < n ; i++ ) cin >> S[i].first >> S[i].second;
    ullong l = lcmd(S[0].first, S[0].second, S[1].first, S[1].second);
    for ( int i = 2; i < n; i++ ){
	l = lcmd(l, 1, S[i].first, S[i].second );
	cout << l << endl;
    }
    cout << "l = " << l << endl;
    for ( int i = 0; i < n; i++ ){
	cout << (l/S[i].first)*S[i].second << endl;
    }

}

main(){
    while( cin >> n && n ) compute();
}
