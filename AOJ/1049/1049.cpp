#include<iostream>
using namespace std;

#define MAX 20
#define rep(i, n) for ( int i = 0; i < (int)n; i++)
#define INFTY (1<<21)

int M[MAX][MAX], n;
bool used[MAX];
int id[MAX], pos[MAX], ans;

int md(){
    int m = 0;
    rep(i, n){
	if ( used[i] ) continue;
	for ( int j = i+1; j < n; j++ ){
	    if ( used[j] ) continue;
	    if ( i == j ) continue;
	    m = max(m, M[i][j]);
	}
    }
    return m;
}

void rec( int cur, int w ){
    if ( cur == n ){ ans = min(ans, w); return;}
    if ( w + md() >= ans ) return;

    rep(i, n){
	if ( used[i] ) continue;
	int npos = w;
	rep(j, cur){ 
	    npos = max(npos, pos[j] + M[id[j]][i]);
	}
	pos[cur] = npos;
	id[cur] = i;
	used[i] = true;	
	rec( cur+1, npos);
	used[i] = false;
    }
}

main(){
    while( cin >> n && n ){
	rep(i, n) rep(j, n) cin >> M[i][j];
	rep(i, n) rep(j, n) M[i][j] = max( M[i][j], M[j][i] );
	rep(i, n) used[i] = false;
	ans = INFTY;
	rec(0, 0);
	cout << ans << endl;
    }
}

