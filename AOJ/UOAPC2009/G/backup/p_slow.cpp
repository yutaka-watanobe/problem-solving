#include<iostream>
#include<queue>
using namespace std;
#define MAX 10
#define PMAX 10
#define TMAX 10
#define LIMIT 25

char G[MAX+2][MAX+2];
int H, W;

int ntarget;
int limit;
int np;

pair<int, int> targets[TMAX];

static const int di[4] = {0, -1, 0, 1};
static const int dj[4] = {1, 0, -1, 0};

void print(){
  for ( int i = 1; i <= H; i++ ){
    for ( int j = 1; j <= W; j++ ){
      cout << G[i][j];
    }
    cout << endl;
  }
  cout << "---------" << endl;
}

bool isAdj( int i, int j, int from ){
    for ( int r = 0; r < 4; r++ ){
	if ( r == from ) continue;
	char ch = G[i + di[r]][j + dj[r]];
	if ( ch == 'W' || ch == 'P' ) return true;
    }
    return false;
}

int bfs( int si, int sj, bool T[MAX+2][MAX+2] ){

  //    queue<pair<int, int> > Q;
    pair<int, int> Q[101];
    int head, tail;
    head = tail = 0;

    static int INFTY = 1000;
    int D[MAX+2][MAX+2];
    for ( int i = 1; i <= H; i++ )
	for ( int j = 1; j <= W; j++ ) D[i][j] = INFTY;

    D[si][sj] = 0;
    //Q.push(make_pair(si, sj));
    Q[tail++] = make_pair(si, sj);
    pair<int, int> u;

    //    while(!Q.empty()){
    while( head != tail){
	//u = Q.front(); Q.pop();
	u = Q[head]; head++;
	if ( G[u.first][u.second] > limit ||
	     G[u.first][u.second] == '*' ||
	     G[u.first][u.second] == 'P' ||
	     T[u.first][u.second] ) return D[u.first][u.second];

	int ni, nj;
	for ( int r = 0; r < 4; r++ ){
	    ni = u.first + di[r];
	    nj = u.second + dj[r];
	    if ( G[ni][nj] == '#' || G[ni][nj] == 'W' ) continue;
	    if ( D[ni][nj] != INFTY ) continue;
	    D[ni][nj] = D[u.first][u.second] + 1;
	    //	    Q.push(make_pair(ni, nj));
	    Q[tail++] = make_pair(ni, nj);
	}
    }
    return INFTY;
}

int getMD(pair<int, int> P[]){
    bool T[MAX+2][MAX+2];
    for ( int i = 1; i <= H; i++ )
	for ( int j = 1; j <= W; j++ ) T[i][j] = false;
    for ( int i = 0; i < np; i++ ) T[P[i].first][P[i].second] = true;

    int md = 0;
    for ( int i = 0; i < ntarget ;i++ ){
	pair<int, int> t = targets[i];
	if ( G[t.first][t.second] == 'W' ) continue;
	md += bfs( t.first, t.second, T);
    }
    return md;
}

bool dfs( int depth, int nget, pair<int, int> P[] ){
  //  print();
    if ( nget == ntarget ) return true;
    //if ( depth + getMD(P) >= limit ) return false;
    if ( depth + (ntarget-nget) > limit ) return false;

    pair<int, int> next[PMAX];

    int ni, nj;

    for ( int i = 0; i < np; i++ ){
	for ( int p = 0; p < np; p++ ) next[p] = P[p];

	for ( int r = 0; r < 4; r++ ){
	    ni = P[i].first + di[r];
	    nj = P[i].second + dj[r];

	    if ( G[ni][nj] == '#' || G[ni][nj] == 'P' || G[ni][nj] == 'W') continue;
	    if ( isAdj(ni, nj, (r+2)%4) ) continue;
	    char tmp = G[ni][nj];
	    next[i] = make_pair(ni, nj);
	    G[ni][nj] = 'W';
	    int earn = (tmp == '*') ? 1 : 0;
	    if ( dfs(depth+1, nget+earn, next) ) return true;
	    G[ni][nj] = tmp;
	}
    }

    return false;
}

void compute(pair<int, int> P[]){
    for ( limit = ntarget; limit < LIMIT; limit++ ){
		cout << "try " << limit << endl;
	if ( dfs(0, 0, P) ) {
	    //	  print();
	    break;
	}
    }
    cout << limit << endl;
}

int main(){
    while( cin >> H >> W && H ){
	for ( int i = 0; i < H+2; i++ )
	    for ( int j = 0; j < W+2; j++ ) G[i][j] = '#';
	ntarget = 0;
	pair<int, int> P[PMAX];
	np = 0;
	for ( int i = 1; i <= H; i++ ){
	    for ( int j = 1; j <= W; j++ ){
		cin >> G[i][j];
		if ( G[i][j] == 'P' ) P[np++] = make_pair(i, j); 
		else if ( G[i][j] == '*' ) {
		    targets[ntarget++] = make_pair(i, j);
		}
	    }
	}
	compute(P);
    }
    return 0;
}
