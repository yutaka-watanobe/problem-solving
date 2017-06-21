#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++)
#define MAX 20
#define H 5
#define N 10

int n, minw;
char P[H][MAX], B[H][MAX*N];

bool invalid(int p){
    rep(i, H) rep(j, n){
	if ( P[i][j] == 'X' && B[i][j+p] != '.' ) return true;
    }
    return false;
}

void setTask(int p, char ch){
    rep(i, H) for ( int j = p; j < p+n; j++ ){
	if ( P[i][j-p] == 'X' )	B[i][j] = ch;
    }
}

void rec( int pos, int last){
    if ( pos == N ){ minw = min(minw, last+n); return; }
    if ( minw <= last+n-1 + (n-pos) ) return;
    for ( int j = last+1; j <= last+n; j++ ){
	if ( invalid(j) ) continue;
	setTask(j, 'X');
	rec(pos+1, j);
	setTask(j, '.');
    }
}

void init(){
    minw = (1<<21);
    rep(i, H) rep(j, MAX*N) B[i][j] = '.';
}

main(){
    while ( cin >> n && n ){
	rep(i, H) rep(j, n) cin >> P[i][j];
	init();
	rec(0, -1);
	cout << minw << endl;
    }
}
