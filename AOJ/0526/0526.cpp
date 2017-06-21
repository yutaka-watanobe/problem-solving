#include<cstdio>
#include<queue>
#include<algorithm>
#define rep(i,b,e) for ( int i = b; i <= e; i++ )
using namespace std;

#define MAX 100
#define INFTY (1<<21)
int n, M[MAX+1][MAX+1];

class Node{
    public:
    int p, cost;
    Node( int p = 0, int cost = 0 ): p(p), cost(cost){}
    bool operator < ( const Node &s ) const{
	return cost > s.cost;
    }
};

int dijkstra( int s, int t ){
    priority_queue<Node> PQ;
    bool visited[MAX+1];
    int d[MAX+1];

    for ( int i = 1; i <= n; i++ ){
	visited[i] = false;
	d[i] = INFTY;
    }

    PQ.push(Node(s, 0));
    d[s] = 0;

    Node u;

    while( !PQ.empty() ){
	u = PQ.top(); PQ.pop();
	if ( u.p == t ) return u.cost;
	visited[u.p] = true;
	for ( int v = 1; v <= n; v++ ){
	    if ( M[u.p][v] == INFTY || visited[v] ) continue;
	    if ( d[v] > d[u.p] + M[u.p][v] ){
		d[v] = d[u.p] + M[u.p][v];
		PQ.push(Node(v, d[v]));
	    }
	}
    }
    return -1;
}

main(){
    int k, m, s, t, e;
    while(1){
	scanf("%d %d", &n, &k);
	if ( n == 0 && k == 0 ) break;
	rep(i,1,n) rep(j,1,n) M[i][j] = INFTY;
	rep(i,1,k){
	    scanf("%d %d %d", &m, &s, &t);
	    if ( m ){
		scanf("%d", &e);
		M[t][s] = M[s][t] = min( M[s][t], e );
	    } else printf("%d\n", dijkstra(s, t));
	}
    }
}
