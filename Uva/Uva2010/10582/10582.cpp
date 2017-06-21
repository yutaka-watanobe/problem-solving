#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<cmath>
#include<cassert>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)
#define MAX 100

static int di[4] = {0, -1, 0, 1};
static int dj[4] = {1, 0, -1, 0};

class Piece{
    public:
    bool E[4];
    int nrotate;
    Piece(){ rep(i, 4) E[i] = false;}

    void setParam(){
	if ( E[0] == E[2] || E[1] == E[3] ) nrotate = 2;
	else nrotate = 4;
    }

    void rotate(){
	bool tmp = E[0];
	E[0] = E[3]; E[3] = E[2]; E[2] = E[1]; E[1] = tmp;
    }

    int getValue(){
	int sum = 0;
	int p = 1;
	for ( int i = 0; i < 4; i++ ){
	    if ( E[i] ) sum += p;
	    p *= 2;
	}
	return sum;
    }
};

int H, W, cnt;
Piece P[MAX][MAX];
bool visited[MAX][MAX];

void print(){
    for ( int i = 0; i <= H+1; i++ ){
	for ( int j = 0; j <= W+1; j++ ){
	    cout << P[i][j].getValue() << " ";
	}
	cout << endl;
    }
cout << endl;
}

void dfs(int pi, int pj){
    if ( pi == H && pj == W+1 ||
	 pi == H+1 && pj == W ) {
	cnt++; return;
    }

    //cout << pi << "," << pj << endl;


    int nr = P[pi][pj].nrotate;
    int ni, nj;
    for ( int r = 0; r < nr; r++, P[pi][pj].rotate()){

	bool possible = false;
	rep(f, 4){
	    ni = pi + di[f];
	    nj = pj + dj[f];
	    if ( !visited[ni][nj] ) continue;
	    if ( P[pi][pj].E[f] && P[ni][nj].E[(f+2)%4] ) possible = true;

	}
	if ( !possible ) continue;
	int t = 0;
	rep(f, 4){
	    ni = pi + di[f];
	    nj = pj + dj[f];
	    if ( visited[ni][nj] ) continue;
	    if ( P[pi][pj].E[f] ) {
		visited[pi][pj] = true;
		t++;
		dfs(ni, nj);
		visited[pi][pj] = false;
	    }
	}
	//	assert( t== 1);
    }

    
}

int compute(){
    cnt = 0;
    rep(i, H+2) rep(j, W+2){
	visited[i][j] = false;
	P[i][j].setParam();
    }
    visited[0][1] = visited[1][0] = true;
    P[0][1].E[3] = true;
    P[1][0].E[0] = true;
    dfs(1, 1);
    return cnt;
}

main(){
    string line;
    int tcase; cin >> tcase;
    char G[MAX*4][MAX*4];
   
    rep(t, tcase){
	cin >> H >> W;
	getline(cin, line);
	rep(i, H*4+1) {
	    getline(cin, line);
	    rep(j, line.size())  G[i][j] = line[j];
	}
	
	int i = 2, j = 2;
	rep(a, H+2) rep(b, W+2) P[a][b] = Piece();
	rep(a, H) {
	    j = 2;
	    rep(b, W){
		rep(r, 4) {
		    int ni = i + di[r];
		    int nj = j + dj[r];
		    P[a+1][b+1].E[r] = (G[ni][nj]=='*')?1:0;
		}
		j += 4;
	    }
	    i += 4;
	}
	/*
	for ( int i = 1; i <= H; i++ ){
	    for ( int j = 1; j <= W; j++ ){
		cout << P[i][j].getValue() << " ";
	    }
	    cout << endl;
	}
	*/

	cout << "Number of solutions: " << compute() << endl;
    }
}
