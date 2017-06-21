#include<iostream>
#include<algorithm>
using namespace std;

main(){
    int A[5];
    while( cin >> A[0] ){
	for ( int i = 1; i < 5; i++ ) cin >> A[i];
	sort(A, A+5);
	for ( int i = 4; i >= 0; i-- ) {
	    if ( i != 4 ) cout << " ";
	    cout << A[i];
	}
	cout << endl;
    }
}
