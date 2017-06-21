#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

int minv;
map<string, bool> visited;

void recursive( string state ){
    int cnt = 0;
    for ( int i = 0; i < state.size(); i++ ){
	if ( state[i] == 'o' ) cnt++;
    }
    minv = min( minv, cnt );
    visited[state] = true;

    for ( int i = 0; i <= 9; i++ ){
	if ( state[i] == 'o' && state[i+1] == 'o' && state[i+2] == '-' ){
	    string next = state;
	    next[i] = next[i+1] = '-';
	    next[i+2] = 'o';
	    if ( !visited[next] ) recursive( next );
	}
    }

    for ( int i = 11; i >= 2; i-- ){
	if ( state[i] == 'o' && state[i-1] == 'o' && state[i-2] == '-' ){
	    string next = state;
	    next[i] = next[i-1] = '-';
	    next[i-2] = 'o';
	    if ( !visited[next] ) recursive( next );
	}
    }


}

void compute(){
    string state; cin >> state;
    visited = map<string, bool>();

    minv = 12;
    recursive( state );
    cout << minv << endl;
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	compute();
    }
}
