// Floyd + DP
// 陸路のみ
// 陸路>海路>陸路
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
#define rep(i, n) for ( int i = 0; i < (int)n; i++)
#define MAX 200
#define INFTY (1<<21)

int N, M, R, L[MAX][MAX], S[MAX][MAX];
vector<int> O;

void floyd(int D[MAX][MAX], int n){
    rep(k, n) rep(i, n){
	if ( D[i][k] == INFTY ) continue;
	rep(j, n){
	    if ( D[k][j] == INFTY ) continue;
	    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
	}
    }
}

int compute(){
    floyd(L, N);
    floyd(S, N);
    int T[1000][MAX];
    rep(i, O.size()) rep(j, N) T[i][j] = INFTY;
    
    T[0][O[0]] = 0;

    for ( int i = 1; i < R; i++ ){
	for ( int j = 0; j < N; j++ ){
	    T[i][j] = min(T[i][j], T[i-1][j] + L[O[i-1]][O[i]]);
	    for ( int k = 0; k < N; k++ ){
		T[i][k] = min(T[i][k], T[i-1][j] + L[O[i-1]][j] + S[j][k] + L[k][O[i]]);
	    }

	}
    }

    int minv = INFTY;
    rep(i, N) minv = min(minv, T[O.size()-1][i]);
    return minv;

}

main(){
    int s, t, c;
    char ch;
    while(cin >> N >> M && N ){
	O.clear();
	rep(i, N) rep(j, N) L[i][j] = S[i][j] = INFTY;
	rep(i, N) L[i][i] = S[i][i] = 0;
	rep(i, M){
	    scanf("%d %d %d", &s, &t, &c); cin >> ch;
	    s--; t--;
	    if ( ch == 'L' ) L[s][t] = L[t][s] = min(L[s][t], c);
	    else S[s][t] = S[t][s] = min(S[s][t], c);
	}
	cin >> R;
	rep(i, R){
	    cin >> s; s--;
	    O.push_back(s);
	}
	cout << compute() << endl;
    }
}
