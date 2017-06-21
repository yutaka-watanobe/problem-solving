#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 10
#define LIMIT 30

char G[MAX+2][MAX+2];

int H, W;
int C[MAX+2][MAX+2][MAX+2][MAX+2];
int ntarget;
int limit;

vector<pair<int, int> > targets;

static const int di[4] = {0, -1, 0, 1};
static const int dj[4] = {1, 0, -1, 0};

bool isAdj( int i, int j, int from ){
    for ( int r = 0; r < 4; r++ ){
	if ( r == from ) continue;
	if ( G[i + di[r]][j + dj[r]] == 'W' ||
	     G[i + di[r]][j + dj[r]] == 'P' ) return true;
    }
    return false;
}

int bfs( int si, int sj, int gi, int gj ){
    queue<pair<int, int> > Q;
    static int INFTY = 1000;
    int D[MAX+2][MAX+2];
    for ( int i = 1; i <= H; i++ )
	for ( int j = 1; j <= W; j++ ) D[i][j] = INFTY;

    D[si][sj] = 0;
    Q.push(make_pair(si, sj));
    pair<int, int> u;

    while(!Q.empty()){
	u = Q.front(); Q.pop();
	if ( u.first == gi && u.second == gj ) return D[u.first][u.second];
	int ni, nj;
	for ( int r = 0; r < 4; r++ ){
	    ni = u.first + di[r];
	    nj = u.second + dj[r];
	    if ( G[ni][nj] == '#' || G[ni][nj] == 'W' ) continue;
	    if ( D[ni][nj] != INFTY ) continue;
	    D[ni][nj] = D[u.first][u.second] + 1;
	    Q.push(make_pair(ni, nj));
	}
    }
    return INFTY;
}

int getMD(vector<pair<int, int> > P){

    int md = 0;
    for ( int i = 0; i < targets.size() ;i++ ){
	pair<int, int> t = targets[i];
	if ( G[t.first][t.second] == 'W' ) continue;
	int mind = 10000;;

	for ( int j = 0; j < targets.size(); j++ ){
	    if ( i == j ) continue;
	    mind = min(mind, C[t.first][t.second][targets[j].first][targets[j].second] );
	}

	for ( int j = 0; j < P.size(); j++ ){
	    mind = min(mind, bfs(t.first, t.second, P[j].first, P[j].second));
	}

	md += mind;
    }
    return md;
}

bool dfs( int depth, int nget, vector<pair<int, int> > P ){
    if ( nget == ntarget ) return true;
    if ( depth + getMD(P) >= limit ) return false;

    vector<pair<int, int> > next;

    int ni, nj;

    for ( int i = 0; i < P.size(); i++ ){
	next = P;
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

void compute(vector<pair<int, int> > P){
 
    for ( int i = 0; i < targets.size()-1; i++ ){
	for ( int j = i+1; j < targets.size(); j++ ){
	    pair<int, int> s = targets[i];
	    pair<int, int> t = targets[j];
	    
	    C[s.first][s.second][t.first][t.second] = C[t.first][t.second][s.first][s.second] = bfs( s.first, s.second, t.first, t.second);
	}
    }

    int md = getMD(P);
    cout << "md = " << md << endl;


    for ( limit = md; limit < LIMIT; limit++ ){
	//	cout << "try " << limit << endl;
	if ( dfs(0, 0, P) ) {
	    for ( int i = 1; i <= H; i++ ){
		for ( int j = 1; j <= W; j++ ){
		    cout << G[i][j];
		}
		cout << endl;
	    }

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
	vector<pair<int, int> > P;
	targets.clear();
	for ( int i = 1; i <= H; i++ ){
	    for ( int j = 1; j <= W; j++ ){
		cin >> G[i][j];
		if ( G[i][j] == 'P' ) P.push_back(make_pair(i, j));
		else if ( G[i][j] == '*' ) {
		    ntarget++;
		    targets.push_back(make_pair(i, j));
		}
	    }
	}
	compute(P);
    }
    return 0;
}
