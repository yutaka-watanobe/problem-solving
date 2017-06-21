#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i, n) for ( int i = 0; i < (int)n; i++)
#define NMAX 100
#define MAX 1000000
#define INFTY (1<<21)

void setTable(int maxv, pair<int, int> v[NMAX], int vs,  int T[MAX+1]){
    rep(i, maxv+1) T[i] = INFTY;
    T[0] = 0;
    rep(i, vs){
	for ( int j = 1; j <= v[i].second; j++ ) T[j] = min(T[j], v[i].first);
	for ( int j = v[i].second+1; j <= maxv; j++ ){
	    T[j] = min(T[j], T[j-v[i].second] + v[i].first);
	}
    }
}

main(){
    int n, M[NMAX], TS[MAX+1], TA[MAX+1], ss, as;
    pair<int, int> S[NMAX], A[NMAX];

    string name, type;
    int maxh = 0;
    while( cin >> n && n ){
	ss = as = 0;
	rep(i, n) { cin >> M[i]; maxh = max(maxh, M[i]); }
	int m, cost, damage; 
	cin >> m;
	rep(i, m){
	    cin >> name >> cost >> type >> damage;
	    if ( type == "Single") S[ss++] = make_pair(cost, damage);
	    if ( type == "All") A[as++] = make_pair(cost, damage);
	}
	setTable(maxh, S, ss, TS);
	setTable(maxh, A, as, TA);
	
	int ans = INFTY;
	for( int a = 0; a <= maxh; a++ ){
	    int cost = TA[a];
	    for ( int i = 0; i < n; i++ ){
		int rem = M[i] - a;
		if ( rem <= 0 ) continue;
		cost += TS[rem];
	    }
	    ans = min(ans, cost);
	}
	cout << ans << endl;
    }
}
