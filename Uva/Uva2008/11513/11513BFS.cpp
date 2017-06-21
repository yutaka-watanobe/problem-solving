#include<stdio.h>
#include<iostream>
#include<queue>
#include<map>
using namespace std;

class State{
    public:
    int d, p, c;
    State(){ p = 0; d = 0; c = 0;}
    State( int d, int p, int c ): d(d), p(p), c(c){}
};

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
map<int, State> S;

void init(){
    int g = 123456789;
    queue<int> Q;

    map<int, bool> visited;
    //    visited[g] = true;
    S[g].d = 0;
    S[g].p = -1;

    Q.push(g);

    int u, v;
    while(!Q.empty()){
	u = Q.front(); Q.pop();
	for ( int p = 1; p <= 3; p++ ){
	    v = lshift( u, p );
	    if ( S[v].p == 0 ) {
		S[v] = State(S[u].d+1, u, p);
		Q.push(v);
	    }
	    v = dshift( u, p );
	    if ( S[v].p == 0 ) {
		S[v] = State(S[u].d+1, u, p+3);
		Q.push(v);
	    }
	}
    }
}

void printPath(int v){
    if ( S[v].p == -1 ) return;
    int com = S[v].c;
    if ( com > 3 ) cout << 'V' << com-3;
    else cout << 'H' << com;

    printPath(S[v].p);

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
	int cost = S[s].d;
	if ( s == 123456789 ) cout << "0" << endl;
	else if ( cost == 0 ) cout << "Not solvable" << endl;
	else {
	    cout << S[s].d << " ";
	    printPath(s);
	    cout << endl;
	}
    }

    return 0;
}

