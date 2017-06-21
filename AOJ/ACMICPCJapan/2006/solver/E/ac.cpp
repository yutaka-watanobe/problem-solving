#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define INFTY (1<<15)
#define MAX 9
#define EMPTY '0'
#define OBSTACLE '1'

int N, M;
char G[MAX+2][MAX+2];
bool V[MAX+2][MAX+2];
pair<int, int> s2[2], s3[2];
int mincost;
const int di[4] = {0, -1, 0, 1};
const int dj[4] = {1, 0, -1, 0};

int ncut;


int op(int d){
    return (d+2)%4;
}

int bfs(){
    int D[MAX+2][MAX+2];
    queue<pair<int, int> > Q;

    for ( int i = 1; i <= N; i++ ){
	for ( int j = 1; j <= M; j++ ){
	    D[i][j] = INFTY;
	}
    }
    Q.push(make_pair(s3[0].first, s3[0].second));
    D[s3[0].first][s3[0].second] = 0;

    pair<int, int> u, v;
    int ni, nj;
    while(!Q.empty()){
	u = Q.front(); Q.pop();
	if ( G[u.first][u.second] == '3' && !(u.first == s3[0].first && u.second == s3[0].second)) return D[u.first][u.second];

	for ( int r = 0; r < 4; r++ ){
	    ni = u.first + di[r];
	    nj = u.second + dj[r];
	    if ( D[ni][nj] == INFTY && !V[ni][nj] && (G[ni][nj] == EMPTY || G[ni][nj] == '3')){
		D[ni][nj] = D[u.first][u.second] + 1;
		Q.push(make_pair(ni, nj));
	    }
	}
    }

    return INFTY;
}

int MD( int i , int j ){
    return max(i, s2[1].first) - min(i, s2[1].first ) +
	max(j, s2[1].second) - min(j, s2[1].second );

}

int getWidth( int i, int j, int d){
    int w = 0;
    while(1){
	if ( G[i][j] != EMPTY ) return -1;
	if ( V[i][j] ) return w;
	i += di[d]; j += dj[d];
	w++;
	//	if ( w > 3 ) return -1;
    }
}

bool is2seq( int i, int j, int d, int w ){
    for ( int s = 0; s < w; s++ ){
	if ( !V[i][j] ) return false;
	i += di[d]; j += dj[d];
    }
    return true;
}

bool isEseq( int i, int j, int d, int w ){
    for ( int s = 0; s < w; s++ ){
	if ( V[i][j] || G[i][j] != EMPTY ) return false;
	i += di[d]; j += dj[d];
    }
    return true;
}

bool cut(int i, int j){
    for ( int d = 0; d < 4; d++ ){
	int w = getWidth(i+di[d], j+dj[d], d);
	if ( w <= 0 ) continue;
	if ( w == 1 || w == 2 ){
	    if ( is2seq( i+di[(d+1)%4], j+dj[(d+1)%4], d, w+2 ) ||
		 is2seq( i+di[(d+3)%4], j+dj[(d+3)%4], d, w+2 ) ) return true;
	} else {
	    if ( is2seq( i+di[(d+1)%4], j+dj[(d+1)%4], d, w+2 ) &&
		 isEseq( i+di[(d+3)%4]*2, j+dj[(d+3)%4]*2, d, w ) ||		 
		 is2seq( i+di[(d+3)%4], j+dj[(d+3)%4], d, w+2 ) &&
		 isEseq( i+di[(d+1)%4]*2, j+dj[(d+1)%4]*2, d, w ) ) {
		return true;
	    }
	}
    }

    return false;
}



void dfs( int i, int j, int dist, int pre ){
    if ( G[i][j] == '2' ){
	mincost = min( mincost, dist + bfs() );
	return;
    }

    if ( dist + MD(i, j) > mincost ) return ;

    if ( pre != -1 ){
	for ( int r = 0; r < 4; r++ ){
	    if ( r == pre ) continue;
	    if ( V[i+di[r]][j+dj[r]] ) return;
	}
    }


    V[i][j] = true;

    if ( cut(i, j) ) {
	//	ncut++;
	return;
    }
    
    
    int ni, nj;
    for ( int d = 0; d < 4; d++ ){
	ni = i + di[d];
	nj = j + dj[d];
	if ( !V[ni][nj] && (G[ni][nj] == EMPTY || G[ni][nj] == '2') ){
	    dfs( ni, nj, dist + 1, op(d) );
	    V[ni][nj] = false;
	}
    }
}

void compute(){
    mincost = INFTY;
    for ( int i = 0; i < N+2; i++ ){
	for ( int j = 0; j < M+2; j++ ) V[i][j] = false;
    }
    G[s2[0].first][s2[0].second] = EMPTY;
    //    G[s3.first][s3.second] = EMPTY;

    ncut= 0;
    dfs( s2[0].first, s2[0].second, 0, -1 );
    if ( mincost >= INFTY ) cout << 0 << endl;
    else cout << mincost << endl;
    //        cout << "ncut = " << ncut << endl;
}

bool input(){
    cin >> N >> M;
    if ( N == 0 && M == 0 ) return false;
    for ( int i = 0; i < N+2; i++ ) G[i][0] = G[i][M+1] = OBSTACLE;
    for ( int j = 0; j < M+2; j++ ) G[0][j] = G[N+1][j] = OBSTACLE;

    int s2c, s3c;
    s2c = s3c = 0;
    for ( int i = 1; i <= N; i++ ){
	for ( int j = 1; j <= M; j++ ){
	    cin >> G[i][j];
	    if ( G[i][j] == '2' ) s2[s2c++] = make_pair(i, j);
	    if ( G[i][j] == '3' ) s3[s3c++] = make_pair(i, j);
	}
    }
    return true;
}

main(){
    while( input() ) compute();
}
