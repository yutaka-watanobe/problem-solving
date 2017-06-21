#include<iostream>
using namespace std;
#define MAX 10000000

bool P[MAX + 1];

void eratos(){
    for ( int i = 0; i <= MAX; i++ ) P[i] = true;
    P[0] = P[1] = false;
    for ( int i = 2; i*i <= MAX; i++ ){
	if ( P[i] )
	    for ( int j = 2; i*j <= MAX; j++ ) P[i*j] = false;
    }
}

int getQuads(int n){
    for ( int i = n; i >= 13; i--)
	if ( P[i] && P[i-2] && P[i-6] && P[i-8] ) return i;
}

int main(void){
    eratos();
    int n;
    while( cin >> n && n ) cout << getQuads(n) << endl;

    return 0;
}
