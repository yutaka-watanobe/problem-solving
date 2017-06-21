#include<iostream>
#include<string>
using namespace std;
#define MAX 105
#define ERROR "ERROR"
char G[MAX][MAX];
int px, py;

void init(){
    for ( int y = 0; y < MAX; y++ )
	for ( int x = 0; x < MAX; x++ ) G[y][x] = ' ';
    for ( int x = 0; x < MAX; x++ ) G[0][x] = 'X';
}

bool F(){
    if ( G[py][px] == ' ' ) return false;
    px++;
    return true;
}

bool B(){
    if ( G[py][px-1] == ' ' ) return false;
    px--;
    return true;
}

bool P(){
    if ( G[py+1][px] == ' '){
	char l = G[py+1][px-1];
	if ( l == ' ' ) return false;
    }
    py++;
    return true;
}

bool N(){
    if ( py == 1 ) return false;
    if ( G[py-1][px] == ' ' ){
	char l = G[py-1][px-1];
	if ( l == ' ' ) return false;
    }
    py--;
    return true;
}

bool D(){
    if ( G[py][px] == ' ' ) return false;
    G[py][px] = ' ';
    int ry = py;
    int rx = px;
    while( G[ry][rx+1] != ' '){
	G[ry][rx] = G[ry][rx+1];
	G[ry][rx+1] = ' ';
	rx++;
    }
    if ( G[py][px] == ' ' && G[py][px-1] == ' '){
	py--;
	if ( py == 0 ) return false;
	if ( G[py][px] == ' ' && G[py][px-1] == ' '){
	    return false;
	}
    }
    return true;
}

bool C(){
    if ( G[py][px] == ' ') return false;
    if ( G[py+1][px] != ' ' ) return false;
    G[py+1][px] = G[py][px];
    py++; px++;
    return true;
}

void insert(char ch){
    int wx = px;
    while(G[py][wx] != ' ') wx++;
    for ( int x = wx; x >= px+1; x--) G[py][x] = G[py][x-1];
    G[py][px++] = ch;
}

bool fall(){
    for ( int y = 2; y < MAX; y++ ){
	for ( int x = 1; x < MAX; x++ ){
	    if ( G[y][x] == ' ') continue;
	    int sx = x;
	    int ex = x;
	    while( G[y][ex+1] != ' ') ex++;
	    int ty = y;
	    bool hasc = false;
	    for ( int i = sx; i <= ex; i++ ) if ( py == y && (px == i || px == i+1)) hasc = true;
	    while(1){
		bool empty = true;
		for ( int i = sx; i <= ex; i++ ) if ( G[ty-1][i] != ' ' ) empty = false;
		if ( empty ) ty--;
		else break;
	    }
	    if ( ty < y ){
		for ( int i = sx; i <= ex; i++ ){
		    G[ty][i] = G[y][i]; G[y][i] = ' ';
		}
		if ( hasc ) py = ty;
		return true;
	    }
	    x = ex;
	}
    }
    return false;
}

string simulate(){
    string str; cin >> str;
    init();
    py = px = 1;
    G[py][px++] = str[0];
    for ( int i = 1; i < str.size(); i++ ){
	char ch = str[i];
	if ( ch == 'F' ) {
	    if ( !F() ) return ERROR;
	} else if ( ch == 'B' ){
	    if ( !B() ) return ERROR;
	} else if ( ch == 'P' ){
	    if ( !P() ) return ERROR;
	} else if ( ch == 'N' ){
	    if ( !N() ) return ERROR;
	} else if ( ch == 'D' ){
	    if ( !D() ) return ERROR;
	    while(fall());
	} else if ( ch == 'C' ){
	    if ( !C() ) return ERROR;
	} else {
	    insert(ch);
	}
    }
    string ans = "";
    int p = px-1;
    while( G[py][p] != ' '){ ans = G[py][p] + ans; p--; }
    p = px;
    while( G[py][p] != ' '){ ans = ans + G[py][p]; p++; }

    return ans;
}

main(){
    int n; cin >> n;
    for ( int i = 0; i < n; i++ ) cout << simulate() << endl;
}
