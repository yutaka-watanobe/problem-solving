// DFS in Grid (loop in horizontal)
#include<iostream>
#include<algorithm>
using namespace std;

#define REP(i, n) for ( int i = 0; i < n; i++ )
#define MAX 20

int row, col, si, sj;
char C[MAX][MAX];
bool V[MAX][MAX];
int nregion;

void dfs( int i, int j ){
    static const int di[4] = {0, -1, 0, 1};
    static const int dj[4] = {1, 0, -1, 0};
    V[i][j] = true;
    nregion++;
    int ni, nj;
    REP(r, 4){
	ni = i + di[r];
	nj = j + dj[r];
	if ( ni < 0 || ni >= row ) continue;
	if ( nj == -1 ) nj = col-1;
	if ( nj == col ) nj = 0;
	if ( !V[ni][nj] && C[i][j] == C[ni][nj] ) dfs(ni, nj);
    }
}

int compute(){
    char l = C[si][sj];
    dfs( si, sj );
    int ans = 0;
    REP(i, row) REP(j, col){
	if ( C[i][j] == l && !V[i][j]){
	    nregion = 0;
	    dfs(i, j);
	    ans = max( ans, nregion );
	}
    }
    return ans;
}

int main(){
    while( cin >> row >> col ){
	REP(i, row) REP(j, col) { cin >> C[i][j]; V[i][j] = false;}
	cin >> si >> sj;
	cout << compute() << endl;
    }
    return 0;
}
