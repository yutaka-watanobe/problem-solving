#include<iostream>
using namespace std; 
#define N 9
#define rep(i, n) for ( int i = 0; i < n; i++)
#define NE 0
#define NW 1
#define SW 2
#define SE 3
#define VERTICAL 0
#define HORIZON 1
static const int dx[4] = {1, -1, -1, 1};
static const int dy[4] = {1, 1, -1, -1};
bool M[N][N][N][N];
int n;

void move( int &x, int &y, int &dir, int vh ){
    if ( vh == VERTICAL ){
	if ( dir == 0 ) dir = 1;
	else if ( dir == 1 ) dir = 0;
	else if ( dir == 2 ) dir = 3;
	else if ( dir == 3 ) dir = 2;
    } else {
	if ( dir == 0 ) dir = 3;
	else if ( dir == 1 ) dir = 2;
	else if ( dir == 2 ) dir = 1;
	else if ( dir == 3 ) dir = 0;
    }
    x += dx[dir];
    y += dy[dir];
}

void simulate(){
    int x = 2, y = 1, dir = NE;
    while(1){
	if ( x % 2 == 0 && M[x/2][(y-1)/2][x/2][(y+1)/2]){ // vertical mirror
	    move(x, y, dir, VERTICAL);
	} else if ( y % 2 == 0 && M[(x-1)/2][y/2][(x+1)/2][y/2]){
	    move(x, y, dir, HORIZON);
	} else {
	    if ( x == 0 || y == 0 || x == 16 || y == 16 ){
		cout << x*50 << " " << y*50 << endl;
		return;
	    }
	    x += dx[dir];
	    y += dy[dir];
	}
	
	if ( x == 2 && y == 1 && dir == NE ){
	    cout << 75 << " " << 25 << endl; return;
	}
	
    }
}

main(){
    char ch;
    int x, y;
    while(1){
	cin >> n;
	if ( n < 0 ) break;
	rep(i, N) rep(j, N) rep(k, N) rep(l, N) M[i][j][k][l] = false;
	rep(i, n){
	    cin >> ch >> x >> y;
	    if ( ch == 'x' ) M[x][y][x+1][y] = M[x+1][y][x][y] = true;
	    else M[x][y][x][y+1] = M[x][y+1][x][y] = true;
	}
	simulate();
    }
}
