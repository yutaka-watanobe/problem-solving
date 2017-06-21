#include<iostream>
#include<string>
using namespace std;
char c;
string T1, T2;
int p1, p2;

void recS( string &T, int &p ){
    for ( int i = 0; i < 2; i++ ){
	if ( T[p] == '(' ) {
	    if ( c == 'u' ) cout << '(';
	    p++; recS(T, p); p++;
	    if ( c == 'u' ) cout << ')';
	} else {
	    p++;
	}
	if ( i == 0 && c == 'u' ) cout << ',';
    }
}

void rec(){
    for ( int i = 0; i < 2; i++ ){
	if ( T1[p1] == '(' && T2[p2] == '(' ){
	    cout << '('; p1++; p2++;
	    rec();
	    p1++; p2++; cout << ')';
	} else if ( T1[p1] == '(' ){
	    if ( c == 'u' ) cout << "(";
	    p1++; recS( T1, p1); p1++;
	    p2++;
	    if ( c == 'u' ) cout << ")";
	} else if ( T2[p2] == '(' ){
	    if ( c == 'u' ) cout << "(";
	    p2++; recS( T2, p2); p2++;
	    p1++;
	    if ( c == 'u' ) cout << ")";
	} else {
	    p1++; p2++;
	}
	if ( i == 0 ) cout << ',';
    }
}

int main(){
    while( cin >> c ){
	cin >> T1 >> T2;
	p1 = p2 = 1;
	cout << '(' ; rec(); cout << ')' << endl;
    }
    return 0;
}

