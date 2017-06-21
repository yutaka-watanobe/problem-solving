#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 31

main(){
    int T[MAX], w, n, a, b;
    char ch;
    cin >> w >> n;
    for ( int i = 1; i <= w; i++ ) T[i] = i;
    for ( int i = 0; i < n; i++ ){
	cin >> a >> ch >> b;
	swap(T[a], T[b]);
    }
    for ( int i = 1; i <= w; i++ ) cout << T[i] << endl;
}
