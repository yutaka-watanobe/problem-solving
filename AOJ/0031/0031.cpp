#include<iostream>
#include<bitset>
using namespace std;
int W[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

main(){
    int weight;
    bitset<10> B;

    while ( cin >> weight ){
	B = weight;
	bool isFirst = true;
	for ( int i = 0; i < 10; i++ ) {
	    if ( B[i] ) {
		if ( isFirst ) isFirst = false;
		else cout << " ";
		cout << W[i];
	    }
	}
	cout << endl;
    }
}
