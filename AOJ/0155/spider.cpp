#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#define MAX 1000
#define INFTY (1<<21)

struct Point{ int x, y; };

int n;
double G[MAX][MAX]; // graph
double D[MAX]; // shortest cost
int P[MAX]; // path
Point B[MAX];

void dijkstra(int s){
    bool visited[MAX];
    for ( int i = 1; i <= n; i++ ){
	D[i] = INFTY;
	P[i] = -1;
	visited[i] = false;
    }

    D[s] = 0.0;

    while(1){
	double minv = INFTY;
	int u = 0;
	for ( int i = 1; i <= n; i++ ){
	    if ( visited[i] ) continue;
	    if ( minv > D[i] ){
		minv = D[i];
		u = i;
	    }
	}

	if (minv == INFTY ) break;
	visited[u] = true;

	for ( int v = 1; v <= n; v++ ){
	    if ( visited[v] ) continue;
	    if ( D[u] + G[u][v] < D[v] ){
		D[v] = D[u] + G[u][v];
		P[v] = u; // parent of node v is u
	    }
	}
    }
}

void parse(int i, vector<int> &ans){
    if ( i == -1 ) return;
    parse(P[i], ans);
    ans.push_back(i);
}

void printPath(int s, int g){
    if ( D[g] == INFTY ){
	cout << "NA" << endl;
	return;
    }
    vector<int> ans;
    parse(g, ans);
    for ( int i = 0; i < ans.size(); i++ ){
	if ( i ) cout << " ";
	cout << ans[i];
    }
    cout << endl;
}

double getDist(Point p1, Point p2){
    return sqrt( 1.0*(p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

void makeGraph(){
    for ( int i = 1; i <= n; i++ ){
	for ( int j = 1; j <= n; j++ ){
	    double d = getDist(B[i], B[j]);
	    if ( d <= 50 ) G[i][j] = d;
	    else G[i][j] = INFTY;
	}
    }
}

main(){
    int id, query, s, g;
    while( cin >> n && n ){
	for ( int i = 0; i < n; i++ ){
	    cin >> id;
	    cin >> B[id].x >> B[id].y;
	}
	makeGraph();
	cin >> query;
	for ( int i = 0; i < query; i++ ){
	    cin >> s >> g;
	    dijkstra(s);
	    printPath(s, g);
	}
    }
    return 0;
}
