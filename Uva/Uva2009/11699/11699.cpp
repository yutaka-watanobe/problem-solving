#include<iostream>
#include<string>
#define MAX 15
#define rep(i, n) for ( int i = 0; i < n; i++ )
using namespace std;

char G[MAX][MAX];
bool place[MAX];
int minv;

void update(int cnt){
    if ( cnt >= minv ) return;
    char C[MAX][MAX];
    rep(i, MAX)	rep(j, MAX) C[i][j] = (place[i]) ? '.': G[i][j];
    int r = 0;
    rep(j, MAX){
	int h = 0;
	rep(i, MAX) if ( C[i][j] == '#' ){ h++; break;}
	if ( h ) r++;
	if ( r > cnt ) return;
    }

    minv = min(minv, cnt );
}

void rec( int p, int cnt ){
    if ( p == MAX ){ update(cnt); return; }

    rec(p+1, cnt);
    place[p] = true;
    rec(p+1, cnt+1);
    place[p] = false;
}

void compute(){
    minv = (1<<21);
    rep(i, MAX) place[i] = false;
    rec(0, 0);
    cout << minv << endl;
}

main(){
    string line;
    while(1){
	cin >> line;
	if ( line == "END" ) break;
	rep(j, MAX) G[0][j] = line[j];
	for ( int i = 1; i < MAX; i++ ){
	    cin >> line;
	    rep(j, MAX) G[i][j] = line[j];
	}
	compute();
    }
}
