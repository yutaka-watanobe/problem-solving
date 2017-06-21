#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define LIMIT 1440

bool isPalindromic( int h, int m ){
    if ( h >= 24 ) h = 0;
    if ( h == 0 ){
	if ( m < 10 || m/10 == m%10 ) return true;
	else return false;
    }
    if ( h < 10 ){
	if ( m < 10 ) return h == m;
	else return h == m%10;
    } else {
	return h/10 == m%10 && h%10 == m/10;
    }
}

void compute(){
    int h, m;
    char ch;
    cin >> h >> ch >> m;
    int a = h*60 + m;
    for ( int t = a+1; t <= LIMIT; t++ ){
	if ( isPalindromic( t/60, t%60 ) ){
	    printf("%02d:%02d\n", (t/60)%24, t%60);
	    return;
	}
    }
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	compute();
    }
}
