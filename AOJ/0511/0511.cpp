#include<iostream>
using namespace std;

int main(){
    int A[31] = {};
    int x;
    for ( int i = 0; i < 28; i++ ){
	cin >> x;
	A[x] = 1;
    }

    for ( int i = 1; i <= 30; i++ ){
	if ( !A[i] ) cout << i << endl;
    }

    return 0;
}
