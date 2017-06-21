#include<iostream>
#include<queue>
#include<map>
using namespace std;
#define MAX 50
#define INFTY (1<<10)

class State{
    public:
    int ty, tx, ky, kx, t;
    State(int ty=0, int tx=0, int ky=0, int kx=0, int t=0):
	ty(ty), tx(tx), ky(ky), kx(kx), t(t){}

    bool operator < ( const State &s) const{
	if ( ty != s.ty ) return ty < s.ty;
	if ( tx != s.tx ) return tx < s.tx;
	if ( ky != s.ky ) return ky < s.ky;
	if ( kx != s.kx ) return kx < s.kx;
	return false;
    }
};

int H, W, G[MAX][MAX];

bool isBlock(int y, int x){
    if ( 0 > y || 0 > x || y >= H || x >= W ) return true;
    return G[y][x];
}

int bfs(int ty, int tx, int ky, int kx){
    queue<State> Q;
    map<State, bool> V;
    State start = State(ty, tx, ky, kx, 0);
    V[start] = true;
    Q.push(start);

    State u, v;
    const int dy[4] = {0, -1, 0, 1};
    const int dx[4] = {1, 0, -1, 0};
    int nty, ntx, nky, nkx;

    while(!Q.empty()){
	u = Q.front(); Q.pop();
	if ( u.tx == u.kx && u.ty == u.ky ) return u.t; 
	for ( int r = 0; r < 4; r++ ){
	    nty = u.ty + dy[r];
	    ntx = u.tx + dx[r];
	    nky = u.ky + dy[r]*(-1);
	    nkx = u.kx + dx[r]*(-1);
	    if ( isBlock(nty, ntx) ){ nty = u.ty; ntx = u.tx; }
	    if ( isBlock(nky, nkx) ){ nky = u.ky; nkx = u.kx; }
	    v = State(nty, ntx, nky, nkx);
	    if ( !V[v] ){
		v.t = u.t + 1;
		V[v] = true;
		Q.push(v);
	    }
	}
    }
    return INFTY;
}

int main(){
    int tx, ty, kx, ky;
    while( cin >> W >> H && W ) {
	cin >> tx >> ty >> kx >> ky;
        for ( int i = 0; i < H; i++ )
	    for ( int j = 0; j < W; j++ ) cin >> G[i][j];
	int t = bfs(ty-1, tx-1, ky-1, kx-1);
	if ( t == INFTY ) cout << "NA" << endl;
	else cout << t << endl;
    }
    return 0;
}

/*
グリッド上を双子が真逆に移動するとき、二人が出会うまでの最短の時間を求める問題です。壁を含んだグリッドの升目と、二人の初期位置が与えられます。

状態遷移による幅優先探索を実装するプログラムが記述できるかどうかが問われています。

状態を表すためにクラス State を定義します。１つの状態は二人の位置(ty, tx)及び(ky, kx)で表します。その状態に移った時間を保持しておくために t も宣言します。１度訪問した状態を map で管理するため、Stateクラスには比較演算子を定義する必要があります。ここでは、二人の位置関係で異なる状態の大小関係を定義しています。この状態空間の中で幅優先探索を行い最短の時間を求めます。
 */
