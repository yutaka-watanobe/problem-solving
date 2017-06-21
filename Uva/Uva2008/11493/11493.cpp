#include<stdio.h>
#include<iostream>
using namespace std;
#define REP(i, n) for ( int i = 0; i < n; i++ )
#define MAX 10001

int getNum(){
    //int x; scanf("%d", &x); return x;
    char ch;
    int n = 0;
    while(1){
	ch = getchar();
	if ( ch == ' ' || ch == '\n' ) break;
	n *= 10; n += ch - '0';
    }
    return n;
}

int T[MAX];

int compute(int row, int col, int w){
    if ( col*100 % w != 0 ) return INT_MAX;
    int nplank = 0;
    int rem = col*100 / w;
    int cost;

    cost  = min( T[row], rem );
    rem -= cost;
    nplank += cost;
    if ( rem == 0 ) return nplank;

    int lim = (row+2)/2;
    for ( int i = row-1; i >= lim; i-- ){
	cost = min( rem, min( T[i], T[row-i]) );
	rem -= cost;
	nplank += cost*2;
	if ( rem == 0 ) return nplank;
    }

    if ( row % 2 == 0 ){
	cost = min( rem, T[row/2]/2 );
	rem -= cost;
	nplank += cost*2;
	if ( rem == 0 ) return nplank;
    }

    return INT_MAX;
}

int main(){
    int x, y, w, n;
    int ans;
    while(1){
	x = getNum();
	y = getNum();
	if ( x == 0 && y == 0 ) break;
	w = getNum();
	n = getNum();
	REP(i, MAX+1) T[i] = 0;
	REP(i, n) T[getNum()]++;
	ans = min(compute(x, y, w), compute(y, x, w));
	if ( ans == INT_MAX ) printf("impossivel\n");
	else printf("%d\n", ans);
    }
}
