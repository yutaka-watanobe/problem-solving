#include<iostream>
#include<stdio.h>
#include<set>
#include<algorithm>
#include<map>
#include<cmath>
#include<queue>
typedef unsigned long long ullong;

using namespace std;
#define MAX 100000

struct Point{
    int x, y, r;
    bool operator < ( const Point &p ) const{
	if ( x == p.x ) return y < p.y;
	return x < p.x;
    }
};

struct State{
    Point p; 
    int dist;
};

//map<Point, bool> visited;
//map<Point, int> rem;
set<Point> rem;
int ans;
int cnt;

void bfs( int sx, int sy, int k ){
    State u, nex;
    u.p.x = sx;
    u.p.y = sy;
    u.dist = 0;

    // queue<State> Q;
    State Q[MAX];
    int head, tail;
    head = tail = 0;

    //Q.push(u);
    Q[tail] = u; tail++;
    
    //if ( rem[u.p] == 0 ) ans++;
    set<Point>::iterator it;

    /*
    it = rem.find(u.p);
    if ( it == rem.end() ) ans++;
    else if ( (*it).r < k ){
	rem.erase(it);
	u.p.r = k;
	rem.insert(u.p);
    } else return;
    */
    //   if ( !visited[u.p] ){
    //      visited[u.p] = true;
    //      ans++;
    //    }
    //    if ( rem[u.p] < k ){
    //      rem[u.p] = k;
    //    } else return;

    static const int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    static const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    

    //    while( !Q.empty() ){
    while( head != tail ){

	//u = Q.front(); Q.pop();
	u = Q[head++];
	//	if ( head + 1 == MAX ) head = 0;
	//	else head++;

	//	if ( u.dist >= k ) return;

	int nx, ny;
	for ( int r = 0; r < 8; r++ ){
	    //	cnt++;
	    nx = u.p.x + dx[r];
	    ny = u.p.y + dy[r];
	    nex.p.x = nx;
	    nex.p.y = ny;
	    //	    int r = rem[nex.p];

	    //it = find( rem.begin(), rem.end(), nex.p );
	    it = rem.find(nex.p);
	    if ( it == rem.end() || (*it).r < k - u.dist ){
		nex.p.r = k - u.dist;
		if ( it == rem.end() ) {
		    ans++;
		    rem.insert(nex.p);
		} else {
		    rem.erase(it);
		    rem.insert(nex.p);
		}

		//rem[nex.p] = k - u.dist;
		nex.dist = u.dist + 1;
		//Q.push(nex);
		if ( nex.dist < k ) Q[tail++] = nex;
		//		if ( tail + 1 == MAX ) tail = 0;
		//		else tail++;
		
		//				if ( !visited[nex.p] ){
		//				    visited[nex.p] = true;
		//				    ans++;
		//				}
	    } 
	}

    }
}

struct In{
    int x, y, k;
    bool operator < ( const In &i ) const{
	return k > i.k;
    }
};

int n;
void compute(){
    ans = 0;
    cnt = 0;
    int x, y, k;
    In in[30];

    //    for ( int i = 0; i < n; i++ ){
    //	scanf("%d %d %d", &x, &y, &k);
    //	bfs(x, y, k);
    //    }

    for ( int i = 0; i < n; i++ ){
	scanf("%d %d %d", &in[i].x, &in[i].y, &in[i].k);
    }
    //            sort( in, in + n);
    for ( int i = 0; i < n; i++ ){
	bfs( in[i].x, in[i].y, in[i].k );
    }

    //    cout << cnt << endl;
    printf("%d\n", ans);
}

int main(){
    while ( cin >> n && n ){
      //visited = map<Point, bool>();
	//rem = map<Point, int>();
	rem = set<Point>();
	compute();
    }
}
