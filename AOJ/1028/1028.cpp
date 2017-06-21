#include<iostream>
using namespace std;
#define INF (1<<21)

static const int M[6] = {1, 5, 10, 50, 100, 500};

int getMin(int T[], int x){
    int sum = 0, c;
    for ( int i = 5; i >= 0; i--){
	if ( x >= M[i] && T[i] > 0 ){
	    c = min(T[i], x/M[i]);
	    x -= c*M[i];
	    sum += c;
	}
    }

    if ( x > 0 ) return INF;
    return sum;
}

main(){
    int p, T[6];
    int O[6] = {INF, INF, INF, INF, INF, INF};

    while( cin >> p && p ){
	for ( int i = 0; i < 6; i++ ) cin >> T[i];
	int ans = INF;
	for ( int add = 0; add <= 500; add++ ){
	    ans = min(ans, getMin(T, p+add) + getMin(O, add) );
	}
	cout << ans << endl;
    }
}
