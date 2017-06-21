#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, n) for ( int i = 0; i < (int)n; i++ )
#define MAX 1000
#define INFTY (1 << 21)
#define NORTH 0
#define SOUTH 1

int R, C, B, S, D[MAX];
int bottom[MAX], top[MAX];
char G[MAX][MAX];
void dfs( int i, int j, int t[MAX], int dir, bool V[MAX][MAX] ){
    V[i][j] = true;
    if ( dir == NORTH ) t[j] = max(i, t[j] );
    else t[j] = min(i, t[j]);

    static const int di[4] = {0, -1, 0, 1};
    static const int dj[4] = {1, 0, -1, 0};
    int ni, nj;
    for ( int r = 0; r < 4; r++ ){
	ni = i + di[r];
	nj = j + dj[r];
	if ( ni < 0 || nj < 0 || R <= ni || C <= nj  ) continue;
	if ( !V[ni][nj] && G[ni][nj] == '#' ) dfs(ni, nj, t, dir, V);
    }
}

void makeDistance(){
    bool V[MAX][MAX];
    rep(i, C) { bottom[i] = 0; top[i] = R+1; }
    rep(i, R) rep(j, C) V[i][j] = false;
    dfs( 0, 0, bottom, NORTH, V );
    dfs( R-1, 0, top, SOUTH, V );
    rep(i, C) D[i] = top[i] - bottom[i] - 1;
}

void compute(){
    makeDistance();

    int T[MAX][MAX];
    rep(i, R) rep(j, C) T[i][j] = INFTY;
    rep(j, C) T[0][j] = D[j];

    for ( int i = 0; i < B-1; i++ ){
	int sj;
	for(sj = 0; ; sj++) if ( T[i][sj] != INFTY ) break;
	for ( int j = sj; j < C; j++ ){
	    for ( int k = j+S+1; k < C; k++ ){
		T[i+1][k] = min(T[i+1][k], T[i][j] + D[k]);
	    }
	}
    }

    int minv = INFTY;
    for ( int j = 0; j < C; j++ ){
	minv = min(minv, T[B-1][j]);
    }

    cout << minv << endl;
}

int main(){
    while( cin >> R >> C ){
	cin >> B >> S;
	rep(i, R) rep(j, C)  cin >> G[i][j];
	compute();
    }
    return 0;
}
