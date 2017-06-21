#include<iostream>
using namespace std;

#define MAX 40

int fibonacci( int i ){
    if ( i == 0 ) return 0;
    if ( i == 1 ) return 1;
    return fibonacci(i - 2) + fibonacci(i - 1);
}

int main(void){
    int i; cin >> i;
    cout << fibonacci(i) << endl;

    return 0;
}

