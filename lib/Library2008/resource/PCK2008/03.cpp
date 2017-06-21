#include<iostream>
using namespace std;
#define BASE 4

void parse( int x ){
    if ( x / BASE ) parse( x / BASE );
    cout << x % BASE;
}

int main(){
    int n;
    while( cin >> n && n >= 0){
	parse(n);
	cout << endl;
    }
    return 0;
}
