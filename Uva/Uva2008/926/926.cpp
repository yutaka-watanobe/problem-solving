#include<iostream>
using namespace std;
#define MAX 30

int dir(char ch){
    if ( ch == 'E' ) return 0;
    else if ( ch == 'N' ) return 1;
    else if ( ch == 'W' ) return 2;
    else return 3;
}

int oposite( int x ){
    return (x+2)%4;
}


void compute(){
    int N, sx, sy, tx, ty;
    cin >> N >> sx >> sy >> tx >> ty;
    bool B[MAX+1][MAX+1][4];
    unsigned long long T[MAX+1][MAX+1];
    for ( int x = 1; x <= N; x++ ){
	for ( int y = 1; y <= N; y++ ){
	    for ( int d = 0; d < 4; d++ ) B[x][y][d] = false;
	    T[x][y] = 0;
	}
    }
    int m, y, x, ny, nx;  cin >> m;
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};

    char ch;
    for ( int i = 0; i < m; i++ ){
	cin >> x >> y >> ch;
	int tmp = dir(ch);
	B[x][y][tmp] = true;
	nx = x + dx[tmp];
	ny = y + dy[tmp];
	if ( ny >= 1 && nx >= 1 && ny <= N && nx <= N ){
	    B[nx][ny][oposite(tmp)] = true;
	}
    }

    T[sx][sy] = 1;
    for ( int x = sx; x <= N; x++ ){
	for ( int y = sy; y <= N; y++ ){
	    if ( y > sy && !B[x][y][3] ) T[x][y] += T[x][y-1];
	    if ( x > sx && !B[x][y][2] ) T[x][y] += T[x-1][y];
	}
    }

    cout << T[tx][ty]  << endl;
}

int main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ) compute();
    return 0;
}
