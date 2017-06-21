#include<iostream>
using namespace std;
static const int MAX = 100;
static const char OB = '.';

char G[MAX+2][MAX+2];
int r, c;

main(){
    while( cin >> r >> c && (r && c)){
	for ( int i = 0; i < r+2; i++ ){
	    for ( int j = 0; j < c+2; j++ ){
		G[i][j] = OB;
	    }
	}
	for ( int i = 1; i <= r; i++ ){
	    for ( int j = 1; j <= c; j++ ){
		cin >> G[i][j];
	    }
	}

	static const int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
	static const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
	
	int count = 0;

	for ( int i = 1; i <= r; i++ ){
	    for ( int j = 1; j <= c; j++ ){
		if ( G[i][j] == OB ) continue;
		int ni, nj;
		bool isOB = false;
		for ( int d = 0; d < 8; d++ ){
		    ni = i + dx[d];
		    nj = j + dy[d];
		    if ( G[ni][nj] != OB ){
			isOB = true;
		    }
		}
		if ( !isOB ) count++;
	    }
	}

	cout << count << endl;

    }
}
