#include<stdio.h>
#include<iostream>
#include<queue>
#include<map>
using namespace std;

#define MODE_BACK 0
#define MODE_FORWARD 1
#define LIMIT 10
#define MAX 20

int rshift(int v, int p ){
    static const int base[4] = {1, 1000, 1000000, 1000000000};
    p = 3 - p + 1;
    int t, r;
    t = v%base[p] - v%base[p-1];
    v -= t;
    r = t%(base[p-1]*10);
    t -= r;
    t /= 10;
    t += r*100;
    v += t;
    return v;
}

int ushift(int v,  int p ){
  static const int base[4] = {-1, 100000000, 10000000, 1000000};
  int b = base[p];
  int t1, t2, t3;
  t1 = ((v%(b*10))/b)*b; b /= 1000;
  t2 = ((v%(b*10))/b)*b; b /= 1000;
  t3 = ((v%(b*10))/b)*b;b /= 1000;
  v -= (t1 + t2 + t3);
  v += t1/1000000 + (t2+t3)*1000;
  return v;
}

map<int, int> GP, GD, GC;


int BFS(int s, map<int, int> &P, map<int, int> &D, map<int, int> &C, int mode, int &u){
    queue<int> Q;

    map<int, bool> visited;
    visited[s] = true;
    D[s] = 0;
    P[s] = -1;

    Q.push(s);

    int v;
    while(!Q.empty()){
	u = Q.front(); Q.pop();
	
	if ( mode == MODE_BACK ){
	    if ( D[u] >= LIMIT ) return 0;
	} else {
	    if ( GD[u] != 0 ) return GD[u] + D[u];
	    if ( D[u] + LIMIT >= MAX ) return -1;
	}

	for ( int p = 1; p <= 3; p++ ){
	    v = rshift( u, p );
	    if ( mode == MODE_BACK ) v = rshift( v, p );
	    if ( !visited[v] ) {
		visited[v] = true;
		D[v] = D[u] + 1;
		P[v] = u;
		C[v] = p;
		Q.push(v);
	    }
	    v = ushift( u, p );
	    if ( mode == MODE_BACK ) v = ushift( v, p );
	    if ( !visited[v] ) {
		visited[v] = true;
		D[v] = D[u] + 1;
		P[v] = u;
		C[v] = p+3;
		Q.push(v);
	    }
	}
    }
    return -1;
}

void printPathB(int v, map<int, int> &P, map<int, int> &C){
    if ( P[v] == -1 ) return;
    int com = C[v];
    if ( com > 3 ) cout << 'V' << com-3;
    else cout << 'H' << com;

    printPathB(P[v], P, C);

}
void printPathF(int v, map<int, int> &P, map<int, int> &C){
    if ( P[v] == -1 ) return;
    printPathF(P[v], P, C);
    int com = C[v];
    if ( com > 3 ) cout << 'V' << com-3;
    else cout << 'H' << com;
}

int main(){
    int s, x;
    BFS(123456789, GP, GD, GC, MODE_BACK, x);

    while( cin >> x && x){
	int p = 100000000;
	s = x*p;
	p /= 10;
	for ( int i = 1; i < 9; i++ ){
	    cin >> x;
	    s += x*p;
	    p /= 10;
	}
	map<int, int> P, D, C;
	int u;
	int cost = BFS(s, P, D, C, MODE_FORWARD, u);
	if ( s == 123456789 ) cout << "0" << endl;
	else if ( cost == -1 ) cout << "Not solvable" << endl;
	else {
	    cout << cost << " ";
	    printPathF(u, P, C);
	    printPathB(u, GP, GC);
	    cout << endl;
	}
    }

    return 0;
}

