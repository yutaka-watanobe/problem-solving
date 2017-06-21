#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 50
#define NOT_USED 0
#define USED 1
#define ISFULL 2

bool searchTarget(int, int, int, int );
bool pour(int, int);

int size, C[MAX], state[MAX];

bool searchTarget( int volume, int source, int startt, int nfilled, int remain ){
    if ( volume == 0 ){
	state[source] = USED;
	if( pour(nfilled, remain) ) return true;
	state[source] = ISFULL;
	return false;
    } else if ( volume < 0 || startt < 0 || remain < volume ) return false;

    for ( int i = source - 1; i >= 0; i-- ){
	if ( state[i] == ISFULL ) break;
	if ( state[i] == NOT_USED && C[i] > volume ) return false;
    }

    int pre = -1;
    for ( int target = startt; target >= 0; target-- ){
	if ( state[target] >= 1 || C[target] > volume ) continue;
	if ( pre == C[target] ) continue; // pre を起点としたものはすでに失敗している
	state[target] = ISFULL;
	if ( searchTarget( volume - C[target], source, target-1, nfilled+1, remain-C[target] ) ) return true;
	state[target] = NOT_USED;
	pre = C[target];
    }
    return false;
}

bool pour( int nfilled, int remain ){
    if ( nfilled == size ) return true;

    for ( int source = size-1; source >= 1; source-- ){
	if ( state[source] == ISFULL ) {
	    if ( searchTarget( C[source], source, source-1, nfilled, remain )) return true;
	}
    }

    return false;
}

bool judge(){
    sort( C, C + size );
    int remain = 0;
    for ( int i = 0; i < size; i++ ) {
	state[i] = NOT_USED;
	remain += C[i];
    }
    state[size-1] = ISFULL;
    remain -= C[size-1];
    return pour( 1 , remain );
}

int main(){
    while ( cin >> size && size ) {
	for ( int i = 0; i < size; i++ ) cin >> C[i];
	if ( judge() ) cout << "YES" << endl;
	else cout << "NO" << endl;
    }
    return 0;
}
