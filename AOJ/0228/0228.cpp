#include<iostream>
using namespace std;

void printBit(int x, int w){
    if (!w) return;
    printBit(x/2, w-1);
    cout << x%2;
}

main(){
    int B[11] = {63, 6, 91, 79, 102, 109, 125, 39, 127, 111, 0};
    int n, p;
    while( cin >> n && n != -1 ){
	for ( int i = 0, cur = 10; i < n; i++ ){
	    cin >> p;
	    printBit(B[cur]^B[p], 7);
	    cout << endl;
	    cur = p;
	}
    }
}
