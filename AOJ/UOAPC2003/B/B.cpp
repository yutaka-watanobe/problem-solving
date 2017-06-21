#include<iostream>
#include<string>
#include<cassert>
#include<map>
#include<algorithm>
using namespace std;
#define REP(i, n) for ( int i = 0; i < n; i++ )
#define MAX 7
int n;

int D[MAX], M[MAX][MAX];
bool A[MAX], V[MAX];

void dfs(int u){
    V[u] = true;
    for ( int v = 0; v < MAX; v++ ){
	if ( M[u][v] && A[v] && !V[v] ) dfs(v);
    }
}

bool connected(){
    REP(i, MAX){
	if ( A[i] ){
	    REP(j, MAX) V[j]= false;
	    dfs(i);
	    break;
	}
    }
    REP(i, MAX ){
	if ( A[i] && !V[i] ) return false;
    }
    return true;
}

int main(){
    string st;
    while( cin >> n ){
	REP(i, MAX) D[i] = 0;
	REP(i, MAX) REP(j, MAX) M[i][j] = 0;
	REP(i, MAX) A[i] = false;

	map<string, bool> used = map<string, bool>();
	for ( int i = 0; i < n; i++ ){
	    cin >> st;
	    assert( st[0] <= st[1] );
	    sort( st.begin(), st.end());
	    assert( !used[st] );
	    used[st] = true;
	    D[st[0]-'0']++;
	    D[st[1]-'0']++;
	    M[st[0]-'0'][st[1]-'0'] = M[st[1]-'0'][st[0]-'0'] = 1;
	    A[st[0]-'0'] = A[st[1]-'0'] = true;
	}
	int nodd = 0;
	for ( int i = 0; i < MAX; i++ ){
	    if ( D[i] % 2 != 0 ) nodd++;
	}
	if ( (nodd == 2 || nodd == 0 ) && connected() ) cout << "Yes" << endl;
	else cout << "No" << endl;
    }

    return 0;
}
