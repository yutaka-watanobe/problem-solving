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
#define INFTY (1 << 21)
using namespace std;

class Station{
    public:
	int nload;
    int prev1, prev2;
    int pred1, pred2;
    string loads[MAX];
    int C[4][2];
    int A[4][26]; // number of alpha
    int id;
    
    Station(){}
    Station( int nload): nload(nload){
	prev1 = prev2 = pred1 = pred2 = -1;
	id = 0;
	for ( int i = 0; i < nload; i++ ){
	    for ( int j = 0; j < 2; j++ ) C[i][j] = id++;
	}
    }

    void minus( int t, string str ){
	for ( int i = 0; i < str.size(); i++ ) A[t][str[i] - 'a']--;
    }

    void plus( int t, string str ){
	for ( int i = 0; i < str.size(); i++ ) A[t][str[i] - 'a']++;
    }

    void init(){
	for ( int i = 0; i < nload; i++ ){
	    for ( int a = 0; a < 26; a++ ) A[i][a] = 0;
	}
	for ( int i = 0; i < nload; i++ ){
	    for ( int j = 0; j < loads[i].size(); j++ ){
		A[i][loads[i][j] - 'a']++;
	    }
	}
    }

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

    void print(){
	for ( int i = 0; i < nload; i++ ){
	    cout << loads[i] << endl;
	}
	cout << "-------------------" << endl;
    }
};


Station initial, goal;
int nload;
bool M[MAX][2][MAX][2]; // original graph
int G[MAX][MAX]; // distance graph

map<Station, int> BS; // goal state
map<Station, int> FS; // 

int func;

