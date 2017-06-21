#include<iostream>
#include<queue>
using namespace std;
#define MAX 10
#define PMAX 10
#define TMAX 10
#define LIMIT 25

char G[MAX+2][MAX+2];
char in[MAX+2][MAX+2];
bool T[MAX+2][MAX+2];
int H, W;

int ntarget;
int limit;
int np;

struct Pair{
  int first, second;
};

struct Point{
  int first, second, from;
};

//pair<int, int> targets[TMAX];
Pair targets[TMAX];

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

bool missed(){
    for ( int i = 0; i < ntarget; i++ ){
	//pair<int, int> t = targets[i];
	Pair t = targets[i];
	if ( G[t.first][t.second] == '*' ){
	    for ( int r = 0; r < 4; r++ ){
		if ( T[t.first + di[r]][t.second + dj[r]] ) continue;
		if ( G[t.first + di[r]][t.second + dj[r]] == 'W' ) return true;
	    }
	}
    }
    return false;
}

bool isWP( int i, int j ){
    if ( in[i][j] == '*' ) return false;
    return (G[i][j] == 'W' || G[i][j] == 'P');
}
bool isWP( char ch){
    return (ch == 'W' || ch == 'P');
}
bool isSB( char ch ){
    return (ch == '.' || ch == '#');
}

bool isS( char ch ) {
    return ch == '.';
}

//int getMD(pair<int, int> P[]){
int getMD(Point P[]){
    int md = 10000;
    for ( int i = 0; i < ntarget ;i++ ){
	//pair<int, int> t = targets[i];
	Pair t = targets[i];
	if ( G[t.first][t.second] == 'W' ) continue;
	int mind = 10000;;

	for ( int j = 0; j < np; j++ ){
	    int d = max(t.first, P[j].first)-min(t.first, P[j].first) + max(t.second, P[j].second)-min(t.second, P[j].second);
	    mind = min(mind, d);
	}
	md = min(md, mind);
    }
    return md;
}

int bfs( int si, int sj ){
    queue<Point> Q;
    static const int INFTY = 1000;
    int d[MAX+2][MAX+2];
    for ( int i = 1; i <= H; i++ )
	for ( int j = 1; j <= W; j++ ) d[i][j] = INFTY;
    Point s; s.first = si; s.second = sj;
    Q.push(s);
    d[si][sj] = 0;
    Point u;
    while(!Q.empty()){
	u = Q.front(); Q.pop();
	if ( G[u.first][u.second] == '*' ) return d[u.first][u.second];

	int ni, nj;
	for ( int r = 0; r < 4; r++ ){
	    ni = u.first + di[r];
	    nj = u.second + dj[r];
	    if ( (G[ni][nj] == '.' || G[ni][nj] == '*' ) && d[ni][nj] == INFTY ){
		d[ni][nj] = d[u.first][u.second] + 1;
		Point v; v.first = ni; v.second = nj;
		Q.push(v);
	    }
	}
    }
    return INFTY;
}

int getMDBFS( Point P[] ){
    int md = 0;
    for ( int i = 0; i < np; i++ ){
	Point p = P[i];
	if ( in[p.first][p.second]  == '*' ) continue;
	if ( in[p.first][p.second]  == 'P' ) continue;
	if ( !(G[p.first][p.second] == 'W' && in[p.first][p.second] =='.'))continue;

	md += bfs(p.first, p.second);
    }
    return md;
}

int getMDB( Point P[] ){
    int md = 0;
    bool visited[TMAX];
    for ( int i = 0; i < ntarget; i++ ) visited[i] = false;

    for ( int i = 0; i < np; i++ ){
	Point p = P[i];
	if ( in[p.first][p.second]  == '*' ) continue;
	if ( in[p.first][p.second]  == 'P' ) continue;
	if ( !(G[p.first][p.second] == 'W' && in[p.first][p.second] =='.'))continue;
	int mind = 100;
	int mini = -1;
	for ( int j = 0; j < ntarget; j++ ){
	    Pair t = targets[j];
	    if ( G[t.first][t.second] == 'W' ) continue;
	    //mind = min(mind, (max(p.first, t.first)-min(p.first, t.first)  + max(p.second, t.second)-min(p.second, t.second)));
	    int d= max(p.first, t.first)-min(p.first, t.first)  + max(p.second, t.second)-min(p.second, t.second);
	    if ( mind > d ){
	      mind = d;
	      mini = j;
	    }
	}
	if ( mini >= 0 ) visited[mini] = true;
	md += mind;
    }
    for ( int i = 0; i < ntarget; i++ ) if ( !visited[i] && G[targets[i].first][targets[i].second] == '*') md++;
    return md;
}

