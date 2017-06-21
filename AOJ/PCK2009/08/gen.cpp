#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for ( int i = 0; i < n; i++ )
using namespace std;

#define MAX 100

int G[MAX][MAX], g;
bool V[MAX];

bool rec(int u, int n){
    V[u] = true;
    if ( u == g ) return true;

    for ( int v = 0; v < n; v++ ){
	if ( G[u][v] == 0 || V[v] ) continue;
	if ( rec(v, n) ) return true;
    }
    return false;
}

bool dfs(int s, int n){
    rep(i, n) V[i] = false;
    return rec(s, n);
}

void gen(int x, int e){
    int c, n, m, s, d;
    n = x;
    s = rand()%n;
    d = rand()%n;
    while( d == s ) d = rand()%n;

    vector<pair<pair<int, int>, int> > v;
    c = rand()%9+1;

    rep(i, n) rep(j, n) G[i][j] = 0;

    g = d;
    while( !dfs(s, n) ){
	int i = rand()%n;
	int j = rand()%n;
	while( i == j ) j = rand()%n;
	G[i][j] = G[j][i] = (1000+(rand()%20)*100);
    }

    for ( int a = 0; a < e; a++ ){
	int i = rand()%n;
	int j = rand()%n;
	while( i == j ) j = rand()%n;
	int cost = (1000 + (rand()%20)*100);
	G[i][j] = G[j][i] = cost;
    }


    for ( int i = 0; i < n-1; i++ ){
	for ( int j = i+1; j < n; j++ ){
	    if ( G[i][j] == 0 ) continue;
	    v.push_back(make_pair(make_pair(i, j), G[i][j] ));
	}
    }

    m = v.size();
    cout << c << " " << n << " " << m << " " << s+1 << " " << d+1 << endl;
    for ( int i = 0; i < v.size(); i++ ){
	pair<int, int> st = v[i].first;
	int cost = v[i].second;
	cout << st.first+1 << " " << st.second+1 << " " << cost << endl;
    }
    assert( m < 500 );
}

main(){
    gen(5, 10);
    gen(5, 20);
    gen(5, 30);
    gen(5, 40);
    gen(5, 50);
    gen(5, 60);
    gen(6, 70);
    gen(6, 8);
    gen(7, 8);
    gen(7, 12);
    gen(8, 15);
    gen(8, 16);
    gen(10, 0);
    gen(10, 10);
    gen(10, 20);
    gen(10, 30);
    gen(10, 40);
    gen(10, 80);
    gen(10, 100);
    gen(10, 150);
    gen(10, 200);
    gen(10, 250);
    gen(10, 300);
    gen(20, 10);
    gen(20, 20);
    gen(20, 30);
    gen(20, 40);
    gen(20, 50);
    gen(20, 60);
    gen(20, 70);
    gen(20, 100);
    gen(20, 150);
    gen(20, 200);
    gen(30, 10);
    gen(30, 20);
    gen(30, 30);
    gen(30, 40);
    gen(30, 150);
    gen(30, 160);
    gen(30, 170);
    gen(30, 180);
    gen(30, 190);
    gen(30, 200);
    gen(50, 20);
    gen(50, 30);
    gen(50, 50);
    gen(50, 160);
    gen(50, 170);
    gen(50, 180);
    gen(50, 190);
    gen(50, 200);
    gen(60, 20);
    gen(60, 30);
    gen(60, 50);
    gen(60, 60);
    gen(60, 70);
    gen(60, 80);
    gen(60, 190);
    gen(60, 200);
    gen(80, 20);
    gen(80, 30);
    gen(80, 150);
    gen(80, 160);
    gen(80, 170);
    gen(80, 180);
    gen(80, 190);
    gen(80, 200);
    gen(100, 0);
    gen(100, 10);
    gen(100, 20);
    gen(100, 30);
    gen(100, 40);
    gen(100, 50);
    gen(100, 60);
    gen(100, 70);
    gen(100, 80);
    gen(100, 150);
    gen(100, 160);
    gen(100, 170);
    gen(100, 280);
    gen(100, 200);
    gen(100, 280);
    gen(100, 300);

    cout << "0 0 0 0 0" << endl;
}
