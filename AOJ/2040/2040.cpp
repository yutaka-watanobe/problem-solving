#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
#include<set>
#include<map>
using namespace std;
typedef unsigned short ushort;

class QState{
    public:
    int cur, str, cost;
    QState(){}
    QState(int cur, int str, int c):cur(cur), str(str), cost(c){}
    bool operator < ( const QState &q ) const{ return cost > q.cost; }
};

ushort T[16];

int dist(int i, int j){
    return max(i, j) - min(i, j);
}	    

int dijkstra(int n, ushort start, ushort goal){
    priority_queue<QState> PQ;
    ushort d[n][(1<<n)];

    for ( int i = 0; i < n; i++ ){
	for ( int j = 0; j < (1<<n); j++ ){
	    d[i][j] = 10000;
	}
    }

    for ( int i = 0; i < n; i++ ) {
	d[i][start] = 0;
	PQ.push(QState(i, start, 0));
    }

    QState u;
    while( !PQ.empty() ){
	u = PQ.top(); PQ.pop();
	if ( u.str == goal ) return u.cost;

	for ( int i = 0; i < n; i++ ){
	    for  ( int j = 0; j < n; j++ ){
		int nstr = u.str;
		int ncur = u.cur;
		ushort p1 = (nstr & T[i]);
		ushort p2 = (nstr & T[j]);
		
		if ( p1 > 0 && p2 == 0 ){
		    nstr -= p1;
		    nstr += T[j];
		} else if ( p1 == 0 && p2 > 0 ){
		    nstr -= p2;
		    nstr += T[i];
		} else continue;

		ncur = j;

		int ncost = u.cost + dist(u.cur, i) + dist(i, j);

		if ( ncost < d[ncur][nstr] ){
		    d[ncur][nstr] = ncost;
		    PQ.push(QState(ncur, nstr, ncost));
		}
	    }
	}
    }
}

main(){
    int n;
    string s, g;

    for ( int i = 0; i < 16; i++ ) T[i] = (1<<i);
    while( cin >> n && n ){
	cin >> s >> g;
	ushort si = 0, gi = 0;
	ushort p = 1;
	for ( int i = n-1; i >= 0; i--, p *= 2){
	    if ( s[i] == 'B' ) si += p;
	    if ( g[i] == 'B' ) gi += p;
	}
	cout << dijkstra(n, si, gi) << endl;
    }
}
