#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++)

int n, in[26], out[26], G[26][26];
bool visited[26];

bool check(){
    rep(i, 26) if ( in[i] != out[i] ) return false;
    return true;
}

void dfs(int u){
    visited[u] = true;
    rep(v, 26) if ( !visited[v] && G[u][v] ) dfs(v);
}

int getNComponent(){
    int nc = 0;
    rep(i, 26){
	if ( in[i] == 0 && out[i] == 0 ) continue;
	if ( !visited[i] ){ nc++; dfs(i); }
    }
    return nc;
}

int main(){
    while( cin >> n && n ){
	rep(i, 26){
	    in[i] = out[i] = 0;
	    visited[i] = false;
	    rep(j, 26) G[i][j] = 0;
	}
	
	string str;
	rep(i, n){
	    cin >> str;
	    in[str[0]-'a']++;
	    out[str[str.size()-1]-'a']++;
	    G[str[0]-'a'][str[str.size()-1]-'a'] = 1;
	    G[str[str.size()-1]-'a'][str[0]-'a'] = 1;
	}
	
	cout << (( check() && getNComponent() == 1 )?"OK":"NG") << endl;
    }
    return 0;
}

/*
与えられた単語を全て使用し、循環するしりとりが行えるかどうかを判定する問題です。

グラフのオイラー閉路の有無を判定するプログラムを作成できるかが問われています。

この解説ではスペースの節約のために以下のマクロを利用しています。
#define rep(i, n) for ( int i = 0; i < n; i++)

まず、与えられた単語でグラフを作成します。グラフはアルファベットの数である26個のノードを持ち、与えられた各単語について最初の文字が視点、最後の文字が終点となるようにエッジを追加します。有向きグラフがオイラー閉路を持つ条件は、このグラフにの全てのノードについて、入力エッジと出力エッジの数が等しいことです。ただし、グラフが連結で無い場合もすべての単語で循環しりとりを行うことも不可能になるので注意が必要です。

 */
