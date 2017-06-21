#include<iostream>
#include<queue>
#include<map>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )
#define MAX 50
#define INFTY (1<<10)

int H, W, G[MAX][MAX];

bool isBlock(int y, int x){
    if ( 0 > y || 0 > x || y >= H || x >= W ) return true;
    return G[y][x];
}

int bfs(int tx, int ty, int kx, int ky){
    queue<pair<int, int> > Q;
    map<pair<int, int>, int> D;
    int pt = ty*W + tx;
    int pk = ky*W + kx;
    D[make_pair(pt,pk)] = 0;
    Q.push(make_pair(pt, pk));

    pair<int, int> u, v;
    const int dy[4] = {0, -1, 0, 1};
    const int dx[4] = {1, 0, -1, 0};
    int nty, ntx, nky, nkx, npt, npk;

    while(!Q.empty()){
	u = Q.front(); Q.pop();
	ty = u.first/W;
	tx = u.first%W;
	ky = u.second/W;
	kx = u.second%W;
	pt = ty*W + tx;
	pk = ky*W + kx;
	if ( pt == pk ) return D[make_pair(pt,pk)];
	rep(r, 4){
	    nty = ty + dy[r];
	    ntx = tx + dx[r];
	    nky = ky + dy[r]*(-1);
	    nkx = kx + dx[r]*(-1);
	    npt = (isBlock(nty, ntx))? pt : nty*W+ntx;
	    npk = (isBlock(nky, nkx))? pk : nky*W+nkx;
	    if ( D.find(make_pair(npt, npk)) == D.end() ){
		D[make_pair(npt,npk)] = D[make_pair(pt,pk)] + 1;
		Q.push(make_pair(npt, npk));
	    }
	}
    }
    return -1;
}

main(){
    int tx, ty, kx, ky;
    while(1){
	cin >> W >> H;
	if ( W == 0 && H == 0 ) break;
	cin >> tx >> ty >> kx >> ky;
	tx--; ty--; kx--; ky--;
	rep(i, H) rep(j, W) G[i][j] = 1;
	rep(i, H) rep(j, W) cin >> G[i][j];
	int cost = bfs(tx, ty, kx, ky);
	if ( cost < 0 ) cout << "NA" << endl;
	else cout << cost << endl;
    }
}
