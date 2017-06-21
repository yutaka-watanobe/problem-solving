#include<iostream>
#include<cstdio>
#include<cassert>
using namespace std;
#define rep(i,n) for ( int i = 0; i < n; i++ )
#define MAX 20

static const int T[6] = {10, 5, 3, 6, 12, 9};
int G[MAX][MAX], H, W, ncell, vcell, V[MAX][MAX];

bool eq(int a, int i, int b, int j){
    return ((a & (1<<i)) > 0) == ((b & (1<<j)) > 0);
}

void dfs(int i, int j){
    V[i][j] = true;
    vcell++;
    static int di[4] = {0, -1, 0, 1};
    static int dj[4] = {1, 0, -1, 0};

    rep(s, 4){
	int ni = i + di[s];
	int nj = j + dj[s];
	if ((G[i][j] & (1<<s)) && !V[ni][nj]) dfs(ni, nj);
    }
}

bool rec(int pos){
    if ( pos == H*W ) {
	vcell = 0;
	rep(i, H) rep(j, W) V[i][j] = false;
	rep(i, H) rep(j, W){
	    if ( G[i][j] == 0 ) continue;
	    dfs(i, j);
	    return ncell == vcell;
	}
	return false;
    }
    int i = pos/W;
    int j = pos%W;
    if ( G[i][j] == 0 ){
	int v = 0;
	if ( j && !eq( G[i][j-1], 0, v, 2 ) )  return false;
	if ( i && !eq( G[i-1][j], 3, v, 1 ) )   return false;
	if ( rec(pos+1) ) return true ;
    } else {
	rep(t, 6){
	    int v = T[t];
	    if ( j && !eq( G[i][j-1], 0, v, 2 ) ) continue;
	    if ( i && !eq( G[i-1][j], 3, v, 1 ) ) continue;
	    if ( i == 0 && (v&(1<<1)) ) continue;
	    if ( i == H-1 && (v&(1<<3)) ) continue;
	    if ( j == 0 && (v&(1<<2)) ) continue;
	    if ( j == W-1 && (v&1) ) continue;
	    G[i][j] = v;
	    if ( rec(pos+1) ) return true;
	}
    }
    return false;
}

main(){
    while(1){
      cin >> W >> H;
      //      assert( W <= 7 && H <= 7 );
	if ( H == 0 && W == 0 ) break;
	ncell = 0;
	rep(i, H) rep(j, W){ 
	    cin >> G[i][j];
	    if ( !G[i][j] ) ncell++;
	    G[i][j] = (G[i][j] ? 0 : 1); 
	}

	bool r = rec(0);
	if (r){
	  cout << "Yes" << endl;
	} else{
	  cout << "No" << endl;
	}
    }
}
