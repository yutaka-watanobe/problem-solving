#include<iostream>
#include<string>
#include<string.h>
using namespace std;
#define MAX 10
#define CMAX 25
#define N 25

char B[MAX+2][MAX+2], C[CMAX;
int H, W, n;
bool used[CMAX], checkPoint[MAX+2][MAX+2];

int expression();
int term();
int factor();

char exp[N];
int p;
bool hasError;

bool isOP( char ch ){
    return ( ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '=' );
}

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
	    if ( f == 0 || value < f || value % f != 0 ) {
	      hasError = true;
	      return 0;
	    }
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

bool solve( char ep[N], int eps){
    ep[eps] = '\0';

    char left[N];
    char right[N];
    int nl, nr;
    nl = nr = 0;

    int i = 0;
    while(i < eps &&  ep[i] != '=' ) left[nl++] = ep[i++];
    if ( i == eps ) return false;
    for ( int j = i+1; j < eps; j++ ) {
	if ( ep[j] == '=' ) return false;
	right[nr++] = ep[j];
    }

    if ( nr == 0 || nl == 0 ) return false;

    left[nl] = '\0';
    strcpy(exp, left);
        exp[nl] = '\0';
    p = 0;
    hasError = false;
    for ( int i = 0; i < nl-1; i++ ){
	if ( isOP(left[i]) && isOP(left[i+1]) ) return false;
    }
    if ( isOP(left[0]) || isOP(left[nl-1] ) ) return false;
    int l = expression();

    right[nr] = '\0';
    strcpy(exp, right);
        exp[nr] = '\0';
    p = 0;
    for ( int i = 0; i < nr-1; i++ ){
	if ( isOP(right[i]) && isOP(right[i+1]) ) return false;
    }
    if ( isOP(right[0]) || isOP(right[nr-1] ) ) return false;

    int r = expression();

    return (!hasError) && (l == r);
}

bool unsolvableH( int si, int sj ){
    char ep[N];
    int eps = 0;
    int j = sj;
    while(1){
	if ( B[si][j] == '.' ) return false;
	else if ( B[si][j] == '#' ) break;
	j--;
    }
    j++;
    for ( int a = j; a <= sj; a++ ) ep[eps++] = B[si][a];

    j = sj + 1;
    while(1){
	if ( B[si][j] == '.' ) return false;
	else if ( B[si][j] == '#' ) break;
	j++;
    }
    for ( int a = sj+1; a < j; a++ ) ep[eps++] = B[si][a];
    if ( eps == 1 ) return false;

    return !solve(ep, eps);
}

bool unsolvableV( int si, int sj ){
    char ep[N];
    int eps = 0;
    int i = si;
    while(1){
	if ( B[i][sj] == '.' ) return false;
	else if ( B[i][sj] == '#' ) break;
	i--;
    }
    i++;
    for ( int a = i; a <= si; a++ ) ep[eps++] = B[a][sj];
    i = si + 1;
    while(1){
	if ( B[i][sj] == '.' ) return false;
	else if ( B[i][sj] == '#' ) break;
	i++;
    }
    for ( int a = si+1; a < i; a++ ) ep[eps++] = B[a][sj];
    if ( eps == 1 ) return false;
    return !solve(ep, eps);
}

bool recursive( int pos ){
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

void setCheckPoint(){
    bool isFirst = true;
    for ( int i = 1; i <= H; i++ ){
	isFirst = true;
	for ( int j = W; j >= 1; j-- ){
	    if ( B[i][j] == '#' ) isFirst = true;
	    else if ( B[i][j] == '.' ){
		if ( isFirst ) checkPoint[i][j] = true;
		isFirst = false;
	    }
	}
    }
    for ( int j = 1; j <= W; j++ ){
	isFirst = true;
	for ( int i = H; i >= 1; i-- ){
	    if ( B[i][j] == '#' ) isFirst = true;
	    else if ( B[i][j] == '.' ){
		if ( isFirst ) checkPoint[i][j] = true;
		isFirst = false;
	    }
	}
    }
}

int main(){
    while( cin >> H >> W && H ){
	for ( int i = 0; i < H+2; i++ ){
	    for ( int j = 0; j < W+2; j++ ) {
		B[i][j] = '#';
		checkPoint[i][j] = false;
	    }
	}

	for ( int i = 1; i <= H; i++ )
	    for ( int j = 1; j <= W; j++ ) cin >> B[i][j];
	cin >> n;
	for ( int i = 0; i < n; i++ ) {
	    cin >> C[i];
	    used[i] = false;
	}

	setCheckPoint();

	if ( recursive(0) )  cout << "Yes" << endl;
	else  cout << "No" << endl;
    }
}
