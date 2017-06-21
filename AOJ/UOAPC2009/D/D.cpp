#include<iostream>
#include<string>
using namespace std;
#define MAX 10
#define CMAX 25

char B[MAX+2][MAX+2];
int H, W, n;
char C[CMAX];
bool used[CMAX];

void print(){
    for ( int i = 1; i <= H; i++ ){
	for ( int j = 1; j <= W; j++ ){
	    cout << B[i][j];
	}
	cout << endl;
    }
}

int expression();
int term();
int factor();

string exp;
int p;
bool hasError;

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
	    int f = factor();
	    if ( f== 0 || value % f != 0 ) hasError = true;
	    value /= f;
	}
    }
    return value;
}

int factor(){
    int value = 0;
    if ( exp[p] == '(' ){
        p++; value = expression(); p++;
    } else {
        while( isdigit(exp[p]) ) { value = value*10 + exp[p++] - '0';}
    }
    return value;
}

bool isOP( char ch ){
    return ( ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '=' );
}

bool solve( string ep ){
    //        cout << "check " << ep << endl;
    for ( int i = 0; i < ep.size()-1; i++ ){
	if ( isOP(ep[i]) && isOP(ep[i+1]) ) return false;
    }
if ( isOP(ep[0]) || isOP(ep[eps-1] ) ) return false;
    string left = "";
    string right = "";
    int i = 0;
    while(i < ep.size() &&  ep[i] != '=' ) left += ep[i++];
    if ( i == ep.size() ) return false;
    for ( int j = i+1; j < ep.size(); j++ ) {
	if ( ep[j] == '=' ) return false;
	right += ep[j];
    }
    exp = left;
    p = 0;
    hasError = false;
    int l = expression();
    exp = right;
    p = 0;
    int r = expression();
    //hasError = false;

    //    cout << left << " = " << l << "    " << right << " = " << r << endl;
    return (!hasError) && (l == r);
}

bool unsolvableH( int si, int sj ){
    string ep = "";
    int j = sj;
    while(1){
	if ( B[si][j] == '.' ) return false;
	else if ( B[si][j] == '#' ) break;
	else ep = B[si][j] + ep;
	j--;
    }
    j = sj + 1;
    while(1){
	if ( B[si][j] == '.' ) return false;
	else if ( B[si][j] == '#' ) break;
	else ep = ep + B[si][j];
	j++;
    }
    if ( ep.size() == 1 ) return false;
    return !solve(ep);
}

bool unsolvableV( int si, int sj ){
    string ep = "";
    int i = si;
    while(1){
	if ( B[i][sj] == '.' ) return false;
	else if ( B[i][sj] == '#' ) break;
	else ep = B[i][sj] + ep;
	i--;
    }
    i = si + 1;
    while(1){
	if ( B[i][sj] == '.' ) return false;
	else if ( B[i][sj] == '#' ) break;
	else ep = ep + B[i][sj];
	i++;
    }
    if ( ep.size() == 1 ) return false;
    return !solve(ep);
}

bool recursive( int pos ){
    //    print();
    if ( pos == H*W ) return true;
    int i, j;
    i = pos/W + 1;
    j = pos%W + 1;
    if ( B[i][j] != '.' ) return recursive(pos+1);

    for ( int s = 0; s < n; s++ ){
	if ( used[s] ) continue;
	B[i][j] = C[s];
	if ( unsolvableH(i, j) ) { 	B[i][j] = '.'; continue;}
	if ( unsolvableV(i, j) ) {	B[i][j] = '.'; continue;}
	used[s] = true;
	if ( recursive(pos+1) ) return true;
	used[s] = false;
	B[i][j] = '.';
    }
    return false;
}



int main(){
    while( cin >> H >> W && H ){
	for ( int i = 0; i < H+2; i++ )
	    for ( int j = 0; j < W+2; j++ ) B[i][j] = '#';
	for ( int i = 1; i <= H; i++ )
	    for ( int j = 1; j <= W; j++ ) cin >> B[i][j];
	cin >> n;
	for ( int i = 0; i < n; i++ ) {
	    cin >> C[i];
	    used[i] = false;
	}
	if ( recursive(0) ) {
	    cout << "YES" << endl;
	    print();
	} else {
	    cout << "NO" << endl;
	}
    }
}
