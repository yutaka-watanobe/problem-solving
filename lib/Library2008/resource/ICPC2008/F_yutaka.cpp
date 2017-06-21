#include<iostream>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
typedef set<int> Shape;
#define MAX 12
int W, H, C[MAX][MAX], ncell, sx, sy, tx, ty, sd, td, flip;
bool V[MAX][MAX];
map<Shape, bool> U;

void rotate( int &x, int &y ){
    if ( td == 1 ){ swap( x, y ); x *= (-1);}
    else if ( td == 2 ) { x *= (-1); y *= (-1);}
    else if ( td == 3 ) { swap( x, y ); y *= (-1);}
    x *= flip;
}
 
bool dfs( Shape shape ){
    if ( shape.size() == ncell ) return true;

    U[shape] = true;

    static const int dx[4] = {0, -1, 0, 1};
    static const int dy[4] = {1, 0, -1, 0};
    int nx, ny, tnx, tny, diffx, diffy;
    Shape nextS;

    for ( Shape::iterator it = shape.begin(); it != shape.end(); it++ ){
	for ( int d = 0; d < 4; d++ ){
	    nx = (*it)/W + dx[d];
	    ny = (*it)%W + dy[d];
	    if ( !C[nx][ny] || V[nx][ny] ) continue;
	    diffx = nx - sx;
	    diffy = ny - sy;
	    rotate( diffx, diffy );
	    tnx = tx + diffx;
	    tny = ty + diffy;
	    if ( nx == tnx && ny == tny ) continue;
	    if ( !C[tnx][tny] || V[tnx][tny] ) continue;
	    nextS = shape;
	    nextS.insert( nx*W + ny );
	    if ( U[nextS] ) continue;
	    V[nx][ny] = V[tnx][tny] = true;
	    if ( dfs( nextS ) ) return true;
	    V[nx][ny] = V[tnx][tny] = false;
	}
    }
    return false;
}

bool parse(){
    U = map<Shape, bool>();
    for ( int x = 1; x <= H; x++ ){
	for ( int y = 1; y <= W; y++ ) V[x][y] = 0;
    }
    Shape shape;
    shape.insert( sx*W + sy );
    U[shape] = true;
    V[sx][sy] = V[tx][ty] = true;
    return dfs( shape );
}

bool check(){
    if ( ncell % 2 != 0 || ncell < 2 ) return false;
    ncell /= 2;
    for ( tx = 1; tx <= H; tx++ ){
	for ( ty = 1; ty <= W; ty++ ){
	    if ( (tx == sx && ty == sy) || C[tx][ty] == 0) continue;
	    for ( td = 0; td < 4; td++ ){
		flip = 1;
		if ( parse() ) return true;
		flip = -1;
		if ( parse() ) return true;
	    }
	}
    }
    return false;
}

main(){
    while( cin >> W >> H && ( W && H ) ){
	ncell = 0;
	sx = sy = -1;
	for ( int x = 0; x < H + 2; x++ ){
	    for ( int y = 0; y < W + 2; y++ ){
		C[x][y] = 0;
		if ( 1 <= x && 1 <= y && x <= H && y <= W ) cin >> C[x][y];
		if ( C[x][y] ) ncell++;
		if ( C[x][y] && sx == -1 ){ sx = x; sy = y; }
	    }
	}
	if ( check() ) cout << "YES" << endl;
	else cout << "NO" << endl;
    }
}
