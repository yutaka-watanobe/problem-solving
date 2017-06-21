#include<iostream>
#include<stdio.h>
#include<set>
#include<map>
using namespace std;

struct Point{
    int x, y;
    bool operator < ( const Point &p ) const{
	if ( x == p.x ) return y < p.y;
	return x < p.x;
    }
};


int n;
//map<Point, bool> visited;
map<Point, int> rem;
int ans;

void dfs( int x, int y, int k ){
    Point u, nex;
    u.x = x;
    u.y = y;

    if ( k <= 0 ) return;

    if ( rem[u] < k ){
	if ( rem[u] == 0 ) ans++;
	rem[u] = k;
    } else return;

    static const int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    static const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    
    int nx, ny;
    for ( int r = 0; r < 8; r++ ){
	nx = u.x + dx[r];
	ny = u.y + dy[r];
	nex.x = nx;
	nex.y = ny;
	if ( rem[nex] <= k-1 ){
	    dfs( nex.x, nex.y, k-1);
	}
    }
}

void compute(){
    ans = 0;
    int x, y, k;
    for ( int i = 0; i < n; i++ ){
	scanf("%d %d %d", &x, &y, &k);
	dfs(x, y, k+1);
    }
    printf("%d\n", ans);
}

int main(){
    while ( cin >> n && n ){
	//	visited = map<Point, bool>();
	rem = map<Point, int>();
	compute();
    }
}
