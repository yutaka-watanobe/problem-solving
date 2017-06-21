#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<cassert>
#define MAX 4
#define FORWARD 0
#define BACK 1
#define WEST 0
#define EAST 1
using namespace std;

class Station{
    public:
    int nload;
    string loads[MAX];
    Station(){}
    Station( int nload): nload(nload){}

    bool operator < ( const Station &s ) const {
	for ( int i = 0; i < nload; i++ ){
	    if ( loads[i] == s.loads[i] ) continue;
	    return loads[i] < s.loads[i];
	}
	return false;
    }
};

Station initial, goal;
int nload;
bool M[MAX][2][MAX][2]; // graph

map<Station, int> BS; // goal state
map<Station, int> FS; // 

Station getNext(Station v, int d, int s, int sd, int t, int td){
    string left, right;
    left = v.loads[s].substr(0, d);
    right = v.loads[s].substr(d, v.loads[s].size() - d);
    
    if ( sd == WEST ) {
	v.loads[s] = right;
	if ( td == WEST ){
	    reverse( left.begin(), left.end() );
	    v.loads[t] = left + v.loads[t];
	} else {
	    v.loads[t] = v.loads[t] + left;
	}
    } else {
	v.loads[s] = left;
	if ( td == WEST ){
	    v.loads[t] = right + v.loads[t];
	} else {
	    reverse( right.begin(), right.end() );
	    v.loads[t] = v.loads[t] + right;
	}
    }
    return v;
}

int bfs( Station source, map<Station, int> &D, int mode ){
    queue<Station> Q;
    Q.push(source);
    D[source] = 0;

    Station u, v;
    
    while(!Q.empty()){
	u = Q.front(); Q.pop();
	int dist = D[u];

	if ( mode == FORWARD ) { 
	    if ( BS.find(u) != BS.end() ) return BS[u] + dist;
	} else {
	    if ( dist >= 4 ) return 0;
	}

	for ( int l = 0; l < nload; l++ ){
	    if ( u.loads[l] == "" ) continue;
	    for ( int d = 0; d < u.loads[l].size(); d++ ){
		for ( int t = 0; t < nload; t++ ){
		    for ( int sd = 0; sd < 2; sd++ ){
			for ( int td = 0; td < 2; td++ ){
			    if ( M[l][sd][t][td] ){
				v = getNext(u, d, l, sd, t, td );
				if ( D.find(v) == D.end() ){
				    D[v] = dist + 1;
				    Q.push(v);
				}
			    }
			}
		    }
		}
	    }
	}
    }
    //    assert(false);
    return -1;
}

void compute(){
    BS = map<Station, int>();
    FS = map<Station, int>();
    bfs(goal, BS, BACK);
    cout << bfs(initial, FS, FORWARD) << endl;
}

bool input(){
    int y;
    cin >> nload >> y;
    if ( nload == 0 && y == 0 ) return false;

    for ( int i = 0; i < nload; i++ ){
	for ( int j = 0; j < nload; j++ ){
	    M[i][WEST][j][WEST] = false;
	    M[i][WEST][j][EAST] = false;
	    M[i][EAST][j][WEST] = false;
	    M[i][EAST][j][EAST] = false;
	}
    }
    int sl, tl; // source load, target load
    char sd, td; // source direction, target direction
    for ( int i = 0; i < y; i++ ){
	cin >> sl >> sd >> tl >> td;
	M[sl][(sd == 'W' ? WEST : EAST)][tl][(td == 'W' ? WEST : EAST)] = true;
	M[tl][(td == 'W' ? WEST : EAST)][sl][(sd == 'W' ? WEST : EAST)] = true;
    }

    initial = Station(nload);
    goal = Station(nload);
    
    string train;
    for ( int i = 0; i < nload; i++ ) {
	cin >> train; if ( train == "-" ) train = "";
	initial.loads[i] = train;
    }
    for ( int i = 0; i < nload; i++ ) {
	cin >> train; if ( train == "-" ) train = "";
	goal.loads[i] = train;
    }

    return true;
}

main(){
    while( input() ) compute();
}
