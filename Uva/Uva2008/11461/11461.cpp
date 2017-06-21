#include<iostream>
using namespace std;
#define MAX 100000

int T[MAX+1];

void initialize(){
    for ( int i = 0; i <= MAX; i++ ) T[i] = 0;
    for ( int i = 1; i*i <= MAX; i++ ) T[i*i] = 1;
    for ( int i = 1; i <= MAX; i++ ) T[i] += T[i-1];
}

int main(){
    initialize();
    int a, b;
    while( cin >> a >> b && a && b ){
	cout << T[b] - T[a-1] << endl;
    }
}
