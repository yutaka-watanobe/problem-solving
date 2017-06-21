// Strongly connected component

#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100000
using namespace std;


class Graph{
public:
    int n;
    vector<int> adj[MAX];
    Graph(int n = 0):n(n){
	
    }
    void connect(int i, int j){ adj[i].push_back(j); }
    void transpose(){
	vector<int> nadj[MAX];
	for ( int i = 0; i < n; i++ ){
	    for ( int j = 0; j < adj[i].size(); j++ ){
		nadj[adj[i][j]].push_back(i);
	    }
	}
	for ( int i = 0; i < n; i++ ) adj[i] = nadj[i];
    }
};

Graph g;
int visited[MAX], finish[MAX], t;
vector<int> com;

void dfs(int u){
    visited[u] = t++;
    for ( int i = 0; i < g.adj[u].size(); i++ ){
	int v = g.adj[u][i];
	if ( visited[v] == -1 ) dfs(v);
    }
    finish[u] = t++;
}

void dfsT(int u){
    com.push_back(u);
    visited[u] = 1;
    for ( int i = 0; i < g.adj[u].size(); i++ ){
	int v = g.adj[u][i];
	if ( visited[v] == 0 ) dfsT(v);
    }
}

main(){
    int n, m, s, d;
    cin >> n >> m;
    g = Graph(n); 
    
    for ( int i = 0; i < m; i++ ){
	cin >> s >> d;
	g.connect(s, d);
    }

    for ( int i = 0; i < n; i++ ) visited[i] = finish[i] = -1;
    t = 0;
    for ( int i = 0; i < n; i++ ){
	if ( visited[i] == -1 ) dfs(i);
    }

    /*
    for ( int i = 0; i < n; i++ ){
	cout << i << ": " << visited[i] << "/" << finish[i] << endl;
	}*/

    g.transpose();

    vector<pair<int, int> > order;
    for ( int i = 0; i < n; i++ ){
	order.push_back(make_pair(finish[i], i));
    }
    sort(order.begin(), order.end());

    for ( int i =  0; i < n; i++ ) visited[i] = 0;

    for ( int i = n-1; i >= 0; i-- ){
	int u = order[i].second;
	com.clear();
	if ( visited[u] == 0 ) {
	    dfsT(u);
	    for ( int c = 0; c < com.size(); c++ ){
		cout << com[c] << " ";
	    }
	    cout << endl;
	}
    }
    
    
}

