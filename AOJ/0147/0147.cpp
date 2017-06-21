#include<iostream>
#include<queue>
using namespace std;
#define NSEAT 17
#define MAX 100
#define EMPTY (-1)
int S[NSEAT], in[MAX], ans[MAX];
queue<int> Q;

void insertSeat(int t){
    int u, w, st;
    while(!Q.empty()){
	u = Q.front();
	w = ((u%5==1)? 5 : 2);
	st = -1;
	for ( int s = NSEAT-w; s >= 0; s-- ){
	    bool em = true;
	    for ( int j = s; j < s + w; j++ ) if ( S[j] != EMPTY ) em = false;
	    if ( em ) st = s;
	}

	if ( st < 0 ) return;
	Q.pop();
	in[u] = t;
	ans[u] = t - u*5;
	for ( int i = st; i < st + w; i++ ) S[i] = u;
    }
}

main(){
    for ( int i = 0; i < NSEAT; i++ ) S[i] = EMPTY;
    for ( int i = 0; i < MAX; i++ ) ans[i] = -1;
    for ( int t = 0; ans[MAX-1]==-1 ; t++ ){
	if ( t % 5 == 0 ) Q.push(t/5);
	for ( int i = 0; i < NSEAT; i++ ){
	    if ( S[i] == EMPTY ) continue;
	    if ( t - in[S[i]] >= 17*(S[i]%2)+3*(S[i]%3)+19 ) S[i] = EMPTY;
	}
	insertSeat(t);
    }

    int n;
    while ( cin >> n ){
	cout << ans[n] << endl;
    }
}
