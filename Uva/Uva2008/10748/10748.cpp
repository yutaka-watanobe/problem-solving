#include<iostream>
#include<stdio.h>
#include<set>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
#define MAX 2000000

struct Point{
    int x, y;
    bool operator < ( const Point &p ) const{
	if ( x == p.x ) return y < p.y;
	return x < p.x;
    }
};

Point P[MAX];
int ans, size;

void bfs(int x, int y, int k){
    Point u, nex;
    map<Point, bool> v;
    map<Point, int> d;
    u.x = x;
    u.y = y;

    queue<Point> Q;
    Q.push(u);
    v[u] = true;
    d[u] = 0;

    static const int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    static const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    
    while( !Q.empty() ){
	u = Q.front(); Q.pop();
	P[size] = u; size++;
	if ( d[u] > k ) break;

	int nx, ny;
	for ( int r = 0; r < 8; r++ ){
	    nx = u.x + dx[r];
	    ny = u.y + dy[r];
	    nex.x = nx;
	    nex.y = ny;
	    if ( !v[nex] ){
		v[nex] = true;
		d[nex] = d[u] + 1;
		Q.push(nex);
	    } 
	}
    }
}

int n;

void compute(){

    ans = 0;
    int x, y, k;
    size = 0;

    for ( int i = 0; i < n; i++ ){
	scanf("%d %d %d", &x, &y, &k);
	bfs(x, y, k);
    }
    printf("pos %d\n", size);
}

int main(){
    while ( cin >> n && n ){
	compute();
    }
}
