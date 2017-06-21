#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define N 12
#define TOP 0
#define RIGHT 1
#define BOTTOM 2
#define LEFT 3

string P[N+1];
map<string, bool> visited;
bool used[N];
int nway;

int factorial( int n ){
    int x = 1;
    for ( int i = 1; i <= n; i++ ) x *= i;
    return x;
}

void dfs( int pos, string state ){
    if ( pos == N ){ nway++;  return; }

    string nstate, target;
    int i, j;
    for ( int p = 0; p < N; p++ ){
	if ( used[p] ) continue;
	i = pos/3; j = pos%3;
	if ( j > 0 && P[p][LEFT] != state.substr((pos-1)*4, 4)[RIGHT] ) continue;
	if (i > 0 && P[p][TOP] != state.substr((pos-3)*4, 4)[BOTTOM] ) continue;
	nstate = state + P[p];
	if ( visited[nstate] ) continue;
	used[p] = true;
	visited[state] = true;
	dfs( pos+1, nstate );
	used[p] = false;
    }
}

int compute(){
    int ans = 1;
    sort( P, P + N );
    P[N] = "";
    string pre = P[0];
    int cnt = 1;
    for ( int i = 1; i <= N; i++ ){
	if ( pre == P[i] ){
	    cnt++;
	} else {
	    ans *= factorial(cnt);
	    cnt = 1;
	}
	pre = P[i];
    }

    nway = 0;
    visited = map<string, bool>();
    for ( int i = 0; i < N; i++ ) used[i] = false;
    
    dfs(0, "");
    
    return ans * nway;
}

int main(){
    int tcase; cin >> tcase;
    for ( int i = 1; i <= tcase; i++ ){
	for ( int j = 0; j < N; j++ ) cin >> P[j];
	cout << "Case " << i << ": " << compute() << endl;
    }
    return 0;
}