/*
bool isEmpty( int i, int j){
    if ( G[i][j] == 'P' ) return false;
    if ( isWP(i, j+1) ){
	if ( isWP(i-1, j+1) && isWP(i-2,j+1) && isWP(i-2,j) && isS(G[i-1][j]) && isSB(G[i-1][j-1]) ) return true;
	if ( isWP(i+1,j+1) && isWP(i+2,j+1) && isWP(i+2,j) && isS(G[i+1][j]) && isSB(G[i+1][j-1]) ) return true;
    } else if ( isWP(i,j-1) ) {
	if ( isWP(i-1,j-1) && isWP(i-2,j-1) && isWP(i-2,j) && isS(G[i-1][j]) && isSB(G[i-1][j+1]) ) return true;
	if ( isWP(i+1,j-1) && isWP(i+2,j-1) && isWP(i+2,j) && isS(G[i+1][j]) && isSB(G[i+1][j+1]) ) return true;
    } else if ( isWP(i-1,j) ) {
	if ( isWP(i-1,j+1) && isWP(i-1,j+2) && isWP(i,j+2) && isS(G[i][j+1]) && isSB(G[i+1][j+1]) ) return true;
	if ( isWP(i-1,j-1) && isWP(i-1,j-2) && isWP(i,j-2) && isS(G[i][j-1]) && isSB(G[i+1][j-1]) ) return true;
    } else if ( isWP(i+1,j) ){
	if ( isWP(i+1,j+1) && isWP(i+1,j+2) && isWP(i,j+2) && isS(G[i][j+1]) && isSB(G[i-1][j+1]) ) return true;
	if ( isWP(i+1,j-1) && isWP(i+1,j-2) && isWP(i,j-2) && isS(G[i][j-1]) && isSB(G[i-1][j-1]) ) return true;
    } else {
	//	assert(false);
    }
    return false;
    }*/

bool isSW( int i, int j ){
    return G[i][j] == 'W' && in[i][j] == '.';
}

bool isEmpty( int i, int j ){
    if ( G[i][j] == 'P' ) return false;
    assert( G[i][j] == 'W' );
    if ( isWP(G[i-2][j]) && isSW(i, j+1) && isSW(i-1, j+1) && isSW(i-2, j+1) && G[i-1][j] == '.' && isSB(G[i-1][j-1])) return true;
    if ( isWP(G[i-2][j]) && isSW(i, j-1) && isSW(i-1, j-1) && isSW(i-2, j-1) && G[i-1][j] == '.' && isSB(G[i-1][j+1])) return true;
    if ( isWP(G[i+2][j]) && isSW(i, j+1) && isSW(i+1, j+1) && isSW(i+2, j+1) && G[i+1][j] == '.' && isSB(G[i+1][j-1])) return true;
    if ( isWP(G[i+2][j]) && isSW(i, j-1) && isSW(i+1, j-1) && isSW(i+2, j-1) && G[i+1][j] == '.' && isSB(G[i+1][j+1])) return true;
    return false;
}

