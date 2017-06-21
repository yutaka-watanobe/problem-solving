// gorioshi
#include<iostream>
using namespace std;
#define KMAX 50000
#define LIMIT 710
int M[KMAX+1][3];

void generate(){
    for ( int i = 0; i <= KMAX; i++ ){
	for ( int j = 0; j < 3; j++ ) M[i][j] = -1;
    }

    int value;
    for ( int i = 0; i <= LIMIT; i++ ){
	for ( int j = 0; j <= LIMIT; j++ ){
	    if ( i*i + j*j > KMAX ) continue;
	    for ( int k = 0; k <= LIMIT; k++ ){
		value = i*i + j*j + k*k;
		if ( value > KMAX ) {
		    k = LIMIT;
		    continue;
		}
		if ( M[value][0] >= 0 ) continue;
		M[value][0] = i;
		M[value][1] = j;
		M[value][2] = k;
	    }
	}
    }
}

main(){
    generate();
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	int k; cin >> k;
	if ( M[k][0] == -1 ) cout << "-1" << endl;
	else cout << M[k][0] << " " << M[k][1] << " " << M[k][2] << endl;
    }
}
