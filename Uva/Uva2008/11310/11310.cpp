#include<iostream>
using namespace std;
#define MAX 50
typedef unsigned long long ullong;

main(){
    ullong T[MAX];
    T[0] = 1;
    T[1] = 1;
    T[2] = 5;

    for ( int i = 3; i < MAX; i++ ){
	T[i] = 2*T[i-3] + 4*T[i-2] + T[i-1];
    }

    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	int n; cin >> n;
	cout << T[n] << endl;
    }
}
