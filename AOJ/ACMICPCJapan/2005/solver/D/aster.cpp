// 3m13sec
#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<cassert>
#define MAX 4
#define LIMIT 6
#define FORWARD 0
#define BACK 1
#define WEST 0
#define EAST 1
#define INFTY (1 << 21)
using namespace std;

class Station{
    public:
    int nload;
    string loads[MAX];
    int prev1, prev2;
    int pred1, pred2;
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

class State{
    public:
	Station station;
    int cost, dist;
    State(){}
    State(Station station, int dist, int cost ): station(station), dist(dist), cost(cost){}

    bool operator < ( const State &s ) const {
	if ( dist == s.dist )
	    return cost > s.cost;
	else 
	    return dist > s.dist;
    }
};

Station initial, goal;
int nload;
bool M[MAX][2][MAX][2]; // original graph
int G[MAX][MAX]; // distance graph

map<Station, int> BS; // goal state
map<Station, int> FS; // 

int func;

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
    func++;
    return v;
}

int getMinDist( char ch, int source, Station target ){
    int mindist = INFTY;
    for ( int t = 0; t < nload; t++ ){
	for ( int c = 0; c < target.loads[t].size(); c++ ){
	    if ( target.loads[t][c] == ch ){
		mindist = min( mindist, G[source][t]);
	    }
	}
    }
    return mindist;
}

// O(100)
int mdmax;

bool check( string source, string target ){
    for ( int i = 0; i < source.size(); i++ ){
	for ( int j = 0; j < target.size(); j++ ){
	    if ( source[i] == target[j] ) goto next;
	}
	return true;
	next:;
    }
    return false;
}

int getMD( Station source, Station target ){
    int MD = 0;
    /*
    for ( int s = 0; s < nload; s++ ){
	int maxcost = 0;
	for ( int c = 0; c < source.loads[s].size(); c++ ){
	    maxcost = max( maxcost, getMinDist( source.loads[s][c], s, target ) );
	}
	MD += maxcost;
    }
    //    cout << "MD = " << MD << endl;
    */
    for ( int l = 0; l < nload; l++ ){
	if ( check( source.loads[l], target.loads[l] ) ) MD++;
    }



    mdmax = max( mdmax, MD );
    return MD;
}
int cut, fc;

int bfs( Station source, map<Station, int> &D, int mode ){
    priority_queue<State> PQ;
    
    PQ.push(State(source, 0, 0));
    D[source] = 0;

    Station u, v;
    State st;

    while(!PQ.empty()){
	st = PQ.top(); PQ.pop();
	u = st.station;
	int dist = D[u];

	/*
	if ( mode == FORWARD ) { 
	    if ( BS.find(u) != BS.end() ) return BS[u] + dist;
	} else {
	    if ( dist > 3 ) return 0;
	    }*/

	if ( mode == BACK && dist >= 3 ) return 0;

	for ( int l = 0; l < nload; l++ ){
	    for ( int d = 0; d < u.loads[l].size(); d++ ){
		for ( int t = 0; t < nload; t++ ){
		    for ( int sd = 0; sd < 2; sd++ ){
			for ( int td = 0; td < 2; td++ ){
			    if ( u.prev1 == l && u.pred1 == sd && u.prev2 == t && u.pred2 == td ||
				 u.prev1 == t && u.pred1 == td && u.prev2 == l && u.pred2 == sd ) continue;

			    if ( M[l][sd][t][td] ){
				v = getNext(u, d, l, sd, t, td );
				v.prev1 = l;
				v.pred1 = sd;
				v.prev2 = t;
				v.pred2 = td;
				if ( D.find(v) == D.end() ){
				    D[v] = dist + 1;
				    if ( mode == FORWARD ){
					if ( BS.find(v) != BS.end() ) return BS[v] + dist + 1;
				    } 

				    int md = getMD(v, (mode == FORWARD ? goal : initial));
				    if ( (dist + 1) + md <= LIMIT) {
					if ( mode == FORWARD ) PQ.push(State(v, dist + 1, dist+ 1 + md));
					else PQ.push( State(v, dist+1, 0 ));
				    } else {
					cut++;
				    }
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
    /*
    for ( int i = 0; i < nload; i++ ){
	for ( int j = 0; j < nload; j++ ){
	    if ( G[i][j] == INFTY ) cout << " M";
	    else cout << " " << G[i][j];
	}
	cout << endl;
    }
	cout << endl;
    */
    func = 0;
    cut = 0;
    mdmax = 0;
    BS = map<Station, int>();
    FS = map<Station, int>();
    bfs(goal, BS, BACK);
    cout << "size = " << BS.size() << endl;
    cout << "cut = " << cut << endl;
    cout << "mdm = " << mdmax << endl;
    cut = 0;
    mdmax = 0;
    cout << bfs(initial, FS, FORWARD) << endl;
    cout << "size = " << FS.size() << endl;
    cout << "cut = " << cut << endl;
    cout << "mdm = " << mdmax << endl;
    cout << "func = " << func << endl;
    cout << endl;
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
	    G[i][j] = (i == j) ? 0 : INFTY;
	}
    }
    int sl, tl; // source load, target load
    char sd, td; // source direction, target direction
    for ( int i = 0; i < y; i++ ){
	cin >> sl >> sd >> tl >> td;
	M[sl][(sd == 'W' ? WEST : EAST)][tl][(td == 'W' ? WEST : EAST)] = true;
	M[tl][(td == 'W' ? WEST : EAST)][sl][(sd == 'W' ? WEST : EAST)] = true;
	G[sl][tl] = G[tl][sl] = 1;
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

    // create distance graph
    for ( int k = 0; k < nload; k++ ){
	for ( int i = 0; i < nload; i++ ){
	    for ( int j = 0; j < nload; j++ ) {
		G[i][j] = min( G[i][j], G[i][k] + G[k][j] );
	    }
	}
    }

    return true;
}

main(){
    while( input() ) compute();
}
