#include<iostream>
#include<cassert>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
#define MAX 20
#define PMAX 1001
string line;

enum {ELE, TIE, REM};

//#define ELE 0
//#define TIE 1
//#define REM 2

bool removed[MAX];
string name[MAX];

void rem( int p, vector<int> V[PMAX], int id ){
    removed[id] = true;
    for ( int i = 0; i < p; i++ ){
	for ( int j = 0; j < V[i].size(); j++ ){
	    if ( V[i][j] == id ){
		V[i].erase( V[i].begin() + j ); continue;
	    }
	}
    }
}

int check( int p, int n, vector<int> V[PMAX], int &id ){
    int S[MAX] = {};

    for ( int i = 0; i < p; i++ ){
	S[V[i][0]]++;
    }

    int maxv = 0;
    int minv = 1000000;
    int maxi;
    for ( int i = 0; i < n; i++ ){
	if ( removed[i] ) continue;
	if ( maxv < S[i] ){
	    maxv = S[i];
	    maxi = i;
	}
	minv = min(minv, S[i] );
    }

    id = maxi;
    if ( maxv*2 > p ) {
	return ELE;
    }
    
    bool tie = true;
    int pre = -10;
    for ( int i = 0; i < n; i++ ){
	if ( removed[i] ) continue;
	if ( pre != -10 && pre != S[i] ) tie = false;
	pre = S[i];
    }

    if ( tie ) {
	for ( int i = 0; i < n; i++ ){
	    if ( !removed[i] ) cout << name[i] << endl;
	}
	return TIE;
    }

    for ( int i = 0; i < n; i++ ){
	if ( removed[i] ) continue;
	if ( S[i] == minv ){
	    rem(p, V, i);
	}
    }

    return REM;
}

void compute(){
    vector<int> V[PMAX];

    int n; cin >> n; getline( cin, line );
    for ( int i = 0; i < n; i++ ){
	getline( cin, line ); name[i] = line;
    }
    for ( int i = 0; i < n; i++ ) removed[i] = false;
    int p = 0;
    while(1){
	getline( cin, line );
	if ( line.size() == 0 || cin.eof() ) break;

	V[p].clear();
	stringstream sin( line );
	int x;
	for ( int j = 0; j < n; j++ ) {
	    sin >> x;  x--; V[p].push_back(x);
	}
	V[p].push_back(-1);
	p++;
    }

    int id;
    while(1){
      //	print(n, p, V);
	int state = check(p, n, V, id);
	if ( state == ELE){
	    cout << name[id] << endl; return;
	} else if ( state == TIE ){
	    return;
	} 
	assert( state == REM );
    }
}


int main(){
  int n; cin >> n; getline( cin, line );
    getline(cin, line);

    for ( int i = 0; i < n; i++ ){
	if ( i ) cout << endl;
	compute();
    }

    return 0;
}
