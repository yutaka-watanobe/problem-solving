#include<iostream>
#include<queue>
using namespace std;
struct Point{int y, x;};
#define MAX 100

int G[MAX][MAX], W, H;

int bfs(){
    Point u, v;
    queue<Point> Q;
    int D[MAX][MAX], ny, nx;
    int dy[4] = {0, -1, 0, 1};
    int dx[4] = {1, 0, -1, 0};

    for ( int i = 0; i < H; i++ ){
	for ( int j = 0; j < W; j++ ) D[i][j] = INT_MAX;
    }

    u.y = u.x = 0;    
    D[u.y][u.x] = 1;
    Q.push(u);
    
    while(!Q.empty()){
	u = Q.front(); Q.pop();
	if ( u.y == H-1 && u.x == W-1 ) return D[u.y][u.x];
	for ( int r = 0; r < 4; r++ ){
	    nx = u.x + dx[r];
	    ny = u.y + dy[r];
	    if ( nx < 0 || ny < 0 || ny >= H || nx >= W ) continue;
	    if ( G[ny][nx] || D[ny][nx] != INT_MAX )	continue;
	    D[ny][nx] = D[u.y][u.x] + 1;
	    v.x = nx;
	    v.y = ny;
	    Q.push(v);
	}
    }
    
    return -1;
}

int main(){
    cin >> W >> H;
    for ( int i = 0; i < H; i++ ){
	for ( int j = 0; j < W; j++ ) cin >> G[i][j];
    }
    cout << bfs() << endl;
    
    return 0;
}
