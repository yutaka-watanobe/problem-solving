#include<iostream>
using namespace std;

#define GMAX 20
#define SMAX 400
#define TMAX 100
#define INFTY (1<<21)

int N, M, D, sy, sx, gy, gx;
int G[GMAX][GMAX][GMAX][GMAX], S[GMAX][GMAX];
bool V[GMAX][GMAX][TMAX+1][4];

static const int dy[4] = {0, -1, 0, 1};
static const int dx[4] = {1, 0, -1, 0};

bool valid( int y , int x ){
    return ( 0 <= y && 0 <= x && y < N && x < M );
}

void dfs( int y, int x, int t, int d ){
    V[y][x][t][d] = true;

    int ny, nx, nt;
    for ( int nd = 0; nd < 4; nd++ ){
	if ( (d+2)%4 == nd ) continue;

	ny = y + dy[nd];
	nx = x + dx[nd];

	if ( !valid(ny, nx) ) continue;
	if ( G[y][x][ny][nx] == INFTY ) continue;

	nt = t + G[y][x][ny][nx];

	if ( nt > TMAX ) continue;

	if ( S[ny][nx] > 0 ){
	    if ( nd % 2 == 0 ){
		if ( (nt/S[ny][nx])%2 != 1 ) continue;
	    } else {
		if ( (nt/S[ny][nx])%2 != 0 ) continue;
	    }
	}

	if ( V[ny][nx][nt][nd] ) continue;

	dfs( ny, nx, nt, nd );
    }
}

int compute(){
    for ( int y = 0; y < N; y++ ){
	for ( int x = 0; x < M; x++ ){
	    for ( int t = 0; t <= TMAX; t++ ){
		for ( int d = 0; d < 4; d++ ) {
		    V[y][x][t][d] = false;
		}
	    }
	}
    }

    for ( int d = 0; d < 4; d++ ) dfs( sy, sx, 0, d );
    
    for ( int t = 0; t <= TMAX; t++ ){
	for ( int d = 0; d < 4; d++ ){
	    if ( V[gy][gx][t][d] ) return t;
	}
    }
}

int getNumber( char ch ){ return ch - 'a';}

bool input(){
    cin >> N >> M;
    if ( N == 0 && M == 0 ) return false;
    cin >> D;

    int ny, nx;
    for ( int y = 0; y < N; y++ ){
	for ( int x = 0; x < M; x++ ){
	    S[y][x] = 0;
	    for ( int nd = 0; nd < 4; nd++ ){
		ny = y + dy[nd];
		nx = x + dx[nd];
		if ( valid(ny, nx) ){
		    G[y][x][ny][nx] = G[ny][nx][y][x] = D;
		}
	    }
	}
    }

    int nsignal, nconst, njam, y1, x1, y2, x2, k, d; 
    char ch, tmp;

    cin >> nsignal;
    for ( int i = 0; i < nsignal; i++ ){
	cin >> ch  >> tmp >> x1 >> k; x1--;
	S[getNumber(ch)][x1] = k;
    }

    cin >> nconst;
    for ( int i = 0; i < nconst; i++ ){
	cin >> ch >> tmp >> x1; x1--;
	y1 = getNumber(ch);
	cin >> ch >> tmp >> x2; x2--;
	y2 = getNumber(ch);
	G[y1][x1][y2][x2] = G[y2][x2][y1][x1] = INFTY;
    }
    
    cin >> njam;
    for ( int i = 0; i < njam; i++ ){
	cin >> ch >> tmp >> x1; x1--;
	y1 = getNumber(ch);
	cin >> ch >> tmp >> x2 >> d; x2--;
	y2 = getNumber(ch);
	G[y1][x1][y2][x2] += d;
	G[y2][x2][y1][x1] += d;
    }

    cin >> ch >> tmp >> sx; sy = getNumber(ch);
    cin >> ch >> tmp >> gx; gy = getNumber(ch);
    sx--; gx--;
    return true;
}

main(){
    while( input() ) cout << compute() << endl;
}
