#include<iostream>
#include<string>
#include<cassert>
using namespace std;
#define rep(i,n) for ( int i = 0; i < n; i++ )
#define REP(i, b, e) for ( int i = b; i <= e; i++ )
#define MAX 100
#define LIMIT 180
#define BLOCK '#'
#define SPACE '.'
#define EXIT 'X'
static const string DIR = "ENWS";
static const int di[4] = {0, -1, 0, 1};
static const int dj[4] = {1, 0, -1, 0};
int H, W;
char G[MAX+2][MAX+2];

char oposite( int r ){
    return DIR[(r+2)%4];
}

bool isPerson(char ch){
    rep(d, 4) if ( ch == DIR[d] ) return true;
    return false;
}

int getDirection(char ch){
    rep(d, 4) if ( ch == DIR[d] ) return d;
}

int chengeDirection(){
    int nperson = 0;
    REP(i, 1, H) REP(j, 1, W){
	if ( !isPerson(G[i][j]) ) continue;
	nperson++;
	int curd = getDirection(G[i][j]);
	int v = curd;
	curd = ((curd == 0) ? 3 : curd-1);
	for ( int r = curd; r < curd + 4; r++ ){
	    char ch = G[i+di[r%4]][j+dj[r%4]];
	    if ( ch == SPACE || ch == EXIT ){
		v = r%4;
		break;
	    }
	}
	G[i][j] = DIR[v];
    }
    return nperson;
}

void move(){
    bool possible[MAX+2][MAX+2];
    rep(i, H+2) rep(j, W+2 ) possible[i][j] = false;

    REP(i, 1, H) REP(j, 1, W){
	if ( G[i][j] == SPACE || G[i][j] == EXIT){
	    for ( int r = 0; r < 4; r++ ){
		char target = G[i+di[r]][j+dj[r]];
		if ( isPerson(target) && target == oposite(r) ){
		    possible[i+di[r]][j+dj[r]] = true;
		    break;
		}
	    }
	}
    }

    REP(i, 1, H) REP(j, 1, W){
	if ( !isPerson(G[i][j]) || !possible[i][j] ) continue;

	int ni, nj;
	for ( int r = 0; r < 4; r++ ){
	    if ( DIR[r] == G[i][j] ) {
		ni = i + di[r];
		nj = j + dj[r];
		break;
	    }
	}

	if ( G[ni][nj] == EXIT ){
	    G[i][j] = SPACE;
	} else if ( G[ni][nj] == SPACE ){
	    G[ni][nj] = G[i][j];
	    G[i][j] = SPACE;
	}
    }
}

void trace(){
    REP(i, 1, H){
	REP(j, 1, W){
	    cout << G[i][j];
	}
	cout << endl;
    }
    cout << endl;
}

int main(){
    while(1){
	cin >> W >> H;
	if ( H == 0 && W == 0 ) break;
	assert( H <= 30 && W <= 30 );
	rep(i,H+2) rep(j,W+2) G[i][j] = BLOCK;
	REP(i, 1, H) REP(j, 1, W) {
	    cin >> G[i][j];
	    char c = G[i][j];

	    if ( i == 1 || j == 1 || i == H || j == W ){
		assert( c == '#' || c == 'X' );
	    } else {
		assert( c == '#' || c == 'X' || c == '.' ||
			c == 'E' || c == 'N' || c == 'W' || c == 'S');
	    }
	}
	
	int t = 0;
	while(1){
	    if ( t > LIMIT ) break;
	    if( !chengeDirection() ) break;
	    move();
	    t++;
	}
	if ( t > LIMIT ) cout << "NA" << endl;
	else cout << t <<  endl;
    }

    return 0;
}
