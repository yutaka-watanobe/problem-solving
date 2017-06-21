#include<iostream>
#include<string>
#include<map>
using namespace std;

struct Face{
    int color;
    bool change;
};

class Cube{
    public:
    Face faces[6];
    Cube(){}

    void init(){
	for ( int i = 0; i < 6; i++ ) faces[i].change = false;
    }
    
    void rotate1(){
	Face tmp = faces[2];
	faces[2] = faces[0];
	faces[0] = faces[3];
	faces[3] = faces[5];
	faces[5] = tmp;
    }

    void rotate2(){
	Face tmp = faces[1];
	faces[1] = faces[0];
	faces[0] = faces[4];
	faces[4] = faces[5];
	faces[5] = tmp;
    }

    void rotate3(){
	Face tmp = faces[2];
	faces[2] = faces[4];
	faces[4] = faces[3];
	faces[3] = faces[1];
	faces[1] = tmp;
    }
};



int n;
Cube cubes[4];
map<string, int> CT; //color table;
int colorID;
int mincost;

bool check( Cube c1, Cube target ){
    for ( int i = 0; i < 6; i++ ){
	if ( c1.faces[i].color != target.faces[i].color  &&
	     c1.faces[i].change == false ) return false;
	     //	     c2.faces[i].change == false ) return false;
    }
    return true;
}

bool isSame( Cube c1, Cube target ){
    for ( int r1 = 0; r1 < 4; r1++ ){
	for ( int r2 = 0; r2 < 4; r2++ ){
	    if ( check( c1, target ) ) return true;
	    c1.rotate3();
	}
	c1.rotate1();
    }
    c1.rotate2();
    for ( int r1 = 0; r1 < 4; r1++ ){
	for ( int r2 = 0; r2 < 4; r2++ ){
	    if ( check( c1, target ) ) return true;
	    c1.rotate3();
	}
	c1.rotate1();
    }
    return false;
}


void recursive( int pos, int nchange ){
    if ( nchange >= mincost ) return;

    if ( pos == 6*(n-1) ){
	for ( int i = 0; i < n-1; i++ ){
	    if ( !isSame( cubes[i], cubes[n-1]) ) return;
	}
	mincost = min( mincost, nchange );
	return;
    }

    // no chage
    recursive( pos + 1, nchange );
    // change
    cubes[pos/6].faces[pos%6].change = true;
    recursive( pos + 1, nchange + 1 );
    cubes[pos/6].faces[pos%6].change = false;
}

int compute(){
    mincost = 18;

    Cube tmps[4];
    for ( int i = 0; i < n; i++ ) tmps[i] = cubes[i];

    for ( int target = 0; target < n; target++ ){
	for ( int i = 0; i < n; i++ ) cubes[i] = tmps[i];
	Cube tmp = cubes[n-1];
	cubes[n-1] = cubes[target];
	cubes[target] = tmp;


	for ( int i = 0; i < n; i++ ) cubes[i].init();
	
	recursive( 0, 0 );
    }


    
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
	    cubes[i].faces[j].color = getColor(color);
	}
    }

    return true;
}

main(){
    while( initialize() ) cout << compute() << endl;
}
