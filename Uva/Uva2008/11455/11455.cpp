#include<iostream>
#include<algorithm>
using namespace std;

main(){
    int tcase; cin >> tcase;
    int L[4];
    for ( int i = 0; i < tcase; i++ ) {
	for ( int j = 0; j < 4; j++ ) cin >>  L[j];
	sort( L, L + 4 );

	if ( L[0] == L[1] && L[1] == L[2] && L[2] == L[3] ){
	    cout << "square" << endl;
	} else if ( L[0] == L[1] && L[2] == L[3] ){
	    cout << "rectangle" << endl;
	} else if ( L[0] + L[1] + L[2] > L[3] ){
	    cout << "quadrangle" << endl;
	} else cout << "banana" << endl;
    }
}
