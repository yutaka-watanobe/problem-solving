#include<iostream>
#include<string>
#define N 4
#define DMAX 100
using namespace std;

char G[N][N];
string D[DMAX], target;
static const int table[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
int score, M;

bool dfs( int i, int j, bool used[4][4], string str, int depth ){
    str += G[i][j];
    if ( depth + 1 > target.size() ) return false;
    if ( str[depth] != target[depth] ) return false;
    if ( target == str ) return true;

    static const int di[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    static const int dj[8] = {1, 1, 0, -1, -1, -1, 0, 1};

    int ni, nj;
    for ( int d = 0; d < 8; d++ ){
	ni = i + di[d];
	nj = j + dj[d];
	if ( ni < 0 || nj < 0 || ni >= N || nj >= N ) continue;
	if ( used[ni][nj] ) continue;
	used[ni][nj] = true;
	if ( dfs( ni, nj, used, str, depth + 1 ) ) return true;
	used[ni][nj] = false;
    }
    return false;
}

void compute(){
    score = 0;
    bool used[4][4];
    for ( int d = 0; d < M; d++ ){
	target = D[d];
	for ( int i = 0; i < N; i++ ){
	    for ( int j = 0; j < N; j++ ){
		for ( int a = 0; a < N; a++ ){
		    for ( int b = 0; b < N; b++ ) used[a][b] = false;
		}
		used[i][j] = true;
		if (dfs( i, j, used, "",  0 )){
		    score += table[min(8, (int)target.size())];
		    goto next;
		}
		used[i][j] = false;
	    }
	}
    next:;
    }
    
    cout << score << endl;
}

void input(){
    for ( int i = 0; i < N; i++ )
	for ( int j = 0; j < N; j++ ) cin >> G[i][j];
    cin >> M;
    string str;
    for ( int i = 0; i < M; i++ ) cin >> D[i];
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	cout << "Score for Boggle game #" << i+1 << ": ";
	input();
	compute();
    }
}
