#include<iostream>
#include<stdio.h>
#include<set>
#include<algorithm>
#include<map>
#include<cmath>
#include<queue>
typedef unsigned long long ullong;

// 7919  13127 
using namespace std;
#define MAX 100000
#define KEYMAX 1050011
//#define KEYMAX 1999993


//#define ADD 4027


//#define ADD 293
//#define ADD 4027
#define ADD 293
//#define ADD 19467
//#define ADD 999983
#define MIN -1000000001
#define SHIFT 1000000000
//#define MULX 19467
#define MULX 13127

#define MULY KEYMAX
//#define MULY 7919


struct Point{
    int x, y;
    bool operator < ( const Point &p ) const{
	if ( x == p.x ) return y < p.y;
	return x < p.x;
    }
};

struct State{
    Point p; 
    int dist;
};


Point H[KEYMAX];
int R[KEYMAX];

void init(){
    for ( int i = 0; i < KEYMAX; i++ ){
	H[i].x = MIN;
	R[i] = 0;
    }
}

int index( Point p ){
    long long x = (long long)p.x*MULX+ (long long)p.y%MULY;
    //    long long x = (long long)(p.x%KEYMAX)*MULX+ (long long)p.y%KEYMAX;
    if ( x < 0 ) x *= -1;
    int i = x%KEYMAX;


  /*
    long long px, py;
        if ( p.x < 0 ) px = (long long)(-1)*p.x;
    else px = (long long )p.x;
    if ( p.y < 0 ) py = (long long)(-1)*p.y;
    else py = (long long)p.y;


    //    long long x = ( (py << 19) | (px<<13) );
    //    long long x = ( py*MULX | px*MULY );
    //    long long x = (( px + py ))*MULX - py*MULY;
    long long x = px*MULX + py*MULY + px;
    int i = x%KEYMAX;
  */


    if ( H[i].x == MIN ){
	H[i] = p;
	return i;
    } else if ( H[i].x == p.x && H[i].y == p.y ){
	return i;
    } else {
      while(1){
	    if ( H[i].x == MIN ){
		H[i] = p;
		return i;
	    } else if ( H[i].x == p.x && H[i].y == p.y ){
		return i;
	    } else i = ((i+ADD))%KEYMAX;
      }
    }
}

int n;
//map<Point, bool> visited;
map<Point, int> rem;
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
    
    //    if ( !visited[u.p] ){
    //	visited[u.p] = true;
    //	ans++;
    //    }

    if ( R[index(u.p)] == 0 ) ans++;

    if ( R[index(u.p)] < k ){
	R[index(u.p)] = k;
    } else return;

    static const int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    static const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    

    //    while( !Q.empty() ){
    while( head != tail ){

	//u = Q.front(); Q.pop();
	u = Q[head++];
	//	if ( head + 1 == MAX ) head = 0;
	//	else head++;

	if ( u.dist >= k ) return;

	int nx, ny;
	for ( int r = 0; r < 8; r++ ){
	    //	cnt++;
	    nx = u.p.x + dx[r];
	    ny = u.p.y + dy[r];
	    nex.p.x = nx;
	    nex.p.y = ny;
	    int r = R[index(nex.p)];
	    if ( r < k - u.dist ){
		if ( r == 0 ) ans++;
		
		R[index(nex.p)] = k - u.dist;
		nex.dist = u.dist + 1;
		//Q.push(nex);
		if ( nex.dist < k ) Q[tail++] = nex;
		//		if ( tail + 1 == MAX ) tail = 0;
		//		else tail++;

		//		if ( !visited[nex.p] ){
		//		    visited[nex.p] = true;
		//		    ans++;
		//		}
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

void compute(){
    ans = 0;
    cnt = 0;
    int x, y, k;
    In in[30];
    init();
    //    for ( int i = 0; i < n; i++ ){
    //	scanf("%d %d %d", &x, &y, &k);
    //	bfs(x, y, k);
    //    }

    for ( int i = 0; i < n; i++ ){
	scanf("%d %d %d", &in[i].x, &in[i].y, &in[i].k);
    }
    sort( in, in + n);
    for ( int i = 0; i < n; i++ ){
	bfs( in[i].x, in[i].y, in[i].k );
    }

    //    cout << cnt << endl;
    printf("%d\n", ans);
}

int main(){
    while ( cin >> n && n ){
	//	visited = map<Point, bool>();
	//	rem = map<Point, int>();
	compute();
    }
}
