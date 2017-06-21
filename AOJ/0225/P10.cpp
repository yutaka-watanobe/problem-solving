#include<iostream>
#include<string>
#include<set>
#include<cassert>
using namespace std;

int n, in[26], out[26], G[26][26];
bool visited[26];

bool check(){
    for ( int i = 0; i < 26; i++ ){
	if ( in[i] != out[i] ) return false;
    }
    return true;
}

void dfs(int u){
    visited[u] = true;
    for ( int v = 0; v < 26; v++ ){
	if ( !visited[v] && G[u][v] ) dfs(v);
    }
}

int getNC(){
    int nc = 0;
    for ( int i = 0; i < 26; i++ ) visited[i] = false;
    for ( int i = 0; i < 26; i++ ){
	if ( in[i] == 0 && out[i] == 0 ) continue;
	if ( !visited[i] ){
	    nc++;
	    dfs(i);
	}
    }
    return nc;
}

void compute(){
    for ( int i = 0; i < 26; i++ ){
	in[i] = out[i] = 0;
	for ( int j = 0; j < 26; j++ ) G[i][j] = 0;
    }

    string str;
    set<string> S;
    for ( int i = 0; i < n; i++ ){
	cin >> str;
	S.insert(str);
	in[str[0]-'a']++;
	out[str[str.size()-1]-'a']++;
	G[str[0]-'a'][str[str.size()-1]-'a'] = 1;
	G[str[str.size()-1]-'a'][str[0]-'a'] = 1;
    }

    cout << S.size() << " " << n << endl;
    return;
    if ( check() && getNC() == 1 ) cout << "OK" << endl;
    else cout << "NG" << endl;
}

main(){
    while(1){
	cin >> n;
	if ( n == 0 ) break;
	compute();
    }
}
