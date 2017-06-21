#include<iostream>
using namespace std;
#define A 0
#define B 1
#define C 2
#define D 3
#define LEFT 0
#define RIGHT 1

main(){
    int T[4][2];
    for ( int i = 0; i < 4; i++ ) T[i][0] = T[i][1] = 0;
    double left, right;
    while( cin >> left >> right ){
	if ( 1.1 <= left) T[A][LEFT]++;
	if ( 1.1 <= right) T[A][RIGHT]++;
	if ( 0.6 <= left && left < 1.1 ) T[B][LEFT]++;
	if ( 0.6 <= right && right < 1.1 ) T[B][RIGHT]++;
	if ( 0.2 <= left && left < 0.6 ) T[C][LEFT]++;
	if ( 0.2 <= right && right < 0.6 ) T[C][RIGHT]++;
	if ( left < 0.2 ) T[D][LEFT]++;
	if ( right < 0.2 ) T[D][RIGHT]++;
    }
    
    for ( int i = 0; i < 4; i++ ) {
	cout << T[i][0] << " " << T[i][1] << endl;
    }
}
