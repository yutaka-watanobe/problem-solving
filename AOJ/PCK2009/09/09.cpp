#include<iostream>
#include<cassert>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )
#define MAX 10

struct Cell{ int i, j, x, id; };

int H, W, n, b, k; 
Cell P[MAX*MAX], M[MAX][MAX], A[MAX][MAX];
int V[MAX+1];

int ans;

bool check(int si, int sj, int r, int c ){
    rep(i, r) rep(j, c){
	int ii = si + i;
	int jj = sj + j;
	if ( ii < 0 || jj < 0 || ii >= H || jj >= W ) return false;
	if ( M[ii][jj].x ) return false;
    }
    return true;
}

void solve(int pos){
    if ( pos >= n ){ 
	rep(i, H) rep(j, W) if ( M[i][j].x == 0 ) return;
	rep(i, H) rep(j, W) A[i][j] = M[i][j];
	ans++;
	return;
    }

    for(int r = 1; r <= P[pos].x; r++){
	if ( P[pos].x % r != 0 ) continue;
	int c = P[pos].x / r;
	rep(di, r) rep(dj, c){
	    int si = P[pos].i - di;
	    int sj = P[pos].j - dj;
	    if ( check( si, sj,  r, c ) ){
		rep(i, r) rep(j, c) M[si+i][sj+j] = P[pos];
		solve( pos + 1 );
		rep(i, r) rep(j, c) M[si+i][sj+j].x = 0;
	    }
	}
    }
}

int main(){
    int x;
    while( cin >> W >> H && H && W ){
	assert( 1 <= W && W <= 10 );
	assert( 1 <= H && H <= 10 );
	cin >> n;
	assert( 1 <= n && n <= 100 );
	rep(i, n){
	    cin >> b >> k;
	    assert( 1 <= b && b <= n );
	    assert( 1 <= k );
	    P[b-1].x = k;
	}

	rep(i, H) rep(j, W){
	    cin >> x;
	    assert( 0 <= x && x <= n);
	    if ( x ){  P[x-1].i = i; P[x-1].j = j; P[x-1].id = x-1; }
	    M[i][j].x = 0;
	}
	ans = 0;
	solve(0);
	if ( ans == 1 ) {
	    rep(i, H){
		rep(j, W){
		    if ( j ) cout << " ";
		    cout << A[i][j].id+1;
		}
		cout << endl;
	    }
	} else {
	    cout << "NA" << endl;
	}
    }
    return 0;
}
