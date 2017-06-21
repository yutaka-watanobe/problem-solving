#include<iostream>
#include<string>
#include<algorithm>
#define rep(i, n) for ( int i = 0; i < (int)n; i++ )
using namespace std;

#define WMAX 80
#define HMAX 1000

char G[HMAX][WMAX];

int vc, hc, h, pi, pj;
int cnt;

void dfs(int d[3], int ds ){
    static const int di[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    static const int dj[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    G[pi][pj] = ' ';
    int ni, nj;
    for ( int i = 0; i < ds; i++ ){
	int r = d[i];
	ni = pi + di[r];
	nj = pj + dj[r];
	if ( ni < 0 || nj < 0 || ni >= h || nj >= WMAX ) continue;
	if ( G[ni][nj] != '*' ) continue;
	cnt++;
	pi = ni;
	pj = nj;
	dfs(d, ds);
    }
}

void compute(){
    int d[3];
    int C[10000];
    for ( int i = 0; i < 10000; i++ ) C[i] = 0;
    rep(i, h) rep(j, WMAX){
	if ( G[i][j] == '*' ){
	    vc = hc = 0;
	    pi = i; pj = j; 

	    d[0] = 0; 
	    cnt = 0;
	    dfs(d, 1); // to east
	    hc += cnt;

	    d[0] = 7; d[1] = 6; d[2] = 5;
	    cnt = 0;
	    dfs(d, 3); // to south
	    vc += cnt;

	    d[0] = 4;
	    cnt = 0;
	    dfs(d, 1); // to west;
	    hc += cnt;

	    d[0] = 1; d[1] = 2; d[2] = 3;
	    cnt = 0;
	    dfs(d, 3); // to north;
	    vc += cnt;

	    C[(hc+2)* (vc+3)/4]++;
	}
    }

    for ( int i = 1; i < 10000; i++ ){
	if ( C[i] ) cout << i << " " << C[i] << endl;
    }
}

void input(){
    rep(i, h) rep(j, WMAX) G[i][j] = ' ';
    string line;
    getline( cin, line);
    rep(i, h){
	getline(cin, line);
	rep(j, line.size() ) G[i][j] = line[j];
    }
}

int main(){
    for ( int i = 0; ; i++ ){
	cin >> h;
	if ( h == 0 ) return 0;
	if (i) cout << "----------" << endl;
	input();
	compute();
    }
}
