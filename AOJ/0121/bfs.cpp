#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

static const int p[8] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

#define M 1000093

bool H[M+1];

class Puzzle{
    public:
    int state, s, d;
    
    Puzzle(){ state = 0; }

    void set( int num, int idx ){
	state += num*p[idx];
	if ( num == 0 ) s = idx;
    }

    bool move( int ni, int nj ){
	if ( ni < 0 || nj < 0 || ni >= 2 || nj >= 4 ) return false;
	int x = s;
	int y = ni*4 + nj;
	int a = state/p[x]%10;
	int b = state/p[y]%10;
	state -= a*p[x] + b*p[y];
	state += a*p[y] + b*p[x];
	s = y;
	return true;
    }

    bool solved(){
	return state == 76543210;
    }

    bool operator < ( const Puzzle &z ) const {
	return state < z.state;
    }
};

int bfs( Puzzle s ){
    set<Puzzle> v;
    queue<Puzzle> Q;
    s.d = 0;
    v.insert( s );
    
    H[ s.state % M ] = true;

    Q.push(s);

    Puzzle u, nt;
    while( !Q.empty() ){
	u = Q.front(); Q.pop();
	if ( u.solved() ) return u.d;
	static const int di[4] = {0, -1, 0, 1};
	static const int dj[4] = {1, 0, -1, 0};
	for ( int r = 0; r < 4; r++ ){
	    int ni = u.s/4 + di[r];
	    int nj = u.s%4 + dj[r];
	    nt = u;
	    if ( nt.move(ni, nj) ){
		//		if ( v.count(nt) == 0 ){
		//if ( v.find(nt) == v.end() ){
		if ( !H[ nt.state % M ] ){
		    //v.insert(nt);
		    H[ nt.state % M ] = true;
		    nt.d = u.d + 1;
		    Q.push(nt);
		}
	    }
	}
    }
}

main(){
    int num;
    while( cin >> num ){
	for ( int i = 0; i <= M; i++ ) H[i] = false;

	Puzzle p;
	p.set(num, 0);
	for ( int i = 1; i < 8; i++ ) { cin >> num; p.set(num, i); }
	cout << bfs(p) << endl;
    }
}