//bool dfs( int depth, int nget, pair<int, int> P[] ){
bool dfs( int depth, int nget, Point P[] ){
    // print();
    if ( nget == ntarget ) return true;
    if ( depth + (ntarget-nget) > limit ) return false;
    //    if ( missed() ) return false;
    //    if ( depth + (ntarget-nget) + getMD(P)-1 > limit ) return false;
    if ( depth + getMDB(P) > limit ) return false;
    //        if ( depth + getMDBFS(P) > limit ) return false;
    //pair<int, int> next[PMAX];
    Point next[PMAX];

    int ni, nj;

    for ( int i = 0; i < np; i++ ){
	// 今いるところが空白でただ１つの選択しがなければそこへ進む
	// 空白であるということは、道がつづかなければならない、でなければそれは無駄になるから

      //	if ( isEmpty(P[i].first, P[i].second) ) return false;
	//	if ( isEmpty(P[i].first, P[i].second) ){
	//	    return false;
	//	}
	for ( int p = 0; p < np; p++ ) next[p] = P[p];

	int cnt = 0;
	int nr;
	for ( int r = 0; r < 4; r++ ){
	    ni = P[i].first + di[r];
	    nj = P[i].second + dj[r];
	    if ( G[ni][nj] == '*' ){
		char tmp = G[ni][nj];
		//next[i] = make_pair(ni, nj);
		next[i].from = (r+2)%4;
		next[i].first = ni;
		next[i].second = nj;
		G[ni][nj] = 'W';
		T[ni][nj] = true;
		T[P[i].first][P[i].second] = false;
		int earn = 1;
		if ( dfs(depth+1, nget+earn, next) ) return true;

		G[ni][nj] = tmp;
		T[ni][nj] = false;
		T[P[i].first][P[i].second] = true;
		return false;
		goto next;
	    }
	    if ( G[ni][nj] == '.' ) { cnt++; nr = r; }
	}

	if ( in[P[i].first][P[i].second] == '.' && cnt == 1 ){
	    ni = P[i].first + di[nr];
	    nj = P[i].second + dj[nr];
	    char tmp = G[ni][nj];
	    next[i].from = (nr+2)%4;
	    next[i].first = ni;
	    next[i].second = nj;
	    G[ni][nj] = 'W';
	    T[ni][nj] = true;
	    T[P[i].first][P[i].second] = false;
	    int earn = 0;
	    if ( dfs(depth+1, nget+earn, next) ) return true;
	    G[ni][nj] = tmp;
	    T[ni][nj] = false;
	    T[P[i].first][P[i].second] = true;
	    return false;
	    goto next;
	}

	for ( int r = 0; r < 4; r++ ){
	    ni = P[i].first + di[r];
	    nj = P[i].second + dj[r];

	    if ( G[ni][nj] == '#' || G[ni][nj] == 'P' || G[ni][nj] == 'W') continue;
	    //if ( r != P[i].from && G[ni][nj] == 'W' )  continue;
	    if ( isAdj(ni, nj, (r+2)%4) ) continue;

	    char tmp = G[ni][nj];
	    //next[i] = make_pair(ni, nj);
	    next[i].first = ni;
	    next[i].second = nj;
	    G[ni][nj] = 'W';
	    T[ni][nj] = true;
	    T[P[i].first][P[i].second] = false;
	    assert( tmp != '*' );
	    int earn = 0;
	    if ( dfs(depth+1, nget+earn, next) ) return true;
	    G[ni][nj] = tmp;
	    T[ni][nj] = false;
	    T[P[i].first][P[i].second] = true;
	}

	if ( in[P[i].first][P[i].second] == '.' ) return false;
    next:;


    }

    return false;
}

//void compute(pair<int, int> P[]){
void compute(Point P[]){
    for ( int i = 0; i < H+2; i++ )
	for ( int j = 0; j < W+2; j++ ) T[i][j] = false;

    for ( int i = 0; i  < np; i++ ) T[P[i].first][P[i].second] = true;

    for ( limit = ntarget; limit < LIMIT; limit++ ){
      //	            		cout << "try " << limit << endl;
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
	//pair<int, int> P[PMAX];
	Point P[PMAX];
	np = 0;
	for ( int i = 1; i <= H; i++ ){
	    for ( int j = 1; j <= W; j++ ){
		cin >> G[i][j];
		in[i][j] = G[i][j];
		if ( G[i][j] == 'P' ) {
		    P[np].from = -1;
		    P[np].first = i;
		    P[np++].second = j;
		} else if ( G[i][j] == '*' ) {
		    targets[ntarget].first = i;
		    targets[ntarget++].second = j;
		}
	    }
	}
	compute(P);
    }
    return 0;
}
