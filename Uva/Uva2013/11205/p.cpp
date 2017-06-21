#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<cassert>
using namespace std;
#define MAX 101
#define PMAX (1 << 15)

int P, N;
int symbols[MAX];
bool visited[PMAX];

void input(){
    scanf("%d %d", &P, &N);
    for ( int i = 0; i < N; i++ ){
	int value = 0;
	int p = 1;
	int x;
	for ( int j = 0; j < P; j++ ){
	    scanf("%d", &x);
	    value += x*p;
	    p *= 2;
	}
	symbols[i] = value;
    }
}

int ans;

bool check(){

    map<int, bool> v;
    for ( int i = 0; i < N; i++ ){
	if ( v[symbols[i]] ) return false;
	v[symbols[i]] = true;
    }
    return true;

    
    //    for ( int i = 0; i < N; i++ ) cout << symbols[i] << endl;

    /*

    for ( int i = 0; i <= (1 << (P+1) ); i++ ) visited[i] = false;
    for ( int i = 0; i < N; i++ ){
	if ( visited[symbols[i]] ) {
	    //	    cout << "false" << endl;
	    return false;
	}
	visited[symbols[i]] = true;
    }
    //    cout << "true" << endl;

    return true;*/
}

void recursive( int pos, int count ){

     ans = max( ans, count );

    if ( pos == P ){
	return;
    }

    // non cut
    recursive( pos + 1, count );

    // cut
    int tmp[MAX];
    for ( int i = 0; i < N; i++ ) tmp[i] = symbols[i];

    int bit = (1 << pos);
    for ( int i = 0; i < N; i++ ){
	if ( (symbols[i] & bit) == 0  ) continue;
	symbols[i] -= bit;
    }

    if ( check() ) {
	recursive( pos + 1, count + 1 );
    }
    for ( int i = 0; i < N; i++ ) symbols[i] = tmp[i];
}

void compute(){
    ans = 0;
    recursive( 0, 0 );

    cout << P - ans << endl;
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	input();
	compute();
    }
}
