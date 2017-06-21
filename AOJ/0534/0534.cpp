#include<iostream>
using namespace std;
#define MAX 10005

int n, A[MAX];
int minv;

void check( int p, int c ){
    int tmp = A[p];
    A[p] = c;
    
    int r, l, w;
    r = l = p;
    w = 1;

    bool suc = false;
    while(1){
	int pl = l;
	int pr = r;
	while( A[pl-1] == c ) {pl--; w++;};
	while( A[pr+1] == c ) {pr++; w++;};

	if ( w < 4 ) break;
	pl--;
	pr++;
	l = pl;
	r = pr;

	if ( A[l] == -1 || A[r] == -1 ) break;
	if ( A[l] != A[r] ) break;

	w = 2;
	c = A[l];
    }

    int tt = n+1 -r  + l;
    if ( l == r ) tt--;

    minv = min( minv, tt );

    A[p] = tmp;
}

void compute(){
    minv = n;
    for ( int c = 1; c <= 3; c++ ){
	for ( int i = 1; i <= n; i++ ){
	    if ( A[i] == c ) continue;
	    check(i, c);
	}
    }
    cout << minv << endl;
}

main(){
    while(1){
	cin >> n;
	if ( n == 0 ) break;
	A[0] = -1;
	for ( int i = 1; i <= n; i++ ) cin >> A[i];
	A[n+1] = -1;
	compute();
    }
}
