#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 64

class Piece{
    public: 
    int W, H;
    char G[MAX][MAX];

    void rotate(){
	char t[MAX][MAX];
	for ( int i = 0; i < H; i++ ){
	    for ( int j = 0; j < W; j++ ){
		t[j][H-i-1] = G[i][j];
	    }
	}
	swap(W, H);
	for ( int i = 0; i < H; i++ ){
	    for ( int j = 0; j < W; j++ ){
		G[i][j] = t[i][j];
	    }
	}
    }

    void trim(){
	int si, sj, ei, ej;
	si = sj = 100;
	ej = -1;
	ei = -1;
	for ( int i = 0; i < H; i++ ){
	    for ( int j = 0; j < W; j++ ){
		if ( G[i][j] == '.' ) continue;
		si = min(i, si);
		sj = min(j, sj);
		ei = max(i, ei);
		ej = max(j, ej);
	    }
	}

	char t[MAX][MAX];
	for ( int i = si; i <= ei; i++ ){
	    for ( int j = sj; j <= ej; j++ ){
		t[i-si][j-sj] = G[i][j];
	    }
	}
	W = ej-sj+1;
	H = ei-si+1;
	for ( int i = 0; i < H; i++ ){
	    for (int j = 0;j < W; j++ ){
		G[i][j] = t[i][j];
	    }
	}

    }
};

char G[MAX][MAX], T[MAX][MAX];
int W, H;
Piece p;

bool check( int si, int sj, Piece u ){
    for ( int i = 0; i < H;i++ ){
	for ( int j = 0; j < W; j++ ) T[i][j] = G[i][j];
    }
    
    for ( int i = 0; i < u.H; i++ ){
	for ( int j = 0; j < u.W; j++ ){
	    if ( G[i+si][j+sj] == '#' && u.G[i][j] == '#' ) return false;
	    if ( G[i+si][j+sj] == '#' || u.G[i][j] == '#' ) {
		T[i+si][j+sj] = '#';
	    }
	}
    }

    return true;
}

int getScore(){
    int score = 0;
    for ( int i = 0; i < H; i++ ){
	int cnt = 0;
	for ( int j = 0; j < W; j++ ){
	    if ( T[i][j] == '#' ) cnt++;
	    else break;
	}
	if ( cnt == W ) score++;
    }
    return score;
}

int compute(){
    int maxs = -1;
    for ( int r = 0; r < 4; r++ ){
	for ( int i = 0; i <= H - p.H; i++ ){
	    for ( int j = 0; j <= W - p.W; j++ ){
		if ( check(i, j, p) ){
		    maxs = max( maxs, getScore() );
		}
	    }
	}
	p.rotate();
    }
    return maxs;
}

int main(){
    int tcase;  cin >> tcase;
    for ( int t = 0; t < tcase; t++ ){
	cin >> p.H >> p.W;
	for ( int i = 0; i < p.H; i++ ){
	    for ( int j = 0; j < p.W; j++ ) cin >> p.G[i][j];
	}
	cin >> H >> W;
	for ( int i = 0; i < H; i++ ){
	    for ( int j = 0; j < W; j++ ) cin >> G[i][j];
	}
	p.trim();
	cout << compute() << endl;
    }

    return 0;
}
