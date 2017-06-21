#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100

int G[MAX][MAX];
bool visited[MAX][MAX];
int W, H;
int mlen;

void dfs( int i, int j, int depth ){

    mlen = max(  mlen, depth );
    
    static const int di[4] = {0, -1, 0, 1};
    static const int dj[4] = {1, 0, -1, 0};

    int ni, nj;
    for ( int r = 0; r < 4; r++ ){
	ni = i + di[r];
	nj = j + dj[r];
	if ( G[ni][nj] == 0 || visited[ni][nj] ) continue;

	visited[ni][nj] = true;
	dfs( ni, nj, depth+1 );
	visited[ni][nj] = false;
    }
}

void init(){
    for ( int i = 1; i <= H; i++ )
	for ( int j = 1; j <= W; j++ ) visited[i][j] = false;
}

void compute(){
    mlen = 0;
    for ( int i = 1; i <= H; i++ ){
	for ( int j = 1; j <= W; j++ ){
	    if ( G[i][j] == 0 ) continue;
	    init();
	    dfs(i, j, 0);
	}
    }
    cout << mlen << endl;
}

main(){
    while(1){
	cin >> W >> H;
	if ( W == 0 && H == 0 ) break;
	for ( int i = 0; i < H+2; i++ )
	    for ( int j = 0; j < W+2; j++ ) G[i][j] = 0;
	for ( int i = 1; i <= H; i++ )
	    for ( int j = 1; j <= W; j++ ) cin >> G[i][j];
	compute();
    }
}
