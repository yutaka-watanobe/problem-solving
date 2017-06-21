#include<iostream>
using namespace std;
#define rep(i,n) for ( int i = 0; i < n; i++ )
#define MAX 20
#define SMAX 800

#define NON 0
#define TRUE 1
//#define FALSE 2

class Info{
    public:
    int ns, S[SMAX];
    Info(){ ns = 0;}
    void add( int t ){ S[ns++] = t; }
};

int n;
Info I[MAX+1]; // 1 base
int mt;
int state[MAX+1];

bool valid(){
    for ( int i = 1; i <= n; i++ ){
	if ( state[i] == NON ) continue;
	for ( int j = 0; j < I[i].ns; j++ ){
	    int target = I[i].S[j];
	    //if ( target < 0 ) neg[(-1)*target]++;
	    //else pos[target]++;
	    if ( target < 0 ) {
		if ( state[(-1)*target] == TRUE ) return false;
	    }
	}
    }
    return true;
}

bool valid2(){

    for ( int i = 1; i <= n; i++ ){
	if ( state[i] == TRUE  ) {
	    for ( int j = 0; j < I[i].ns; j++ ){
		int target = I[i].S[j];
		if ( target < 0 ) {
		    target *= (-1);
		    for ( int k = 0; k < I[target].ns; k++ ){
			int target2 = I[target].S[k];
			if ( target2 < 0 ) target2 *= (-1);
			if ( state[target2] == TRUE ) return false;
		    }
		}
	    }
	}
    }
    return true;
}

void rec( int cur, int nt ){

    if ( cur == n+1 ){
	if ( !valid() ) return;
	if ( !valid2() ) return;
	if ( mt < nt ) mt = nt;
	return;
    }
    state[cur] = NON;
    rec(cur+1, nt);
    state[cur] = TRUE;
    rec(cur+1, nt+1);
    state[cur] = NON;
}

main(){
    int s, t, a;
    while( cin >> n >> a ){
	if ( n == 0 && a == 0 ) break;
	for ( int i = 1; i <= n; i++ ) I[i].ns = 0;
	rep(i, a){
	    cin >> s >> t; I[s].add(t);
	}
	mt = 0;
	for ( int i =1; i <= n; i++ ) state[i] = NON;
	rec(1, 0);
	cout << mt << endl;
    }
}
