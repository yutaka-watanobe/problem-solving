#include<stdio.h>
#include<iostream>
#include<queue>
#include<map>
using namespace std;

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

int lshift(int v, int p ){
    static const int base[4] = {1, 1000, 1000000, 1000000000};
    p = 3 - p + 1;
    long long t, l;
    t = v%base[p] - v%base[p-1];
    v -= t;
    l = t/(base[p]/10);
    t = 10*t%base[p] + l*base[p-1];
    v += t;
    return v;
}

int dshift(int v,  int p ){
  static const int base[4] = {-1, 100000000, 10000000, 1000000};
  int b = base[p];
  int t1, t2, t3;
  t1 = ((v%(b*10))/b)*b; b /= 1000;
  t2 = ((v%(b*10))/b)*b; b /= 1000;
  t3 = ((v%(b*10))/b)*b;b /= 1000;
  v -= (t1 + t2 + t3);
  v += t3*1000000 + (t1+t2)/1000;
  return v;
}
map<int, int> P, D, C;

void init(){
    int g = 123456789;
    queue<int> Q;

    map<int, bool> visited;
    //    visited[g] = true;
    D[g] = 0;
    P[g] = -1;

    Q.push(g);

    int u, v;
    while(!Q.empty()){
	u = Q.front(); Q.pop();
	for ( int p = 1; p <= 3; p++ ){
	    v = lshift( u, p );
	    //	    if ( !visited[v] ) {
	    if ( P[v] == 0 ) {
		//		visited[v] = true;
		D[v] = D[u] + 1;
		P[v] = u;
		C[v] = p;
		Q.push(v);
	    }
	    v = dshift( u, p );
	    //	    if ( !visited[v] ) {
	    if ( P[v] == 0 ) {
		//		visited[v] = true;
		D[v] = D[u] + 1;
		P[v] = u;
		C[v] = p+3;
		Q.push(v);
	    }
	}
    }
}

void printPath(int v){
    if ( P[v] == -1 ) return;
    int com = C[v];
    if ( com > 3 ) cout << 'V' << com-3;
    else cout << 'H' << com;

    printPath(P[v]);

}

int main(){
    init();
    int s, x;

    while(1){
	cin >> x;
	if ( x == 0 ) break;
	int p = 100000000;
	s = 0;
	s += x*p;
	p /= 10;
	for ( int i = 1; i < 9; i++ ){
	    cin >> x;
	    s += x*p;
	    p /= 10;
	}
	int cost = D[s];
	if ( s == 123456789 ) cout << "0" << endl;
	else if ( cost == 0 ) cout << "Not solvable" << endl;
	else {
	    cout << D[s] << " ";
	    printPath(s);
	    cout << endl;
	}
    }

    return 0;
}

