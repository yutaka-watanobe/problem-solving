#include<stdio.h>
#include<iostream>
#include<cassert>
#define MAX 10001
 
using namespace std;
 
int T[MAX], M[MAX];
int n;
 
bool read(){
    cin >> n; 
if ( n == 0 ) return false;
 assert( n >=2 );
    for ( int i = 1; i <= n; i++ ) cin >> T[i];
    return true;
}
 
void work(){
    M[0] = 0;
    int maxValue = -1000000000;
    for ( int i = 1; i <= n; i++ ){
    if ( M[i-1] >= 0 ){
        M[i] = M[i-1] + T[i];
    } else {
        M[i] = T[i];
    }
    maxValue = ( maxValue < M[i] ) ? M[i] : maxValue;
    }
 
    cout << maxValue << endl;
}
 
main(){
    while ( read() ){
    work();
    }
}
