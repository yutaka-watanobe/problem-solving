#include<iostream>
using namespace std;
#define MAX 30
int F[MAX+1];

main(){
    F[0] = 1;
    F[1] = 1;
    F[2] = 2;
    for ( int i = 3; i <= MAX; i++ ) F[i] = F[i-3] + F[i-2] + F[i-1];

    int n;
    while( cin >> n && n ){
	int p = F[n]/10;
	if ( F[n]%10 ) p++;
	int pp = p/365;
	if ( p%356) pp++;

	cout <<  pp << endl;
    }
}
