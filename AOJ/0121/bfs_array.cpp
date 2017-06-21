#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

class Puzzle{
    public:
    int p[8], s;
    
    Puzzle(){}

    void set( int num, int idx ){
	p[idx] = num;
	if ( num == 0 ) s = idx;
    }

    bool move( int ni, int nj ){
	if ( ni < 0 || nj < 0 || ni >= 2 || nj >= 4 ) return false;
	swap( p[s], p[ni*4 + nj] );
	s = ni*4 + nj;
	return true;
    }

    bool solved(){
	for ( int i = 0; i < 8; i++ ) if ( p[i] != i ) return false;
	return true;
    }

    bool operator < ( const Puzzle &z ) const {
	for ( int i = 0; i < 8; i++ ){
	    if ( p[i] == z.p[i] ) continue;
	    return p[i] < z.p[i];
	}
	return false;
    }
};

int bfs( Puzzle s ){
    map<Puzzle, int> d;
    set<Puzzle> v;
    queue<Puzzle> Q;
    d[s] = 0;
    v.insert( s );
    Q.push(s);

    Puzzle u, nt;
    while( !Q.empty() ){
	u = Q.front(); Q.pop();
	if ( u.solved() ) return d[u];
	static const int di[4] = {0, -1, 0, 1};
	static const int dj[4] = {1, 0, -1, 0};
	for ( int r = 0; r < 4; r++ ){
	    int ni = u.s/4 + di[r];
	    int nj = u.s%4 + dj[r];
	    nt = u;
	    if ( nt.move(ni, nj) ){
		//		if ( v.count(nt) == 0 ){
		if ( v.find(nt) == v.end() ){
		    v.insert(nt);
		    d[nt] = d[u] + 1;
		    Q.push(nt);
		}
	    }
	}
    }
}

main(){
    Puzzle p;
    int num;
    while( cin >> num ){
	p.set(num, 0);
	for ( int i = 1; i < 8; i++ ) { cin >> num; p.set(num, i); }
	cout << bfs(p) << endl;
    }
}
