#include<iostream>

using namespace std;

void compute(){
    string buffer[10];
    for ( int i = 0; i < 10; i++ ) cin >> buffer[i];
    int M = buffer[0].size() - 2;
    for ( int j = 1; j <= M; j++ ){
	int sum = 0;	
	int p = 1;
	for ( int i = 1; i <= 8; i++ ){
	    sum += (buffer[i][j] == '/') ? 0 : p;
	    p *= 2;
	}
	cout << (char)sum;
    }
    cout << endl;
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	compute();
    }
}
