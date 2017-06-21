#include<iostream>
#include<algorithm>
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
};

int ans;

void dfs( Puzzle p, int depth, int from ){
    if ( depth > ans ) return;
    if ( p.solved() ) {
	ans = min( ans, depth );
	return;
    }

    static const int di[4] = {0, -1, 0, 1};
    static const int dj[4] = {1, 0, -1, 0};
    Puzzle nt;
    for ( int r = 0; r < 4; r++ ){
	if ( (r+2)%4 == from ) continue;
	int ni = p.s/4 + di[r];
	int nj = p.s%4 + dj[r];
	nt = p;
	if ( nt.move(ni, nj) ) dfs( nt, depth+1, r );
    }
}

main(){
    Puzzle p;
    int num;
    while( cin >> num ){
	p.set(num, 0);
	for ( int i = 1; i < 8; i++ ) { cin >> num; p.set(num, i); }
	ans = 30;
	dfs(p, 0, -1);
	cout << ans << endl;
    }
}
