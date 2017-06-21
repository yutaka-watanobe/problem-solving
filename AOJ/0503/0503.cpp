#include<iostream>
#include<climits>
using namespace std;
#define MAX 20

struct State{
    int S[3][MAX];
    int top[3];
};

int n, m;
State initial, cur;

bool isSame(){
    for ( int i = 0; i < 3; i++ ){
	if ( initial.top[i] != cur.top[i] ) return false;
	for ( int j = 1; j <= initial.top[i]; j++ ){
	    if ( initial.S[i][j] != cur.S[i][j] ) return false;
	}
    }
    return true;
}

int compute(){
    int cnt;
    int from = -1;
    int to = -1;
    for ( cnt = 0; cnt <= m; cnt++ ){
	if ( isSame() ) return cnt;

	if ( cur.S[0][cur.top[0]] > cur.S[1][cur.top[1]] && cur.top[0] && !(from == 1 && to == 0) ) { // 0 -> 1
	    cur.S[1][++cur.top[1]] = cur.S[0][cur.top[0]--];
	    from = 0; to = 1;
	} else if ( cur.S[0][cur.top[0]] < cur.S[1][cur.top[1]] && cur.top[1] && !(from == 0 && to == 1) ) { // 0 <- 1
	    cur.S[0][++cur.top[0]] = cur.S[1][cur.top[1]--];
	    from = 1; to = 0;
	} else if ( cur.S[1][cur.top[1]] > cur.S[2][cur.top[2]] && cur.top[1] && !(from == 2 && to == 1) ) { // 1 -> 2
	    cur.S[2][++cur.top[2]] = cur.S[1][cur.top[1]--];
	    from = 1; to = 2;
	} else if ( cur.S[1][cur.top[1]] < cur.S[2][cur.top[2]] && cur.top[2] && !(from == 1 && to == 2) ) { // 1 <- 2
	    cur.S[1][++cur.top[1]] = cur.S[2][cur.top[2]--];
	    from = 2; to = 1;
	}
    }
    return cnt;
}

int main(){
    while(1){
	cin >> n >> m;
	if ( n == 0 && m == 0 ) break;

	for ( int i = 0; i < 3; i++ ){
	    cin >> initial.top[i];
	    initial.S[i][0] = 0;
	    for ( int j = 1; j <= initial.top[i]; j++ ) cin >> initial.S[i][j];
	}

	int minv = INT_MAX;
	// from A
	for ( int i = 0; i < 3; i++ ) { cur.top[i] = 0; }
	cur.top[0] = n;
	for ( int j = 0; j <= n; j++ ) cur.S[0][j] = j;

	minv = compute();

	// from C
	for ( int i = 0; i < 3; i++ ) { cur.top[i] = 0; }
	cur.top[2] = n;
	for ( int j = 0; j <= n; j++ ) cur.S[2][j] = j;

	minv = min( minv, compute() );

	if ( minv > m ) cout << "-1" << endl;
	else cout << minv << endl;
    }
    return 0;
}

