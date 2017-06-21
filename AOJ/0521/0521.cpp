#include<iostream>
using namespace std;

int main(){
    int n, v;
    int C[7] = {1000, 500, 100, 50, 10, 5, 1};
    while(1){
	cin >> n;
	if ( n == 0 ) break;
	v = 1000 - n;
	int cnt = 0;
	for ( int c = 0; c < 7; c++ ){
	    while( v >= C[c] ) { cnt++; v -= C[c]; };
	}
	cout << cnt << endl;

    }
}
