#include<iostream>
#include<string>
#include<algorithm>
#include<cassert>
#define MAX 10
#define rep(i, n) for ( int i = 0; i < n; i++ )

using namespace std;

char G[MAX+2][MAX+2];
char L[MAX];
pair<int, int> holes[MAX];

int H, W, n;

int expression();
int term();
int factor();

string exp;
int p;
bool success;

int expression(){
    int value = term();
    while( exp[p] == '+' || exp[p] == '-' ){
        if ( exp[p] == '+' ) { p++; value += term(); }
        else { p++; value -= term(); }
    }
    return value;
}
int term(){
    int value = factor();
    while( exp[p] == '*' || exp[p] == '/' ){
        if ( exp[p] == '*' ) { p++; value *= factor(); }
        else { 
	    p++; 
	    int tmp = factor();
	    if ( tmp == 0 ){
		success = false;
	    } else {
		if ( value % tmp != 0 ) success = false;
		value /= tmp;
	    }
	}
    }
    return value;
}

int factor(){
    int value = 0;
    if ( exp[p] == '(' ){
        p++; value = expression(); p++;
    } else {
	assert( isdigit(exp[p]) );
	string num = "";
        while( isdigit(exp[p]) ) { 
	    num += exp[p];
	    value = value*10 + exp[p++] - '0';
	}
	assert( value == atoi(num.c_str()));
	if ( num.size() > 1 && num[0] ==  '0' ) success = false;
    }
    return value;
}

bool isOP(char ch){
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

bool invalidOp(string str ){
    if ( isOP(str[0]) || isOP(str[str.size()-1] )) return true;
    for ( int i = 0; i < str.size()-1; i++ ){
	if ( isOP(str[i]) && isOP(str[i+1]) ) return true;
    }
    return false;
}

bool valid( string str ){
    int ei = -1;
    for ( int i = 0; i < str.size(); i++ ){
	assert( str[i] != '.' );
	if ( str[i] == '=' ){
	    assert( ei == -1 ); ei = i;
	}
    }
    assert( 0 <= ei && ei < str.size()-1 );

    string left = str.substr(0, ei);
    string right = str.substr(ei+1, str.size()-ei);

    if ( invalidOp(left) ) return false;
    if ( invalidOp(right) ) return false;
    
    success = true;

    p = 0; exp = left;
    int l = expression();
    p = 0; exp = right;
    int r = expression();

    return success && ( l == r );
}

bool judge(){
    string eq = "";
    for ( int i = 0; i <= H+1; i++ ){
	for ( int j = 0; j <= W+1; j++ ){
	    if ( G[i][j] == '#' ){
		assert( (int)eq.size() != 2 );
		if ( eq.size() >= 3 ){
		    if ( !valid(eq) ) return false;
		}
		eq = "";
	    } else {
		eq += G[i][j];
	    }
	}
    }
    eq = "";
    for ( int j = 0; j <= W+1; j++ ){
	for ( int i = 0; i <= H+1; i++ ){
	    if ( G[i][j] == '#' ){
		assert( (int)eq.size() != 2 );
		if ( eq.size() >= 3 ){
		    if ( !valid(eq) ) return false;
		}
		eq = "";
	    } else {
		eq += G[i][j];
	    }
	}
    }
    return true;
}

bool compute(){
    sort( L, L + n );
    do{
	for ( int i = 0; i < n; i++ ){
	    G[holes[i].first][holes[i].second] = L[i];
	}
	if ( judge() ) return true;
    } while( next_permutation(L, L+n) );
    return false;
}
void print(){
    for ( int i = 1; i <= H; i++ ){
	for ( int j = 1; j <= W; j++ ){
	    cout << G[i][j];
	}
	cout << endl;
    }
}

int main(){
    int tcase = 0;
    while( cin >> H >> W ){
	if ( H == 0 && W == 0 ) break;
	//	cout << ++tcase << endl;
	//++tcase;
	rep(i, H+2) rep(j, W+2 ) G[i][j] = '#';
	int nhole = 0;
	for ( int i = 1; i <= H; i++ ){
	    for ( int j = 1; j <= W; j++ ){
		cin >> G[i][j];
		if ( G[i][j] == '.' ){
		    holes[nhole++] = make_pair(i, j);
		}
	    }
	}
	cin >> n;
	assert( n == nhole );
	for ( int i = 0; i < n; i++ ) cin >> L[i];

	//	if ( tcase == 43 ) print();


	if ( compute() ) cout << "Yes" << endl;
	else cout << "No" << endl;

	//	if ( tcase == 43 ) print();
    }
    return 0;
}
