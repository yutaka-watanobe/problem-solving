#include<iostream>
using namespace std;

main(){
    int S, tcase =1, P[12], R[12];
    
    while(1){
	cin >> S;
	if ( S < 0 ) break;
	cout << "Case " << tcase++ << ":" << endl;
	for ( int i = 0; i < 12; i++ ) cin >> P[i];
	for ( int i = 0; i < 12; i++ ) cin >> R[i];

	for ( int i = 0; i < 12; i++ ){
	    if ( S < R[i] ){
		cout << "No problem. :(" << endl;
	    } else {
		cout << "No problem! :D" << endl;
		S -= R[i];
	    }
	    S += P[i];
	}
    }
}
