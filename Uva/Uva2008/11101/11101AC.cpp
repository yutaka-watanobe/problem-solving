#include<stdio.h>
#include<queue>
#include<vector>
#include<cassert>
#include<iostream>
using namespace std;
#define MAX 2000
typedef unsigned short ushort;
static const int INFTY = (1<<21);
int maxx, maxy;
ushort M[MAX][MAX];

void plot( int x1, int y1, int x2, int y2, int mole, queue<pair<int, int> > &Q){
    if ( x1 == x2 ){
	for ( int y = min(y1, y2); y <= max(y1, y2); y++ ){
	    M[y][x1] = mole;
	    if ( mole == 1 ) Q.push(make_pair(x1, y));
	}
    } else if (y1 == y2 ){
	for ( int x = min(x1, x2); x <= max(x1, x2); x++ ){
	    M[y1][x] = mole;
	    if ( mole == 1 ) Q.push(make_pair(x, y1));
	}
    } else {
	assert(false);
    }
}

int bfs( queue<pair<int, int> > Q ){
    static const int dy[4] = {0, 1, 0, -1};
    static const int dx[4] = {1, 0, -1, 0};
    ushort D[MAX][MAX];
    for ( int y = 0; y <= maxy; y++ )
	for (int x = 0; x <= maxx; x++ ) D[y][x] = INFTY;

    queue<pair<int, int> > TQ = Q;
    while( !TQ.empty() ){
	pair<int, int> p = TQ.front(); TQ.pop();
	D[p.second][p.first] = 0;
    }

    int nx, ny;
    pair<int, int> u;
    while(!Q.empty()){
	u = Q.front(); Q.pop();
	if ( M[u.second][u.first] == 2 ) return D[u.second][u.first];
	for ( int d = 0; d < 4; d++ ){
	    nx = u.first + dx[d];
	    ny = u.second + dy[d];
	    if ( nx < 0 || ny < 0 || maxx < nx || maxy < ny ) continue;
	    if ( M[ny][nx] == 2 ) return D[u.second][u.first]+1;
	    if ( M[ny][nx] == 0 ){
		M[ny][nx] = 1;
		D[ny][nx] = D[u.second][u.first]+1;
		Q.push(make_pair(nx, ny));
	    }
	}
    }

}

int main(){
    int m1, m2, x, y;

    while( scanf("%d", &m1) && m1 ){
	vector<pair<int, int> > M1, M2;
	maxx = maxy = 0;
	for ( int i = 0; i < m1; i++ ){
	    scanf("%d %d", &x, &y);
	    M1.push_back(make_pair(x, y));
	    maxx = max(maxx, x);
	    maxy = max(maxy, y);
	}
	scanf("%d", &m2);
	for ( int i = 0; i < m2; i++ ){
	    scanf("%d %d", &x, &y);
	    M2.push_back(make_pair(x, y));
	    maxx = max(maxx, x);
	    maxy = max(maxy, y);
	}

	for ( int y = 0; y <= maxy; y++ )
	    for ( int x = 0;  x <= maxx; x++ ) M[y][x] = 0;

	queue<pair<int, int> > Q;

	for ( int i = 0; i < M1.size(); i++ ){
	    plot(M1[i].first, M1[i].second, M1[(i+1)%M1.size()].first, M1[(i+1)%M1.size()].second, 1, Q);
	}

	for ( int i = 0; i < M2.size(); i++ ){
	    plot(M2[i].first, M2[i].second, M2[(i+1)%M2.size()].first, M2[(i+1)%M2.size()].second, 2, Q);
	}

	printf("%d\n", bfs(Q));
    }

    return 0;
}
