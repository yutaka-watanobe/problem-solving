#include<iostream>
#include<queue>
using namespace std;
#define MAX 200
#define INFTY (1 << 28 )
int M, N;
int G[MAX][MAX];
char in[MAX][MAX];
int si, sj, ti, tj;

int di[9] = {0, -1, -2, -2, -1, 1, 2, 2, 1};
int dj[9] = {0, 2, 1, -1, -2, -2, -1, 1, 2};

void input(){
    char ch;
    cin >> M >> N;

    for ( int i = 0; i < M; i++ ){
	for ( int j = 0; j < N; j++ ){
	    cin >> in[i][j];
	    G[i][j] = 0;
	}
    }
    
    for ( int i = 0; i < M; i++ ){
	for ( int j = 0; j < N; j++ ){
	    if ( in[i][j] == 'Z' ){
		for (  int d = 0; d < 9; d++ ){
		    int ni = i + di[d];
		    int nj = j + dj[d];
		    if ( 0 <= ni  && 0 <= nj && ni < M && nj < N ){
		      G[ni][nj] = 1;
		    }
		}
	    } else if ( in[i][j] == 'A' ) {
		si = i; sj = j;
	    } else if ( in[i][j] == 'B' ){
		ti = i; tj = j;
	    }
	}
    }

    G[si][sj] = 0;
    G[ti][tj] = 0;
}

int compute(){
    int d[MAX][MAX];
    for ( int i = 0; i < M; i++ ){
	for ( int j = 0; j < N; j++ ) d[i][j] = INFTY;
    }

    queue<pair<int, int> > Q;

    Q.push(make_pair(si, sj));
    d[si][sj] = 0;

    pair<int, int> u, v;

    int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

    while( !Q.empty() ){
	u = Q.front(); Q.pop();

	if ( u.first == ti && u.second == tj ) return d[ti][tj];

	int ni, nj;
	for ( int r = 0; r < 4; r++ ){
	    ni = u.first + dx[r];
	    nj = u.second + dy[r];
	    if ( 0 <= ni && 0 <= nj && ni < M && nj < N ){
		if ( G[ni][nj] == 0 && d[ni][nj] == INFTY ){
		    d[ni][nj] = d[u.first][u.second] + 1;
		    Q.push(make_pair( ni, nj));
		}
	    }
	}
    }
    return -1;
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	input();
	int cost  = compute();
	if ( cost == -1 ){
	    cout << "King Peter, you can't go now!" << endl;
	} else {
	    cout << "Minimal possible length of a trip is " << cost << endl;
	}
    }
}
