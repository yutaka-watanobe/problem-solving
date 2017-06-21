#include<iostream>
#include<string>
#include<map>
using namespace std;
#define MAX 100

int F[MAX+1];
map<int, int> F2I;

void makeFibo(){
    F[0] = 0;
    F[1] = 1; F2I[F[1]] = 1;
    F[2] = 2; F2I[F[2]] = 2;
    for ( int i = 3; i <= MAX; i++ ) {
	F[i] = F[i-1] + F[i-2];
	F2I[F[i]] = i;
    }
}

int N, seq[MAX];

bool isCap( char ch ){
    return ( 'A' <= ch && ch <= 'Z' );
}

void compute(){
    makeFibo();
    string source, target;

    cin >> N;
    for ( int i = 0; i < N; i++ ) cin >> seq[i];
    getline( cin, source );
    getline( cin, source );

    target.resize(1000);
    fill ( target.begin(), target.end(), ' ' );


    int pos = 0;
    int size = 0;
    for ( int i = 0; i < source.size() && pos < N ; i++ ){
	if ( !isCap(source[i]) ) continue;
	if ( F2I[seq[pos]] ){
	    target[F2I[seq[pos]]-1] = source[i];
	    size = max( size, F2I[seq[pos]]-1 );
	}
	pos++;
    }

    for ( int i = 0; i <= size; i++ ) cout << target[i];
    cout << endl;
}

int main(){
    int tcase; cin >> tcase;

    for ( int i = 0; i < tcase; i++ ) compute();

    return 0;
}

