#include<iostream>
using namespace std;
#define rep(i,s,e) for ( int i = s; i <= e; i++ )
#define MAX 10000
char C[MAX+2];
int n, m;

void setLeft(char ch){
    for ( int i = 1; ; i++ ){
	if ( C[i] == '#' ) { C[i] = ch; return; }
    }
}

void setB(){
    for ( int i = n; i >= 1; i-- ){
	if ( C[i] == '#' && C[i-1] != 'A' && C[i+1] != 'A' ){
	    C[i] = 'B'; return;
	}
    }
    setLeft('B');
}

bool isEmpty(){
    rep(i,1,n) if ( C[i] != '#' ) return false;
    return true;
}

void setC(){
    if ( isEmpty() ){ C[n/2+1] = 'C'; return; }
    rep(i,1,n){
	if ( C[i] == '#' ) continue;
	if ( C[i+1] == '#' ) { C[i+1] = 'C'; return; }
	if ( C[i-1] == '#' ) { C[i-1] = 'C'; return; }
    }
}

int getDist( int p ){
    int l = 0, r = 0;
    while( C[p+l-1] == '#' ) l--;
    if ( C[p+l-1] == 'X' ) l = -1000000;
    while( C[p+r+1] == '#' ) r++;
    if ( C[p+r+1] == 'X' ) r = 1000000;
    return min( (-1)*l, r);
}
void setD(){
    if ( isEmpty() ){ C[1] = 'D'; return; }
    int d, mi, md = -1;
    rep(i,1,n){
	if ( C[i] != '#' ) continue;
	d = getDist(i);
	if ( d > md ) {
	    md = d; mi = i;
	}
    }
    C[mi] = 'D';
}

main(){
    char ch;
    while( cin >> n >> m && n && m ){
	rep(i,0,n+1) C[i] = '#';
	C[0] = C[n+1] = 'X';
	rep(i,1,m){ 
	    cin >> ch;
	    if ( ch == 'A' ) setLeft('A');
	    else if ( ch == 'B' ) setB();
	    else if ( ch == 'C' ) setC();
	    else if ( ch == 'D' ) setD();
	}
	rep(i,1,n) cout << C[i];
	cout << endl;
    }
}