Station getNext2(Station v, int d, int s, int sd, int t, int td){
    string left, right;
    left = v.loads[s].substr(0, d);
    right = v.loads[s].substr(d, v.loads[s].size() - d);
    
    if ( sd == WEST ) {
	v.minus(s, left);
	v.plus(t, left);
	v.loads[s] = right;
	if ( td == WEST ){
	    reverse( left.begin(), left.end() );
	    v.loads[t] = left + v.loads[t];
	} else {
	    v.loads[t] = v.loads[t] + left;
	}
    } else {
	v.minus(s, right);
	v.plus(t, right);
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

// vÇÃèÛë‘Ç©ÇÁÅAÇìÇÃï∂éöóÒÇÃÇìÇÑë§Ç©ÇÁÇîÇÃï∂éöóÒÇÃÇîÇÑë§Ç÷à⁄ìÆ
Station getNext(Station v, int d, int s, int sd, int t, int td){
    int tail, nd;
    if ( sd == WEST ){
	if ( td == WEST ){
	    for ( int i = 0; i < d; i++  ){
		v.A[t][v.loads[s][0]-'a']++; 
		v.loads[t] = v.loads[s][0] + v.loads[t]; 
		v.A[s][v.loads[s][0]-'a']--;
		v.loads[s].erase(v.loads[s].begin());
	    }
	} else { // td == EAST
	    for ( int i = 0; i < d; i++  ){
		v.A[t][v.loads[s][0]-'a']++; 
		v.loads[t] += v.loads[s][0]; 
		v.A[s][v.loads[s][0]-'a']--;
		v.loads[s].erase(v.loads[s].begin());
	    }
	}
    } else { // sd == EAST
	if ( td == WEST ){
	    nd = v.loads[s].size()-d;
	    for ( int i = 0; i < nd; i++ ){
		tail = v.loads[s].size()-1;
		v.A[t][v.loads[s][tail]-'a']++; 
		v.loads[t] = v.loads[s][tail] + v.loads[t];  
		v.A[s][v.loads[s][tail]-'a']--;
		v.loads[s].erase(v.loads[s].begin() + tail); 
	    }
	    v.loads[s] = v.loads[s].substr(0, d);
	} else { // td == EAST
	    nd = v.loads[s].size()-d;
	    for ( int i = 0; i < nd; i++ ){
		tail = v.loads[s].size()-1;
		v.A[t][v.loads[s][tail]-'a']++; 
		v.loads[t] += v.loads[s][tail]; 
		v.A[s][v.loads[s][tail]-'a']--;
		v.loads[s].erase(v.loads[s].begin() + tail);
	    }
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

int getMDBA( Station source, Station target ){
    int md = 0;
    for ( int i = 0; i < nload; i++ ){
	int has = true;
	for ( int j = 0; j < target.loads[i].size(); j++  ){
	    if ( source.A[i][target.loads[i][j] - 'a'] == 0 ) has = false;
	}
	if ( !has ) md++;
    }
    mdmax = max( mdmax, md );
    return md;
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
    mdmax = max( mdmax, md );
    */

    for ( int l = 0; l < nload; l++ ){
	if ( check( source.loads[l], target.loads[l] ) ) MD++;
    }


    mdmax = max( mdmax, MD );
    return MD;
}
int cut;

int op( int x ){
    if ( x == 0 ) return 1;
    return 0;
}
int bfs( Station source, map<Station, int> &D, int mode ){
    queue<Station> Q;
    Q.push(source);
    D[source] = 0;

    Station u, v;
    

    while(!Q.empty()){
	u = Q.front(); Q.pop();
	int dist = D[u];

	//	u.print();

	/*
	if ( mode == FORWARD ) { 
	    if ( BS.find(u) != BS.end() ) return BS[u] + dist;
	    if ( dist >= 3 ) continue;
	} else {
	    if ( dist >= 3 ) return 0;
	    }*/

	if ( mode == BACK ){
	    if ( dist >= 3 ) return INT_MAX;
	    if ( u == initial ) return D[u];
	}
	


	for ( int s = 0; s < nload; s++ ){
	    for ( int d = 0; d < u.loads[s].size(); d++ ){
		for ( int t = 0; t < nload; t++ ){
		    for ( int sd = 0; sd < 2; sd++ ){
			for ( int td = 0; td < 2; td++ ){
			    //if ( u.prev1 == s && u.pred1 == sd && u.prev2 == t && u.pred2 == td ||
			    //u.prev1 == t && u.pred1 == td && u.prev2 == s && u.pred2 == sd ) continue;
			    
			    if ( u.C[s][sd] == u.C[t][td] &&
				 (u.C[s][sd] > u.C[s][op(sd)] || u.C[t][td] > u.C[t][op(td)] ) ) continue;

			    if ( M[s][sd][t][td] ){
				v = getNext2(u, d, s, sd, t, td );
				//								v.prev1 = s;
				//								v.pred1 = sd;
				//								v.prev2 = t;
				//								v.pred2 = td;

				v.C[s][sd] = v.id;
				v.C[t][td] = v.id++;
				
				if ( D.find(v) == D.end() ){
				    D[v] = dist + 1;
				    if ( mode == FORWARD ){
					if ( BS.find(v) != BS.end() ) return BS[v] + dist + 1;
				    } 
				    //				    Q.push(v);
				    if ( (dist + 1) + getMDBA(v, (mode == FORWARD ? goal : initial)) <= LIMIT ){
					Q.push(v);
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
    int cost = bfs(goal, BS, BACK);
    if ( cost != INT_MAX ){
	cout << cost << endl;
	return;
    }
        cout << "size = " << BS.size() << endl;
        cout << "cut = " << cut << endl;
        cout << "mdm = " << mdmax << endl;
        cout << "func = " << func << endl;
    func = 0;
    cut = 0;
    mdmax = 0;
    cout << bfs(initial, FS, FORWARD) << endl;
        cout << "size = " << FS.size() << endl;
        cout << "cut = " << cut << endl;
        cout << "mdm = " << mdmax << endl;
        cout << "func = " << func << endl;
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

        initial.init();
        goal.init();

    return true;
}

main(){
    while( input() ) compute();
}
