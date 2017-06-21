#include<iostream>
using namespace std;

main(){
    int stack[12], top, x;
    top = 0;
    while( cin >> x ){
	if ( x == 0 ) { cout << stack[top--] << endl; }
	else { top++; stack[top] = x; }
    }
}
