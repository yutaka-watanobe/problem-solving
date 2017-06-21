#include<iostream>
#include<queue>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++)
#define MAX 100
#define INF (1<<21)
int n, L[MAX][MAX], S[MAX];

int bfs( int s, int t ){
    queue<int> q; q.push(s);
    int u, v, d[MAX];
    rep(i, n) d[i] = INF;
    d[s] = 1;
    while( !q.empty() ){
	u = q.front(); q.pop();
	rep(i, S[u]){
	    v = L[u][i];
	    if ( d[v] == INF ){
		d[v] = d[u] + 1;
		q.push(v);
	    }
	}
    }
    return d[t];
}

main(){
    int s, t, tl, q, c;
    cin >> n;
    rep(i, n){
	cin >> s; s--; cin >> S[s];
	rep(j, S[s]){ cin >> L[s][j]; L[s][j]--; }
    }
    cin >> q;
    rep(i, q){
	cin >> s >> t >> tl;
	c = bfs(s-1, t-1);
	if ( c <= tl ) cout << c << endl;
	else cout << "NA" << endl;
    }
}
