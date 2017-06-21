#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define REP(i, a, b) for ( int i = a; i < b; i++ )
#define rep(i, n) REP(i, 0, n)
#define INFTY (1<<21)

int m, n, k, d, C[7], G[110][110], N, D[110][64];

int getID(string str){
    if ( str == "H" ) return 0;
    if ( str == "D" ) return N - 1;
    string num = str.substr(1, str.size()-1);
    if ( str[0] == 'C' ) return atoi(num.c_str());
    return atoi(num.c_str()) + m;
}

bool isC(int x){ return 1 <= x && x <= m; }

int bellman(){
    rep(i, N) rep(j, (1<<m)) D[i][j] = INFTY;
    D[0][0] = 0;
    rep(o, N*(1<<m)) rep(u, N) rep(v, N){
	if ( u == v || G[u][v] == INFTY ) continue;
	rep(b, (1<<m)){
	    if (isC(v) && (b&(1<<(v-1))) != 0 ) continue; 
	    if ( isC(v) ) D[v][b|(1<<(v-1))] = min(D[v][b|(1<<(v-1))], D[u][b] + G[u][v] - C[v]);
	    else D[v][b] = min(D[v][b], D[u][b] + G[u][v]);
	}
    }
    int minv = INFTY;
    rep(i, (1<<m)) minv = min(minv, D[N-1][i]);
    return minv;
}

int main(){
    string source, target;
    int cost;
    while(cin >> m >> n >> k >> d && m ){
	N = 2 + n + m;
	REP(i, 1, m+1) cin >> C[i];
	rep(i, N) rep(j, N) G[i][j] = INFTY;
	rep(i, d){
	    cin >> source >> target >> cost;
	    int s = getID(source);
	    int t = getID(target);
	    G[t][s] = G[s][t] = min(G[s][t], cost * k);
	}
	cout << bellman() << endl;
    }
    return 0;
}

/*

拡張グラフにおいて最短経路(距離)を求めるプログラムが作成できるかが問われています。ただし、負のコストを含むためダイクストラのアルゴリズムを適用することはできません。

この解説ではスペース節約のため以下のマクロを用いています。
#define REP(i, a, b) for ( int i = a; i < b; i++ )
#define rep(i, n) REP(i, 0, n)

拡張グラフにおいてベルマンフォードのアルゴリズムを適用します。各ケーキ屋さんに立ち寄ったかの情報は5ビット分の整数として管理します。




 */
