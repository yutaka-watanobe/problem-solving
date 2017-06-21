#include<iostream>
#include<string>
#include<map>
using namespace std;

int RT[24][6] = {
                 {0, 1, 2, 3, 4, 5},
		 {0, 2, 4, 1, 3, 5},
		 {0, 4, 3, 2, 1, 5},
		 {0, 3, 1, 4, 2, 5},
		 {3, 1, 0, 5, 4, 2},
		 {3, 0, 4, 1, 5, 2},
		 {3, 4, 5, 0, 1, 2},
		 {3, 5, 1, 4, 0, 2},
		 {5, 1, 3, 2, 4, 0},
		 {5, 3, 4, 1, 2, 0},
		 {5, 4, 2, 3, 1, 0},
		 {5, 2, 1, 4, 3, 0},
		 {2, 1, 5, 0, 4, 3},
		 {2, 5, 4, 1, 0, 3},
		 {2, 4, 0, 5, 1, 3},
		 {2, 0, 1, 4, 5, 3},
		 {4, 0, 2, 3, 5, 1},
		 {4, 2, 5, 0, 3, 1},
		 {4, 5, 3, 2, 0, 1},
		 {4, 3, 0, 5, 2, 1},
		 {1, 0, 3, 2, 5, 4},
		 {1, 3, 5, 0, 2, 4},
		 {1, 5, 2, 3, 0, 4},
		 {1, 2, 0, 5, 3, 4}
                };

class Cube{
    public:
    int faces[6];
    Cube(){}
};

int n;
Cube cubes[4];
Cube buffer[4];
int mincost;

map<string, int> CT; //color table;
int colorID;

int check(){
    int T[25];
    int diff = 0;
    for ( int f = 0; f < 6; f++ ){
	for ( int i = 0; i < 25; i++ ) T[i] = 0;

	for ( int i = 0; i < n; i++ ){
	    T[buffer[i].faces[f]]++;
	}
	
	int maxv = 0;
	int maxc;
	for ( int i = 0; i < 25; i++ ){
	    if ( maxv < T[i] ){
		maxv = T[i];
		maxc = i;
	    }
	}

	for ( int i = 0; i < n; i++ ){
	    if ( buffer[i].faces[f] != maxc ) diff++;
	}
    }
    return diff;
}

void recursive( int pos ){
    if ( pos == n ){
	mincost = min( mincost, check() );
	return;
    }

    Cube tmp = buffer[pos];
    for ( int i = 0; i < 24; i++ ){
	for ( int f = 0; f < 6; f++ ){
	    buffer[pos].faces[f] = cubes[pos].faces[RT[i][f]];
	}
	recursive( pos+1 );
    }
}

int compute(){
    buffer[0] = cubes[0];
    mincost = 24;
    recursive(1);
    return mincost;
}

int getColor(string color){
    if ( CT.find(color) == CT.end() ) CT[color] = colorID++;
    return CT[color];
}

bool initialize(){
    cin >> n;
    if ( n == 0 ) return false;
    CT = map<string, int>();
    colorID = 0;
    string color;
    for ( int i = 0; i < n; i++ ){
	for ( int j = 0; j < 6; j++ ){
	    cin >> color;
	    cubes[i].faces[j] = getColor(color);
	}
    }
    return true;
}

main(){
    while( initialize() ) cout << compute() << endl;
}
