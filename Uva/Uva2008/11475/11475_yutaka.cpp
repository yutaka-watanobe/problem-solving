#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 200005

void initNext( string P, int m, int N[]){
    int i, j;
    N[0] = -1;
    for ( i = 0, j = -1; i < m; i++, j++, N[i] = j )
    while( ( j >= 0 ) && ( P[i] != P[j] ) ) j = N[j];
}

bool check( char c1, char c2 ){
  if ( c1 == '*' ) return true;
  else return c1 == c2;
}

int KMPSearch( string T, int n, string P, int m ){
    int N[MAX];
    initNext( P, m, N );
    
    int i, j;
    i = j = 0;
    while ( i < n ){
        while( i < n && j < m ){
            while ( j >= 0 && !check(T[i], P[j]) ) j = N[j];
            i++; j++;
        }
        if ( j == m ) {
	    return i-j;
            j = N[j];
        }
    }
    return T.size();
}

int main(){
    string str, pattern, target;
    while( cin >> str ){
	pattern = str;
	reverse( pattern.begin(), pattern.end() );
	target = str;
	for ( int i = 1; i < pattern.size(); i++ ) target += '*';

	int e = KMPSearch( target, target.size(), pattern, pattern.size() );

	cout << str;
	for ( int i = e-1; i >= 0; i-- ) cout << str[i];
	cout << endl;
    }

    return 0;
}


