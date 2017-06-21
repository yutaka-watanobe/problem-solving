#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<cassert>
#define NMAX 30
#define MMAX 20

using namespace std;

int N, M;

bool L[MMAX][NMAX]; // i can speal j
map<string, int> LI; // language to id
string IL[NMAX];
//vector<vector<int>  > ans;
vector<int> ans;
int visn;
bool V[MMAX];

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

void recursive( int pos, int cnt, bool use[NMAX] ){

    if ( cnt >= ans.size() ) return;

    if ( check( use ) ){
	if ( cnt < ans.size() ){
	    ans.clear();
	    for ( int i = 0; i < N; i++ ){
		if ( use[i] ) ans.push_back(i);
	    }
	}
	return;
    }

    if ( pos >= N ) return;    

    // not use;
    recursive( pos+1, cnt, use );  

    // use;
    use[pos] = true;
    recursive( pos+1, cnt+1, use);
    use[pos] = false;
}

void compute(){
    ans.clear();
    for ( int i = 0; i < 6; i++ ) ans.push_back(-1);
    bool use[NMAX];
    for ( int i = 0; i < N; i++ ) use[i] = false;
    recursive(0, 0, use);
    
    if ( ans.size() == 6 ) cout << "Impossible" << endl;
    else {
	cout << ans.size() << endl;
	for ( int i = 0; i < ans.size(); i++ ){
	    cout << IL[ans[i]] << endl;
	}
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
	    }
	}
	if ( tcase++ ) cout << endl;
	compute();
    }
    return 0;
}
