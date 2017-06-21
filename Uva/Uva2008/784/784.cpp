#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string> M;

void dfs(int i, int j){
    static const int di[4] = {0, -1, 0, 1};
    static const int dj[4] = {1, 0, -1, 0};

    M[i][j] = '#';
    int ni , nj;
    for ( int r = 0; r < 4; r++ ){
	ni = i + di[r];
	nj = j + dj[r];
	if ( ni < 0 || ni > M.size()  ) continue;
	if ( nj < 0 || nj > M[ni].size() ) continue;
	if ( M[ni][nj] != ' ' ) continue;
	dfs( ni, nj );
    }
}

void compute(){
    string line;
    M.clear();
    int si, sj;
    while(1){
	getline(cin, line);
	for ( int i = 0; i < line.size(); i++ ){
	    if ( line[i] == '*' ){
		line[i] = ' ';
		si = M.size(); sj = i;
	    }
	}
	M.push_back(line);
	if ( line[0] == '_' ) break;
    }
    dfs(si, sj);
    for ( int i = 0; i < M.size(); i++ ) cout << M[i] << endl;

}

int main(){
    string line;
    int tcase; cin >> tcase;
    getline(cin, line);
    for ( int i = 0; i < tcase; i++ ) compute();
    return 0;
}
