#include<iostream>
#include<string>

using namespace std;
#define REP(i, n) for ( int i = 0; i < (int)n; i++ )
  static const int RT[24][6] = {
	{1,2,3,4,5,6}, {1,3,5,2,4,6}, {1,5,4,3,2,6}, {1,4,2,5,3,6},
	{4,2,1,6,5,3}, {4,1,5,2,6,3}, {4,5,6,1,2,3}, {4,6,2,5,1,3},
	{6,2,4,3,5,1}, {6,4,5,2,3,1}, {6,5,3,4,2,1}, {6,3,2,5,4,1},
	{3,2,6,1,5,4}, {3,6,5,2,1,4}, {3,5,1,6,2,4}, {3,1,2,5,6,4},
	{5,1,3,4,6,2}, {5,3,6,1,4,2}, {5,6,4,3,1,2}, {5,4,1,6,3,2},
	{2,1,4,3,6,5}, {2,4,6,1,3,5}, {2,6,3,4,1,5}, {2,3,1,6,4,5}
    };
class Dice{
    public:
  

    int face[6];
    Dice(){}

    void set(int top, int front ){
	for ( int i = 0; i < 24; i++ ){
	    if ( RT[i][0] == top && RT[i][1] == front ){
		for  (int f = 0; f < 6; f++ ) face[f] = RT[i][f];
		return;
	    }
	}
    }

    void moveFront(){
	int tmp = face[0];
	face[0] = face[4];
	face[4] = face[5];
	face[5] = face[1];
	face[1] = tmp;
    }

    void moveRight(){
	int tmp = face[0];
	face[0] = face[3];
	face[3] = face[5];
	face[5] = face[2];
	face[2] = tmp;
    }
    
    void moveBack(){
	for ( int i = 0; i < 3; i++ ) moveFront();
    }

    void moveLeft(){
	for ( int i = 0; i < 3; i++ ) moveRight();
    }
};
    
static const int MAX = 10;

int R, C, sr, sc, top, face, M[MAX][MAX];
pair<int, int> P[100000];
int D;

bool visited[MAX][MAX][7][7][7];

bool valid( int i, int j, int top ){
    if ( i < 0 || j < 0 || i >= R || j >= C ) return false;
    return M[i][j] == top || M[i][j] == (-1);
}

bool dfs( int depth, int r, int c, Dice cur, bool isFast){

    if ( !isFast && r == sr && c == sc ){
	P[depth++] = make_pair(r, c);
	D = depth; return true;
    }

    P[depth] = make_pair(r, c);
    if ( !(r==sr&&c==sc) ) visited[r][c][cur.face[0]][cur.face[1]][cur.face[2]] = true;

    Dice next;
    // left
    if ( valid( r, c-1, cur.face[0] ) ){
	next = cur;
	next.moveLeft();
	if ( !visited[r][c-1][next.face[0]][next.face[1]][next.face[2]] )
	    if ( dfs( depth+1, r, c-1, next, false) ) return true;
    }
    // right
    if ( valid( r, c+1, cur.face[0] ) ){
	next = cur;
	next.moveRight();
	if ( !visited[r][c+1][next.face[0]][next.face[1]][next.face[2]] )
	    if ( dfs( depth+1, r, c+1, next, false) ) return true;
    }
    // front
    if ( valid( r+1, c, cur.face[0] ) ){
	next = cur;
	next.moveFront();
	if ( !visited[r+1][c][next.face[0]][next.face[1]][next.face[2]] )
	    if ( dfs( depth+1, r+1, c, next, false) ) return true;
    }
    // back
    if ( valid( r-1, c, cur.face[0] ) ){
	next = cur;
	next.moveBack();
	if ( !visited[r-1][c][next.face[0]][next.face[1]][next.face[2]] )
	    if ( dfs( depth+1, r-1, c, next, false) ) return true;
    }

    return false;
}

void compute(){
    Dice initial = Dice();
    initial.set(top, face);
    
    REP(i, R) REP(j, C) REP(t, 7) REP(f, 7) REP(r, 7) visited[i][j][t][f][r] = false;
    if ( !dfs(0, sr, sc, initial, true) ){
	cout << "  No Solution Possible" << endl;
    } else {
	for ( int i = 0; i < D; i++ ){
	    if ( i%9 == 0 ) cout << "  ";
	    cout << "(" << P[i].first+1 << "," << P[i].second+1 << ")";
	    if ( i != D-1 ) cout << ",";
	    if ( (i+1)%9 == 0 && i+1 < D ) cout << endl;
	}
	cout << endl;
    }
}

int main(){
    string name;
    while(1){
	cin >> name;
	if ( name == "END" ) break;
	cin >> R >> C >> sr >> sc >> top >> face;
	sr--; sc--;
	REP(i, R) REP(j, C) cin >> M[i][j];
	cout << name << endl;
	compute();
    }
    return 0;
}
