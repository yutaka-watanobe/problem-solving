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
    
    int r = 0;
    rep(j, MAX)	{
	bool f = false;
	rep(i, MAX) {
	    if( !place[i] && G[i][j] == '#' ) { f = true; break;}
	}
	if ( f ) r++;
	if ( r > cnt ) return;
    }
    minv = min(minv, cnt );
}

void rec( int p, int cnt ){
    if ( cnt >= minv ) return;
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
    char ch;
    while(1){
	scanf("%c%c%c", &G[0][0], &G[0][1], &G[0][2]);
	if ( G[0][0] == 'E' ) break;
	for ( int j = 3; j < MAX; j++ ) scanf("%c", &G[0][j]);
	scanf("%c", &ch);
	for ( int i = 1; i < MAX; i++ ){
	    rep(j, MAX) scanf("%c", &G[i][j]);
	    scanf("%c", &ch);
	}
	compute();
    }
}
