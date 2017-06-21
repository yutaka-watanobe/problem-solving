#include<iostream>
using namespace std;

#define IMAX 300
#define NMAX 1000

struct Check{ int x, y, z, s; };

int a, b, c, N;
int state[IMAX+1];

Check C[NMAX];

int main(){

    while(1){
	cin >> a >> b >> c >> N;
	if ( a == 0 && b == 0 && c == 0 ) break;

	for ( int i = 1; i <= a+b+c; i++ ) state[i] = 2;

	for ( int i = 0; i < N; i++ ){
	    cin >> C[i].x >> C[i].y >> C[i].z >> C[i].s;
	    if ( C[i].s ){
		state[C[i].x] = state[C[i].y] = state[C[i].z] = 1;
	    }
	}

	for ( int i = 0; i < N; i++ ){
	    if ( C[i].s ) continue;

	    if ( state[C[i].x]==1 && state[C[i].y]==1 ) state[C[i].z] = 0;
	    else if ( state[C[i].x]==1 && state[C[i].z]==1 ) state[C[i].y] = 0;
	    else if ( state[C[i].y]==1 && state[C[i].z]==1 ) state[C[i].x] = 0;
	}

	for ( int i = 1; i <= a+b+c; i++ ){
	    cout << state[i] << endl;
	}

	
    }

    return 0;
}
