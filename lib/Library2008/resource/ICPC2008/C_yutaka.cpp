#include<iostream>
#include<string>
#include<map>
#include<cassert>
using namespace std;

map<char, int> V;
string exp;
int pos;

int formula(){
    char ch = exp[pos];
    if ( isdigit(ch) ){
	pos++; return ch - '0';
    } else if ( isalpha(ch) ){
	pos++; return V[ch];
    } else if ( ch == '-' ){
	pos++; return (2 - formula()); // NOT
    } else if ( ch == '(' ){
	int v1, v2;
	char op;
	pos++;
	v1 = formula();
	op = exp[pos++];
	v2 = formula();
	assert( exp[pos++] == ')');
	if ( op == '*' ) return min( v1, v2 ); // AND
	else if ( op == '+' ) return max( v1, v2 ); // OR
    }
}

main(){
    int cnt;
    while( cin >> exp && exp != "."){
	cnt = 0;
	for ( int p = 0; p <= 2; p++ ){
	    for ( int q = 0; q <= 2; q++ ){
		for ( int r = 0; r <= 2; r++ ){
		    V['P'] = p;
		    V['Q'] = q;
		    V['R'] = r;
		    pos = 0;
		    if ( formula() == 2 ) cnt++;
		}
	    }
	}
	cout << cnt << endl;
    }
}
