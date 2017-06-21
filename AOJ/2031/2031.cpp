#include<iostream>
#include<string>
#include<map>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++)
#define N 15
#define MAX 1000
string H[N] = {"Rock", "Fire", "Scissors", "Snake", "Human", "Tree", "Wolf", "Sponge", "Paper", "Air", "Water", "Dragon", "Devil", "Lightning", "Gun"};

int G[N][N], n, V[MAX];
map<string, int> M;

void init(){
    rep(i, N) rep(j, N) G[i][j] = 0;
    rep(i, N){
	for( int j = 1; j <= 7; j++ ){
	    G[i][(i+j)%N] = 1;
	}
    }
    rep(i, N) M[H[i]] = i;
}

void simulate(){
    rep(i, n){
	int win = 0, lose = 0;
	rep(j, n){
	    if ( i == j ) continue;
	    if ( G[V[i]][V[j]] ) win++;
	    if ( G[V[j]][V[i]] ) lose++;
	}
	if ( win > 0 && lose == 0 ) {
	    cout << H[V[i]] << endl;
	    return;
	}
    }
    cout << "Draw" << endl;
}

main(){
    init();
    string name;
    while( cin >> n && n ){
	rep(i, n){
	    cin >> name; V[i] = M[name];
	}
	simulate();
    }
}
