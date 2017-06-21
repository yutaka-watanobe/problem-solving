#include<iostream>
using namespace std;
#define MAX 32

int favorite[MAX];
int want[MAX+1];
int M, N;

void compute(){
    cin >> N >> M;
    int f;
    for ( int i = 0; i < M; i++ ){
	for (int j = 0; j < N; j++ ){
	    cin >> f;
	    if ( f == 1 ) favorite[i] = (j+1);
	}
    }
    for ( int i = 1; i <= N; i++ ) want[i] = 0;
    for ( int i = 0; i < M; i++ ) want[favorite[i]]++;

    int p = 1;
    for ( int i = 1; i <= N; i++ ){
	if ( want[i] == 0 ) continue;
	p *= want[i];
    }

    cout << p << endl;
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	compute();
    }
}