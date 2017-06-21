// 2m50sec

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
#define BUFFER 80

using namespace std;

class Load{
    public:
    char buffer[BUFFER];

    int head, tail;
    Load(){}
    Load( string str ){
	head = tail = BUFFER/2;
	for ( int i = 0; i < str.size(); i++ ){
	    buffer[tail++] = str[i];
	}
    }
    
    void intoW( char ch ){
	buffer[--head] = ch;
    }

    void intoE( char ch ){
	buffer[tail++] = ch;
    }

    char fromW(){
	char ch = buffer[head];
	head++;
	return ch;
    }

    char fromE(){
	char ch = buffer[tail-1];
	tail--;
	return ch;
    }

    int size(){
	return tail - head;
    }

    bool operator < ( const Load &l ) const {
	if ( (tail - head) != l.tail - l.head ) return tail - head < l.tail - l.head;
	for ( int i = head, j = l.head; i < tail; i++, j++ ){
	    if ( buffer[i] == l.buffer[j] ) continue;
	    return buffer[i] < l.buffer[j];
	}
	return false;
    }

    bool operator == ( const Load &l ) const {
	if ( tail - head != l.tail - l.head ) return false;
	for ( int i = head, j = l.head; i < tail; i++, j++ ){
	    if ( buffer[i] != l.buffer[j] ) return false;
	}
	return true;
    }

    bool operator != ( const Load &l ) const {
	if ( tail - head != l.tail - l.head ) return true;
	for ( int i = head, j = l.head; i < tail; i++, j++ ){
	    if ( buffer[i] != l.buffer[j] ) return true;
	}
	return false;
    }
};

class Station{
    public:
    int nload;
    Load loads[MAX];
    int id;
    
    Station(){}
    Station( int nload): nload(nload){}

    bool operator < ( const Station &s ) const {
	for ( int i = 0; i < nload; i++ ){
	    if ( loads[i] == s.loads[i] ) continue;
	    return loads[i] < s.loads[i];
	}
	return false;
    }
    
    bool operator == ( const Station &s ) const {
	for ( int i = 0; i < nload; i++ ){
	    if ( loads[i] != s.loads[i] ) return false;
	}
	return true;
    }
};


Station initial, goal;
int nload;
bool M[MAX][2][MAX][2]; // original graph
int G[MAX][MAX]; // distance graph

map<Station, int> BS; // goal state
map<Station, int> FS; // 

int func;

// v‚Ìó‘Ô‚©‚çA‚“‚Ì•¶š—ñ‚Ì‚“‚„‘¤‚©‚ç‚”‚Ì•¶š—ñ‚Ì‚”‚„‘¤‚ÖˆÚ“®
Station getNext(Station v, int d, int s, int sd, int t, int td){
    int nd;

    if ( sd == WEST ){
	if ( td == WEST ){
	    for ( int i = 0; i < d; i++  ){
		v.loads[t].intoW(v.loads[s].fromW());
	    }
	} else { // td == EAST
	    for ( int i = 0; i < d; i++  ){
		v.loads[t].intoE(v.loads[s].fromW());
	    }
	}
    } else { // sd == EAST
	if ( td == WEST ){
	    nd = v.loads[s].size() - d;
	    for ( int i = 0; i < nd; i++ ){
		v.loads[t].intoW(v.loads[s].fromE());
	    }
	} else { // td == EAST
	    nd = v.loads[s].size()-d;
	    for ( int i = 0; i < nd; i++ ){
		v.loads[t].intoE(v.loads[s].fromE());
	    }
	}
    }
    //    func++;
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
	    if ( dist >= 3 ) continue;
	} else {
	    if ( dist >= 3 ) return 0;
	}

	for ( int s = 0; s < nload; s++ ){
	    for ( int d = 0; d < u.loads[s].size(); d++ ){
		for ( int t = 0; t < nload; t++ ){
		    for ( int sd = 0; sd < 2; sd++ ){
			for ( int td = 0; td < 2; td++ ){
			    if ( M[s][sd][t][td] ){
				v = getNext(u, d, s, sd, t, td );
				
				if ( D.find(v) == D.end() ){
				    D[v] = dist + 1;
				    if ( mode == FORWARD ){
					if ( BS.find(v) != BS.end() ) return BS[v] + dist + 1;
				    } 
				    Q.push(v);
				}
			    }
			}
		    }
		}
	    }
	}
    }
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
	initial.loads[i] = Load(train);
    }
    for ( int i = 0; i < nload; i++ ) {
	cin >> train; if ( train == "-" ) train = "";
	goal.loads[i] = Load(train);
    }

    return true;
}

main(){
    while( input() ) compute();
}
