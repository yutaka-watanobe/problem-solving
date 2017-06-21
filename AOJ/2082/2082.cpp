#include<iostream>
using namespace std;
#define MAX 1050

int N, M, L[MAX], P[MAX];

bool recursive( int pos, int value){
    if ( pos == M ){
	int j = 0;
	if ( value != L[j++] ) return false;
	for ( int i = pos; i < N + M - 1; i++ ){
	    value -= P[i-M];
	    if ( L[j] == value + 1 ) { value++; P[i] = 1;}
	    else if ( L[j] == value + 0 ) {P[i] = 0;}
	    else {return false;}
	    j++;
	}
	return true;
    } else {
	P[pos] = 1;
	if (recursive(pos+1, value+1)) return true;
	P[pos] = 0;
	if (recursive(pos+1, value)) return true;

    }
    return false;
}

int main(){
    while( cin >> N >> M ){
	if ( N == 0 && M == 0 ) break;
	for ( int i = 0; i < N; i++ ) cin >> L[i];
	if (recursive(0, 0)){
	    for ( int i = 0; i < N+M-1; i++ ) cout << P[i];
	    cout << endl;
	} else {
	    cout << "Goofy" << endl;
	}
    }
    return 0;
}
