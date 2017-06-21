// 423
#include<iostream>
#include<string>
#include<algorithm>
#define MAX 101

using namespace std;

// begin_of_source
int N;
int M[MAX][MAX];

void dijkstra( int source, int d[], int pi[] ){
    bool visited[MAX]; // S に属するノードは true
    for ( int i = 0; i < N; i++ ){
	d[i] = INT_MAX;
	visited[i] = false;
    }

    d[source] = 0; // 最初に s が u として選ばれる
    pi[source] = -1;

    while( 1 ){
	int u; // 最適なノード u を選ぶ
	int mincost = INT_MAX;
	for ( int i = 0; i < N; i++ ){
	    if ( !visited[i] && d[i] < mincost ){
		mincost = d[i]; u = i;
	    }
	}

	// u が存在しなかったとき、つまり S がこれ以上増えないとき、終了
	if ( mincost == INT_MAX ) break;

	visited[u] = true; // u を S に追加

	for ( int v = 0; v < N; v++ ){
	    // v が S に含まれる場合　または　エッジ(u, v)がない場合は　無視
	    if ( visited[v] || M[u][v] == INT_MAX ) continue;
	    if ( d[u] + M[u][v] < d[v] ){
		d[v] = d[u] + M[u][v];
		pi[v] = u;
	    }
	}
    }
}
// end_of_source

main(){
    cin >> N;
    string x;
    for ( int i = 1; i < N; i++ ){
	for ( int j = 0; j < i; j++ ){
	    cin >> x;
	    if ( x == "x" )
		M[i][j] = M[j][i] = INT_MAX;
	    else
		M[i][j] = M[j][i] = atoi(x.c_str());
	}
    }

    int d[MAX];
    dijkstra(0,  d );
    int maxvalue = 0;
    for ( int i = 0; i < N; i++ ){
	if ( d[i] != INT_MAX && maxvalue < d[i] ) maxvalue = d[i];
    }
    cout << maxvalue << endl;
}

