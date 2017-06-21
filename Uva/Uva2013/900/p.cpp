#include<iostream>
using namespace std;
#define MAX 50
typedef unsigned long long ullong;

ullong F[MAX+1];

void init(){
    F[0] = F[1] = 1;
    for ( int i = 2; i <= MAX; i++ ){
	F[i] = F[i-1] + F[i-2];
    }
}

main(){
    init();
    int n;
    while (1){
	cin >> n;
	if ( n == 0 ) break;
	cout << F[n] << endl;
    }
}
