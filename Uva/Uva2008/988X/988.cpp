#include<iostream>
using namespace std;
#define REP(i, e) for ( int i = 0; i < e; i++ )
#define MAX 5000
int N;
bool G[MAX][MAX];
long long T[MAX][MAX];
int outdeg[MAX];


void compute(){
    REP(i, N) REP(j, N) T[i][j] = 0;

    T[0][0] = 1;
    REP(j, N-1) REP(i, N){
	REP(v, N){
	    if ( G[i][v] ) T[v][j+1] += T[i][j];
	}
    }

    unsigned long long sum = 0;
    REP(i, N) REP(j, N ){
	if ( outdeg[i] == 0 ) sum += T[i][j];
    }
    cout << sum << endl;
}

void input(){
    int k, t;
    REP(i, N) REP(j, N) G[i][j] = false;
    REP(i, N){
	cin >> k;
	outdeg[i] = k;
	REP(j, k){
	    cin >> t;
	    G[i][t] = true;
	}
    }
}

int main(){
    while ( cin >> N ){
	input();
	compute();
    }
    return 0;
}
