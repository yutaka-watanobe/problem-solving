#include<iostream>
#include<stdio.h>
#include<set>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
#define MAX 1000000

struct Point{
    int x, y;
    bool operator < ( const Point &p ) const{
	if ( x == p.x ) return y < p.y;
	return x < p.x;
    }
};

Point P[MAX];
int D[MAX];
int nex[MAX];

map<Point, bool> visited;
int ans;

void init(){
    Point u, nex;
    map<Point, bool> v;
    map<Point, int> d;
    u.x = 0;
    u.y = 0;
    int pos = 0;

    queue<Point> Q;
    Q.push(u);
    v[u] = true;
    d[u] = 0;

    static const int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    static const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    
    while( !Q.empty() ){
	u = Q.front(); Q.pop();
	P[pos] = u;
	D[pos] = d[u]; pos++;
	if ( d[u] > 50 ) break;

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


    cout << "size = " << pos << endl;
    return;
    for ( int i = 0; i < pos; i++ ){
	cout << P[i].x << " " << P[i].y << " " << D[i] << endl;
    }
}

int n;

void parse( int x, int y, int k ){
    Point p;

    int pos = 0;
    while(D[pos] <= k){
	p.x = x + P[pos].x;
	p.y = y + P[pos].y;
	
	if ( !visited[p] ){
	    visited[p] = true;
	    ans++;
	}
	
	pos++;
    }
}

void compute(){

    ans = 0;
    int x, y, k;
    visited = map<Point, bool>();

    for ( int i = 0; i < n; i++ ){
	scanf("%d %d %d", &x, &y, &k);
	parse(x, y, k);
    }
    printf("%d\n", ans);
}

int main(){
    init();
    while ( cin >> n && n ){
	compute();
    }
}
