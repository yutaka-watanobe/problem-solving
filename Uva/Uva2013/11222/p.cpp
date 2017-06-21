#include<iostream>
#include<algorithm>
using namespace std;

#define PMAX 10001

int problems[PMAX];

void compute(){
    for ( int i = 0; i < PMAX; i++ ) problems[i] = 0;
    int A, B, C, s, p; 
    cin >> s;
    for ( int i = 0; i < s; i++ ) { cin >> p; problems[p] |= 1; }
    cin >> s;
    for ( int i = 0; i < s; i++ ) { cin >> p; problems[p] |= (1 << 1); }
    cin >> s;
    for ( int i = 0; i < s; i++ ) { cin >> p; problems[p] |= (1 << 2); }
    
    A = B = C = 0;
    
    for ( int i = 0; i < PMAX; i++ ){
	if ( problems[i] == 1 ) A++;
	if ( problems[i] == 2 ) B++;
	if ( problems[i] == 4 ) C++;
    }

    int m = max( A, max(B, C));
    
    if ( A == m ){
	cout << "1 " << m;
	for ( int i = 0; i < PMAX; i++ ) {
	    if ( problems[i] == 1 ) cout << " " << i;
	}
	cout << endl;
    }

    if ( B == m ){
	cout << "2 " << m;
	for ( int i = 0; i < PMAX; i++ ) {
	    if ( problems[i] == 2 ) cout << " " << i;
	}
	cout << endl;
    }

    if ( C == m ){
	cout << "3 " << m;
	for ( int i = 0; i < PMAX; i++ ) {
	    if ( problems[i] == 4 ) cout << " " << i;
	}
	cout << endl;
    }


}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	cout << "Case #" << i+1 << ":" << endl;
	compute();
    }
}
