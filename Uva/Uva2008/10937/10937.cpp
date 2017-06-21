#include<iostream>
#include<queue>
using namespace std;
#define MAX 50
#define TMAX 10
#define INFTY (1<<21)
static const char SPACE = ' ';
static const char OBSTACLE = 'X';

int h, w;
char M[MAX+2][MAX+2];
pair<int, int> T[TMAX+1]; // 0 = start
int ntreasure;
int D[TMAX+1][TMAX+1];
// for recursive
int least;
bool used[TMAX+1];

int bfs( pair<int, int>  s, pair<int, int> t ){
    if ( M[s.first][s.second] == OBSTACLE ) return INFTY;
    queue<pair<int, int> > Q;
    int d[MAX+2][MAX+2];

    for ( int i = 1; i <= h; i++ ){
	for ( int j = 1; j <=  w; j++ ){
	    d[i][j] = INFTY;
	}
    }

    Q.push(s);
    d[s.first][s.second] = 0;
    pair<int, int> u, v;

    while(!Q.empty()){
	u = Q.front(); Q.pop();
	if ( u == t ) return d[u.first][u.second];

	static const int di[4] = {0, -1, 0, 1};
	static const int dj[4] = {1, 0, -1, 0};

	for ( int r = 0; r < 4; r++ ){
	    int ni = u.first + di[r];
	    int nj = u.second + dj[r];
	    if ( M[ni][nj] == SPACE && d[ni][nj] == INFTY ){
		d[ni][nj] = d[u.first][u.second] + 1;
		Q.push(make_pair(ni,nj));
	    }
	}
    }

    return INFTY;
}

void recursive( int depth, int dist, int u ){
    if ( depth == ntreasure ){
	least = min( least, dist + D[u][0] );
	return;
    }

    if ( dist > least ) return;

    for ( int v = 0; v < ntreasure; v++ ){
	if ( used[v] ) continue;
	used[v] = true;
	recursive( depth+1, dist + D[u][v], v );
	used[v] = false;
    }
}

void compute(){
    for ( int i = 0; i < ntreasure; i++ ){
	for ( int j = 0; j < ntreasure; j++ ) D[i][j] = INFTY;
    }

    for ( int i = 0; i < ntreasure; i++ ){
	for ( int j = i; j < ntreasure; j++ ){
	    D[i][j] = D[j][i] = bfs(T[i], T[j]);
	}
    }


    least = INFTY;
    for ( int i = 0; i < ntreasure; i++ ) used[i] = false;
    used[0] = true;
    recursive( 1, 0, 0 );

    if ( least == INFTY ) cout << -1 << endl;
    else cout << least << endl;
}

bool input(){
    cin >> h >> w;
    if ( h == 0 && w == 0 ) return false;
    for ( int i = 0; i < h+2; i++ ) M[i][0] = M[i][w+1] = OBSTACLE;
    for ( int j = 0; j < w+2; j++ ) M[0][j] = M[h+1][j] = OBSTACLE;
    for ( int i = 1; i <= h; i++ ){
	for (int j = 1; j <= w; j++ ) M[i][j] = SPACE;
    }
    ntreasure = 1;
    char ch;
    for ( int i = 1; i <= h; i++ ){
	for ( int j = 1; j <= w; j++ ){
	    cin >> ch;
	    if ( ch == '.' ){
		if ( M[i][j] != OBSTACLE ) M[i][j] = SPACE;
	    } else if ( ch == '@' ){
		T[0] = make_pair(i, j);
		if ( M[i][j] != OBSTACLE ) M[i][j] = SPACE;
	    } else if ( ch == '!' ){
		T[ntreasure++] = make_pair(i, j);
		if ( M[i][j] != OBSTACLE ) M[i][j] = SPACE;
	    } else if ( ch == '*' ){
		static const int di[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
		static const int dj[9] = {0, 1, 1, 0, -1, -1, -1, 0, 1};
		for ( int d = 0; d < 9; d++ ){
		    M[i+di[d]][j+dj[d]] = OBSTACLE;
		}
	    } else M[i][j] = OBSTACLE;
	}
    }
    
    return true;
}

main(){
    while( input() ) compute();
}
