#include<iostream>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++)

int di[4] = {0, -1, 0, 1};
int dj[4] = {1, 0, -1, 0};
char G[12][6];
int nseq, cnt;
bool v[12][6];

void reset(){ rep(i, 12) rep(j, 6) v[i][j] = false; }

bool isColor( char c ){
    return c == 'R' || c == 'G' || c == 'B' || c == 'Y' || c == 'P';
}

void dfs(int y, int x, char c){
    cnt++;
    int ni, nj;
    v[y][x] = true;
    rep(r, 4){
	ni = y + di[r];
	nj = x + dj[r];
	if ( ni < 0 || nj < 0 || ni >= 12 || nj >= 6 ) continue;
	if ( !v[ni][nj] && c == G[ni][nj] ) dfs(ni, nj, c);
    }
}

void parse(int y, int x, char c){
    int ni, nj;
    G[y][x] = 'X';
    rep(r, 4){
	ni = y + di[r];
	nj = x + dj[r];
	if ( ni < 0 || nj < 0 || ni >= 12 || nj >= 6 ) continue;
	if ( c == G[ni][nj] ) parse(ni, nj, c);
    }
}

bool simulate(){
  

    bool isR = false;
    rep(i, 12) rep(j, 6){
	cnt = 0;
	if ( isColor(G[i][j])){
	    reset();
	    dfs(i, j, G[i][j]);
	}
	if ( cnt >= 4 ){
	    reset();
	    parse(i, j, G[i][j]);
	    isR = true;
	}
    }

    
    rep(i, 12) rep(j, 6){
	if ( G[i][j] != 'O' ) continue;
	rep(r, 4){
	    int ni = i + di[r];
	    int nj = j + dj[r];
	    if ( ni < 0 || nj < 0 || ni >= 12 || nj >= 6 ) continue;
	    if ( G[ni][nj] == 'X' ) G[i][j] = 'x';
	}
    }
   
    rep(i, 12) rep(j, 6) if ( G[i][j] == 'X' || G[i][j] == 'x' ) G[i][j] = '.';
    
  




    for ( int j = 0; j < 6; j++ ){
	while(1){
	    bool isChange = false;
	    for ( int i = 11; i >= 1; i-- ){
		if ( G[i][j] == '.' && G[i-1][j] != '.' ){
		    G[i][j] = G[i-1][j];
		    G[i-1][j] = '.';
		    isChange = true;
		    break;
		}
	    }
	    if ( !isChange ) break;
	}
    }


    return isR;
}

void compute(){
    rep(i, 12) rep(j, 6) cin >> G[i][j];
    nseq = 0;
    while(simulate()){ nseq++; }
    cout << nseq << endl;
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ) compute();
}
