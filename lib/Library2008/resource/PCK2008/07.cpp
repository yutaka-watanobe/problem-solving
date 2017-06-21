#include<iostream>
#include<queue>
#include<map>
using namespace std;
#define INFTY (1<<21)

bool isSameColor( string state ){
    for ( int i = 1; i < state.size(); i++ ){
	if ( state[i-1] != state[i] ) return false;
    }
    return true;
}

char getColor( char c1, char c2 ){
    if ( c1 == 'g' ) return (c2=='r' ? 'b' : 'r');
    else if ( c1 == 'b' ) return (c2=='r' ? 'g' : 'r');
    else if ( c1 == 'r' ) return (c2=='b' ? 'g' : 'b');
}

int bfs(string s){
    queue<string> Q;
    map<string, bool> V;
    map<string, int> D;

    Q.push(s);
    V[s] = true;
    D[s] = 0;
    string u, v;

    while(!Q.empty()){
	u = Q.front(); Q.pop();
	if ( isSameColor(u) ) return D[u];
	for ( int i = 1; i < u.size(); i++ ){
	    if ( u[i-1] != u[i] ){
		v = u;
		v[i-1] = v[i] = getColor(u[i-1], u[i]);
		if ( !V[v] ){
		    V[v] = true;
		    D[v] = D[u] + 1;
		    Q.push(v);
		}
	    }
	}
    }

    return INFTY;
}

int main(){
    string initial;
    while( cin >> initial ){
	if ( initial == "0" ) break;
	int cost = bfs( initial );
	if ( cost == INFTY ) cout << "NA" << endl;
	else cout << cost << endl;
    }
    return 0;
}
