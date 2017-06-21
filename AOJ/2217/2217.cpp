#include<iostream>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )
static const int MAX = 100;

int N, V[MAX][MAX], ans;
pair<int, int> G[MAX][MAX];

void dfs( int y , int x , int id ){
    V[y][x] = id;
    int nx = G[y][x].first;
    int ny = G[y][x].second;
    if ( V[ny][nx] == id ) ans++;
    if ( V[ny][nx] == 0 ) dfs(ny, nx, id);
}

void solve(){
    rep(i, N) rep(j, N) V[i][j] = 0;
    int ncomp = 0;
    ans = 0;

    rep(i, N) rep(j, N){
	if ( V[i][j] == 0 ){
	    ncomp++;
	    dfs(i, j, ncomp);
	}
    }
    cout << ans << endl;
}

main(){
    int px, py;
    while( cin >> N && N ){
	rep(y, N) rep(x, N){
	    cin >> px >> py;
	    G[y][x] = make_pair(px, py);
	}
	solve();
    }
}
