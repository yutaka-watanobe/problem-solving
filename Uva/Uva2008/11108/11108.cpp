#include<iostream>
#include<string>
#include<cassert>
using namespace std;
#define REP(i, s, e) for ( i = s; i <= e; i++ )
string str;
int pos, p, q, r, s, t;

bool isUpper(char ch ){
    return ('A' <= ch && ch <= 'K' );
}

bool isLower(char ch ){
    return ( 'p' <= ch && ch <= 't' );
}

int parse(){
    if ( str[pos] == 'N' ){
	pos++;
	return ( parse() + 1 ) % 2;
    } else if ( isUpper(str[pos]) ){
	char com = str[pos];
	pos++;
	int l = parse();
	pos++;
	int r = parse();
	if ( com == 'K' ) {
	    return  l*r;
	} else if ( com == 'A' ) {
	    return (l==1||r==1)?1:0;
	} else if ( com == 'C' ){
	    if ( l == r ) return 1;
	    else return (l==1)? 0 : 1;
	} else if ( com == 'E' ){
	    return (l==r)?1:0;
	}
    } else if ( isLower(str[pos]) ){
	if( str[pos] == 'p' ) return p;
	else if( str[pos] == 'q' ) return q;
	else if( str[pos] == 'r' ) return r;
	else if( str[pos] == 's' ) return s;
	else if( str[pos] == 't' ) return t;
    } else {
	assert( false );
    }
}

void compute(){
    pos = 0;
    
    REP (p, 0, 1) REP (q, 0, 1) REP(r, 0, 1) REP(s, 0, 1) REP(t, 0, 1){
	pos = 0;
	if ( parse() == 0 ){
	    cout << "not" << endl; return;
	}
    }

    cout << "tautology" << endl;
}

int main(){
    while ( cin >> str ){
	if ( str == "0" ) break;
	compute();
    }
    return 0;
}
