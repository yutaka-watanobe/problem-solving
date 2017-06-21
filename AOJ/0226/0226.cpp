#include<iostream>
#include<string>
using namespace std;

main(){
    string r, a;
    while(1){
	cin >> r >> a;
	if ( a == "0" ) break;
	int hit = 0, blow = 0;
	for ( int i = 0; i < 4; i++ ){
	    for ( int j = 0; j < 4; j++ ){
		if ( r[i] != a[j] ) continue;
		if ( i == j ) hit++;
		else blow++;
	    }
	}
	cout << hit << " " << blow << endl;
    }
}
