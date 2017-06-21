#include<iostream>
using namespace std;

int q1, b, c1, c2, q2;

void compute(){
    cin >> b >> c1 >> c2 >> q2;
    for ( int aizu = q2; aizu >= 1; aizu-- ){
	if ( aizu*c1 > b ) continue;
	int rem = b - aizu*c1;
	int conv = rem/c2;
	if ( aizu + conv >= q1 ) {
	    cout << aizu << " " << conv << endl;
	    return;
	}
    }
    cout << "NA" << endl;
}

int main(){
    while( cin >> q1 && q1 ) compute(); 
    return 0;
}
