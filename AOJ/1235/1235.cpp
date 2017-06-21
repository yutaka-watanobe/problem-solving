#include<iostream>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++)
#define MAX 13

int G[MAX][MAX], N, C;
bool V[MAX][MAX];
static int di[6] = {0, -1, -1, 0, 1, 1};
static int dj[6] = {1, 1, 0, -1, -1, 0};
int cnt;
bool hasZero;

void dfs( int i, int j, int id ){
    V[i][j] = true;
    int ni, nj;
    cnt++;
    rep(r, 6){
	if (G[i+di[r]][j+dj[r]] == 0 ) hasZero = true;
    }
    rep(r, 6){
	ni = i+di[r];
	nj = j+dj[r];
	if ( G[ni][nj] == id && !V[ni][nj] ) dfs(ni, nj, id);
    }
}

int getScore(){
    rep(i, N+2) rep(j, N+2) V[i][j] = false;
    int score = 0;
    for ( int i = 1; i <= N; i++ ){
	for ( int j = 1; j <= N-i+1; j++ ) {
	    if ( G[i][j] > 0 && !V[i][j] ){
		hasZero = false;
		cnt = 0;
		dfs(i, j, G[i][j]);
		if ( !hasZero){
		    if ( G[i][j] == C ) score -= cnt;
		    else score += cnt;
		}
	    }
	}
    }
    return score;
}

void compute(){
    int ans = -1000;
    for ( int i = 1; i <= N; i++ ){
	for ( int j = 1; j <= N-i+1; j++ ) {
	    if ( G[i][j] == 0 ){
		G[i][j] = C;
		ans = max(ans, getScore());
		G[i][j] = 0;
	    }
	}
    }
    cout << ans << endl;
}

main(){
    while( cin >> N >> C && N && C ){
	rep(i, N+3) rep(j, N+3)G[i][j] = 10;
	for ( int i = 1; i <= N; i++ ){
	    for ( int j = 1; j <= i; j++ ){
		cin >> G[i-j+1][j];
	    }
	}
	
	compute();
    }
}
