#include<iostream>
#include<algorithm>

using namespace std;

#define N 5
#define REP(i, n) for ( int i = 0; i < (int)n; i++ )
#define LIMIT 20

static const int T[12][2] = {{-1, -1}, {1, 1}, {1, 2}, {1, 3}, {2, 0}, {2, 1},
			     {2, 2}, {2, 3}, {2, 4}, {3, 1}, {3, 2}, {3, 3}};
static const int g[N][N] = {{-1, -1, 0, -1, -1}, {-1, 1, 2, 3, -1},
			    {4, 5, 6, 7, 8}, {-1, 9, 10, 11, -1}, {-1, -1, 0, -1, -1}};

class Puzzle{
    public:
    int C[N][N], mdist; //manhatta distance
    Puzzle(){}

    bool swapAdj( int si, int sj, int ti, int tj ){
	if ( ti < 0 || tj < 0 || ti >= N || tj >= N ) return false;
	if ( C[ti][tj] <= 0 ) return false;
	swap(C[ti][tj], C[si][sj]);
	int tti = T[C[si][sj]][0];
	int ttj = T[C[si][sj]][1];
	mdist -= max(tti, ti)-min(tti, ti) + max(ttj, tj)-min(ttj, tj);
	mdist += max(tti, si)-min(tti, si) + max(ttj, sj)-min(ttj, sj);
	return true;
    }

    bool isGoal(){
	REP(i, N) REP(j, N) if ( g[i][j] != C[i][j] ) return false;
	return true;
    }

    int getMD(){ // get initial manhattan distance
	int sum = 0;
	int ti, tj;
	REP(i, 5) REP(j, 5){
	    if ( C[i][j] <= 0 ) continue;
	    ti = T[C[i][j]][0];
	    tj = T[C[i][j]][1];
	    sum += (max(ti, i)-min(ti, i) + max(tj, j) - min(tj, j));
	}
	return sum;
    }
};

int limit;

bool dfs( int depth, Puzzle P ){
    if ( P.isGoal() ) return true;
    if ( depth + P.getMD() > limit ) return false;

    static const int di[4] = {0, -1, 0, 1};
    static const int dj[4] = {1, 0, -1, 0};

    REP(i, N) REP(j, N){
	if ( P.C[i][j] != 0 ) continue;
	REP(r, 4){
	    Puzzle v = P;
	    if ( !v.swapAdj(i, j, i+di[r], j+dj[r]) ) continue;
	    if ( dfs( depth + 1, v ) ) return true;
	}
    }

    return false;
}

int idp(Puzzle source){
    for ( limit = 0; limit <= LIMIT; limit++ ){
	source.mdist = source.getMD();
	if ( dfs(0, source) ) return limit;
    }
    return INT_MAX;
}

int main(){
    Puzzle P;
    int top;

    while(1){
	cin >> top;
	if ( top == -1 ) break;
	REP(j, N) P.C[0][j] = -1;
	P.C[0][2] = top;
	for(int i = 1; i < N; i++) REP(j, N){
	    if ( (i == 1 || i == 3) && (j == 0 || j == 4 ) ) P.C[i][j] = -1;
	    else if ( i == 4 && j != 2 ) P.C[i][j] = -1;
	    else cin >> P.C[i][j];
	}

	int cost = idp(P);
	if ( cost == INT_MAX ) cout << "NA" << endl;
	else cout << cost << endl;	
    }

    return 0;
}
