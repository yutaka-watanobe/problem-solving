#include<iostream>
#include<vector>
using namespace std;
#define MAX 100
#define REP(i,e) for ( int i = 0; i < e; i++ )
class Lang{
    public:
    char ch;
    int cnt;
    Lang(){}
    Lang(int cnt, char ch): cnt(cnt), ch(ch){}

    bool operator < ( const Lang &l ) const{
	if ( cnt == l.cnt ) return ch < l.ch;
	else return cnt > l.cnt;
    }
};

int row, col;
char G[MAX][MAX];

void dfs( int i, int j, char t ){
    G[i][j] = ' ';
    static const int di[4] = {0, -1, 0, 1};
    static const int dj[4] = {1, 0, -1, 0};

    int ni, nj;
    REP(r, 4){
	ni = i + di[r];
	nj = j + dj[r];
	if ( 0 > ni || 0 > nj || ni >= row || nj >= col ) continue;
	if ( G[ni][nj] == t ) dfs( ni, nj, t );
    }
}

void compute(){
    int cnt[MAX];
    REP(i, 26) cnt[i] = 0;

    REP(i, row) REP(j, col){
	if ( G[i][j] != ' ' ){
	    cnt[G[i][j]-'a']++;
	    dfs(i, j, G[i][j]);
	}
    }
    vector<Lang> L;

    REP(i, 26) {
	if ( cnt[i] ) L.push_back( Lang(cnt[i], i+'a') );
    }
    sort( L.begin(), L.end() );
    
    for ( int i = 0; i < L.size(); i++ ){
	cout << L[i].ch << ": " << L[i].cnt << endl;
    }
}

void input(){
    cin >> row >> col;
    REP(i, row) REP(j, col) cin >> G[i][j];
}

int main(){
    int tcase; cin >> tcase;
    for ( int i = 1; i <= tcase; i++ ){
	cout << "World #" << i << endl;
	input();
	compute();
    }
    return 0;
}
