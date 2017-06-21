#include<iostream>
using namespace std;

main(){
    int L, M, N;
    while( cin >> L && L ){
	int t = 0, S = 0;
	for ( int i = 1; i <= 12; i++ ){
	    cin >> M >> N; 
	    S += M - N;
	    if ( S >= L && t == 0 ) t = i;
	}
	if ( S < L ) cout << "NA" << endl;
	else cout << t << endl;
    }
}
