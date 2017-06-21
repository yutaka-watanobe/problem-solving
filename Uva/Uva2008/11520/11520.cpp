#include<iostream>
#include<stdio.h>
using namespace std;
#define REP(i, e) for ( int i = 0; i < e; i++ )
#define REPI(i, e) for ( int i = 1; i <= e; i++ )
#define MAX 10
int n;
char B[MAX+2][MAX+2];

void input(){
    cin >> n;
    REPI(i, n) REPI(j, n) cin >> B[i][j];
    REP(i, n+2){
	B[0][i] = B[n+1][i] = B[i][0] = B[i][n+1] = '.';
    }
}

void compute(){

    REPI(i, n){
	REPI(j, n){
	    if ( B[i][j] != '.' ) continue;
	    for ( int a = 0; a <= 26; a++ ){
		char s = 'A' + a;
		if ( B[i+1][j] == s ||
		     B[i][j+1] == s ||
		     B[i-1][j] == s ||
		     B[i][j-1] == s  ) continue;
		B[i][j] = s;
		a = 27;
	    }
	}
    }

    REPI(i, n) {
	REPI(j, n) printf("%c", B[i][j]);
	printf("\n");
    }
}

int main(){
    int tcase; cin >> tcase;
    for ( int i = 1; i <= tcase; i++ ){
	printf("Case %d:\n", i);
	input();
	compute();
    }
    return 0;
}
