#include<iostream>
#include<stack>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )
#define M 50
const int di[4] = {0, -1, 0, 1};
const int dj[4] = {1, 0, -1, 0};
char L[M][M], R[M][M];

int W, H, lg, rg;

bool check(int y, int x){
    return 0 <= y && 0 <= x && y < H && x < W;
}
bool dfs(int lp, int rp){
    bool V[M*M][M*M];
    rep(i, W*H) rep(j, W*H) V[i][j] = false;
    stack<pair<int, int> > S;
    S.push(make_pair(lp, rp));
    pair<int, int> u, v;
    while(!S.empty()){
	u = S.top(); S.pop();
	lp = u.first; rp = u.second;
	if ( lp == lg && rp == rg ) return true;
	if ( lp == lg || rp == rg ) continue;
	int lny, lnx, rny, rnx;
	rep(d, 4){
	    lny = lp/W + di[d];
	    lnx = lp%W + dj[d];
	    rny = rp/W + ((d%2==1)?di[d]:di[(d+2)%4]);
	    rnx = rp%W + ((d%2==1)?dj[d]:dj[(d+2)%4]);
	    if ( !(check(lny, lnx) && L[lny][lnx] != '#')) { lny = lp/W; lnx = lp%W; }
	    if ( !(check(rny, rnx) && R[rny][rnx] != '#')) { rny = rp/W; rnx = rp%W; }
	    int l = lny*W+lnx;
	    int r = rny*W+rnx;
	    if ( !V[l][r] ) { V[l][r] = true; S.push(make_pair(l, r));}
	}
    }
    return false;
}

main(){
    int lp, rp;
    while( cin >> W >> H && W ){
	rep(i, H) {
	    rep(j, W) {
		cin >> L[i][j];
		if ( L[i][j] == 'L' ) lp = i*W+j;
		if ( L[i][j] == '%' ) lg = i*W+j;
	    }
	    rep(j, W) {
		cin >> R[i][j];
		if ( R[i][j] == 'R' ) rp = i*W+j;
		if ( R[i][j] == '%' ) rg = i*W+j;
	    }
	}
	if ( dfs(lp, rp) ) cout << "Yes" << endl;
	else cout << "No" << endl;
    }
}
