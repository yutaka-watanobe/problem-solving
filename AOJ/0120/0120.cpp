#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
using namespace std;
#define rep(i, n) for ( int i = 0; i < (int)n; i++)
#define MAX 12
#define INFTY (1<<21)
int W, L[MAX], n;

inline double getL(int r1, int r2){
    return sqrt((r1+r2)*(r1+r2)-(r1-r2)*(r1-r2));
}

void compute(){
    double T[1<<MAX][MAX];
    rep(i, 1<<n) rep(j, n) T[i][j] = INFTY;
    rep(i, n) T[1<<i][i] = L[i]*2;
    rep(i, 1<<n) rep(j, n) rep(l, n){
	if ( (1<<l) & i ) continue;
	T[(1<<l)|i][l] = min(T[(1<<l)|i][l], T[i][j] - L[j] + L[l] + getL(L[j], L[l]));
    }
    double minv = INFTY;
    rep(i, n) minv = min(minv, T[(1<<n)-1][i]);
    if ( minv > W ) cout << "NA" << endl;
    else cout << "OK" << endl;
}

main(){
    string line;
    int l;
    while( getline(cin, line) && !cin.eof() ){
	stringstream sin(line);
	n = 0;
	sin >> W; 
	while( sin >> l ) L[n++] = l;
	compute();
    }
}
