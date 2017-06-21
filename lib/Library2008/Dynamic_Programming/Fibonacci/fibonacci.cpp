#include<iostream>
using namespace std;
#define MAX 40

int fibonacci( int i ){
    if ( i == 0 ) return 0;
    if ( i == 1 ) return 1;
    return fibonacci(i - 2) + fibonacci(i - 1);
}

int F[MAX];

void makeFibonacci(){
    F[0] = 0;
    F[1] = 1;
    for ( int i = 2; i < MAX; i++ ) F[i] = F[i-2] + F[i-1];
}

main(){
    makeFibonacci();
    int i; cin >> i;
    cout << fibonacci(i) << "  " << F[i] << endl;
    cout << F[i] << endl;
}

