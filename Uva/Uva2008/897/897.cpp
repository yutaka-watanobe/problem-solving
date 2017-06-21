#include<iostream>
#include<cmath>
using namespace std;

static const int T[22] = {2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991};


bool P[992];

void init(){
    for ( int i = 0; i <= 991; i++ ) P[i] = false;
    for ( int i = 0; i < 22; i++ ) P[T[i]] = true;
}

int getNumber( int n, int end ){
    if ( n > 991 ) return 0;
    for ( int i = n+1; i <= end; i++ ){
	if ( P[i] ) return i;
    }
    return 0;
}

int main(){
    init();
    int n;
    while( cin >> n && n ){
	int d = (int)(log10(n))+1;
	int p = 1; 
	for ( int i = 0; i < d; i++ ) p *= 10;
	cout << getNumber(n, p) << endl;
    }

}
