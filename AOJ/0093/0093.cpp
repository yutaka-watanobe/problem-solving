#include<iostream>
using namespace std;

bool isLeapYear(int y){
    if ( y % 4 == 0 ){
	if ( y % 100 == 0 ){
	    if ( y % 400 == 0 ) return true;
	    else return false;
	} else {
	    return true;
	}
    } else {
	return false;
    }
}

int main(){
    int a, b;
    int tcase = 0;
    while(1){
	cin >> a >> b;
	if ( a == 0 && b == 0 ) break;

	int cnt = 0;
	if ( tcase ) cout << endl;
	for ( int i = a; i <= b; i++ ){
	    if ( isLeapYear(i) ) { cout << i << endl; cnt++;}
	}
	if ( cnt == 0 ) cout << "NA" << endl;

	tcase++;
    }
    return 0;
}
