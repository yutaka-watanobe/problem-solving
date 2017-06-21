#include<iostream>
using namespace std;

main(){
    int tcase; cin >> tcase;
    int n;
    for ( int i = 1; i <= tcase; i++ ){
	
	cin >> n;
	int p = -1;
	while(1){
	    cout << n % (2*p) << " ";
	    n /= (2*p);
	    if ( n == 0 ) break;
	    p*= -1;
	}
	cout << endl;

    }
}
