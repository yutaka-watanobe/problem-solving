#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<cassert>
#define NMAX 30
#define MMAX 20
#define SMAX 20


using namespace std;

class DisjointSet{
    public:
    DisjointSet(){}
    DisjointSet( int s ){
		size = s;
		//        rank.resize( size, 0 );
		//	        p.resize( size, 0 );
    }
    
    void makeSet( int x ){
        p[x] = x;
        rank[x] = 0;
    }
    
    void unionNode( int x, int y ){
	link( findSet(x), findSet(y) );
    }
    
    int findSet( int x ){
        if ( x != p[x] ) p[x] = findSet( p[x] );
        return p[x];
    }
    
    bool isSameSet( int x, int y ){
        return ( findSet(x) == findSet(y) );
    }
    
    private:
    	int size;
    //    vector<int> rank, p;
        int rank[SMAX], p[SMAX];
    
    void link ( int x, int y ){
        if ( rank[x] > rank[y] ){
            p[y] = x;
        } else {
            p[x] = y;
            if ( rank[x] == rank[y] ) rank[y]++;
        }
    }
};

int N, M;

bool L[MMAX][NMAX]; // i can speal j
map<string, int> LI; // language to id
string IL[NMAX];
vector<int> slist[NMAX];

//vector<vector<int>  > ans;
vector<vector<int> > ans;
int visn;
bool V[MMAX];

DisjointSet ds;

void dfs( int u, bool use[NMAX] ){
    visn++;
    V[u] = true;
    for ( int v = 0; v < M; v++ ){
	if ( V[v] ) continue;
	for ( int i = 0; i < N; i++ ){
	    if ( !use[i] ) continue;
	    if ( L[u][i] && L[v][i] ){
		dfs( v, use );
		i = N;
	    }
	}
    }
}

bool check(bool use[NMAX] ){
    for ( int i = 0; i < M; i++ ) V[i] = false;
    visn = 0;
    dfs( 0, use);
    return visn == M;
}

void recursive( int pos, int cnt, bool use[NMAX], DisjointSet ds, int nedge ){
    if ( cnt > 5 ) return;
    if ( cnt > ans[0].size() ) return;


    //    if ( check( use ) ){
    if ( nedge + 1 == M ){
	vector<int> va;
	for ( int i = 0; i < N; i++ ){
	    if ( use[i] ) va.push_back(i);
	}

	if ( cnt == ans[0].size() ){
	    ans.push_back(va);
	}else if ( cnt < ans[0].size() ){
	    ans.clear();
	    ans.push_back(va);
	}
	/*
	if ( ans.size() == 0 || ans.size()>0 && cnt < ans[0].size() ){
	    ans.clear();
	    ans.push_back(va);
	} else if ( cnt == ans[0].size()  ){
	    ans.push_back(va);
	    }*/

		return;
    }

    if ( pos >= N ) return;    

    // not use;
    recursive( pos+1, cnt, use, ds, nedge );  

    // use;
    DisjointSet vds = ds;
    int vnedge = nedge;
    for ( int i = 0; i < slist[pos].size()-1; i++ ){
      for ( int j = i+1; j < slist[pos].size(); j++ ){
	int s1 = slist[pos][i];
	int s2 = slist[pos][j];
	if ( vds.findSet(s1) == vds.findSet(s2) ) continue;
	vds.unionNode(s1, s2);
	vnedge++;
      }
    }

    use[pos] = true;
    recursive( pos+1, cnt+1, use, vds, vnedge);
    use[pos] = false;
}

void compute(){
    ans.clear();

    vector<int> x; for ( int i = 0; i < 6; i++ ) x.push_back(-1);
    ans.push_back(x);
    //    for ( int i = 0; i < 6; i++ ) ans.push_back(-1);
    bool use[NMAX];
    for ( int i = 0; i < N; i++ ) use[i] = false;
    
    ds = DisjointSet(M);
    for ( int i = 0; i < M; i++ ) ds.makeSet(i);
    recursive(0, 0, use, ds, 0);
    

    if ( ans[0].size() > 5 ) cout << "Impossible" << endl;
    else {
	int s = ans.size();
	int p = 3;
	cout << ans[p%s].size() << endl;
	for ( int i = 0; i < ans[p%s].size(); i++ ){
	    cout << IL[ans[p%s][i]] << endl;
	}


	/*
	// all
	cout << ans.size() << " " << ans[0].size() << endl;
	for ( int i = 0; i < ans.size(); i++ ){
	    vector<int> va = ans[i];
	    for ( int j = 0; j < va.size(); j++ ) cout << IL[va[j]] << " ";
	    cout << endl;
	    }*/
    }
    
}

int main(){
    string lang;
    int tcase = 0;
    while(1){
	cin >> N >> M;
	if ( N == 0 && M == 0 ) break;
	LI = map<string, int>();
	for ( int i = 0; i < N; i++ ){
	    cin >> lang;
	    LI[lang] = i;
	    IL[i] = lang;
	    slist[i].clear();
	}

	for ( int i = 0; i < M ; i++ ){
	    for ( int j = 0; j < N; j++ ) L[i][j] = false;
	}

	int k;
	for ( int i = 0; i < M; i++ ){
	    cin >> k;
	    for ( int l = 0; l < k; l++ ){
		cin >> lang;
		L[i][LI[lang]] = true;
		slist[LI[lang]].push_back(i);
	    }
	}
	if ( tcase++ ) cout << endl;
	compute();
    }
    return 0;
}
