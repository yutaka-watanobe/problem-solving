#include<iostream>
using namespace std;

main(){
    int tcase; cin >> tcase;
    int DDC, DDB, MMC, MMB, YYC, YYB, Y;
    char ch;
    for ( int i = 0; i < tcase; i++ ){
	cin >> DDC >> ch >> MMC >> ch >> YYC;
	cin >> DDB >> ch >> MMB >> ch >> YYB;

	Y = YYC - YYB;
	if ( MMC == MMB ){
	    if ( DDC < DDB ) Y--;
	} else {
	    if ( MMC < MMB ) Y--;
	}

	cout << "Case #" << i+1 << ": ";
	if ( Y < 0 ) cout << "Invalid birth date" << endl;
	else if ( Y > 130 ) cout << "Check birth date" << endl;
	else cout << Y << endl;
    }
}
