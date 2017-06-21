#include<iostream>
using namespace std;
#define REP(i, n) for ( int i = 0; i < (int)n; i++ )
#define MAX 12

int search( int T[MAX], int n, int t ){
    int sum = 0;
    REP(i, n) if ( T[i] == t ) sum++;
    return sum;
}

main(){
    int count;
    int T[MAX], P[MAX], n;
    
    while( cin >> n && n ){
	REP(i, n) cin >> T[i];
	count = 0;
	while(1){
	    REP(i, n){
		P[i] = search(T, n, T[i]);
	    }
	    
	    int same = true;
	    REP(i,n ) if ( T[i] != P[i] ) same = false;
	    if ( same ) {
		cout << count << endl;
		REP(i,n){
		    if ( i ) cout << " ";
		    cout << P[i];
		}
		cout << endl;
		break;
	    } else {
		REP(i, n) T[i] = P[i];
		count++;
	    }
	}
    }
    
}
