#include<iostream>
using namespace std;

#define MAX 40

int F[MAX];

void makeFibonacci(){
    F[0] = 0;
    F[1] = 1;
    for ( int i = 2; i < MAX; i++ ) F[i] = F[i-2] + F[i-1];
}

int main(void){
    makeFibonacci();
    int i; cin >> i;
    cout << F[i] << endl;

    return 0;
}

