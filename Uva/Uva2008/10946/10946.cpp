#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

static const int MAX = 50;
static const char WATER = '.';

char G[MAX+2][MAX+2];
bool visited[MAX+2][MAX+2];

struct Result{
    int counter;
    char symbol;
    bool operator < ( const Result &r ) const{
	if ( counter == r.counter ) return symbol < r.symbol;
	return counter > r.counter;
    }
};

int row, col, counter;

void dfs( int i, int j, char target ){
    visited[i][j] = true;
    counter++;

    static int di[4] = {0, -1, 0, 1};
    static int dj[4] = {1, 0, -1, 0};
    //    static int di[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    //    static int dj[8] = {1, 1, 0, -1, -1, -1, 0, 1};

    int ni, nj;
    for ( int d = 0; d < 4; d++ ){
	ni = i + di[d];
	nj = j + dj[d];
	if ( G[ni][nj] == target && !visited[ni][nj] ) dfs( ni, nj, target );
    }
}

void compute(){
    vector<Result> results;

    for ( int i = 0; i < row+2; i++ ){
	for ( int j = 0; j < col+2; j++ ) visited[i][j] = false;
    }

    for ( int i = 1; i <= row; i++ ){
	for ( int j = 1; j <= col; j++ ){
	    if( !visited[i][j] && G[i][j] != WATER ){
		char ch = G[i][j];
		counter = 0;
		dfs( i, j, ch );
		Result r;
		r.counter = counter;
		r.symbol = ch;
		results.push_back(r);
	    }
	}
    }
    sort( results.begin(), results.end() );

    for ( int i = 0; i < results.size(); i++ ){
	cout << results[i].symbol << " " << results[i].counter << endl;
    }
}

bool input(){
    cin >> row >> col;
    if ( row == 0 && col == 0 ) return false;
    
    for ( int i = 0; i < row+2; i++ ) G[i][0] = G[i][col+1] = WATER;
    for ( int j = 0; j < col+2; j++ ) G[0][j] = G[row+1][j] = WATER;
    for ( int i = 1; i <= row; i++ ){
	for ( int j = 1; j <= col; j++ ) cin >> G[i][j];
    }

    return true;
}

main(){
    for( int i = 1; input(); i++ ){
	cout << "Problem " << i << ":" << endl;
	compute();
    }
}
