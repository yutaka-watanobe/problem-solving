#include<iostream>
#include<string>
#include<map>
using namespace std;

class Cube{
    public:
    int faces[6];
    Cube(){}

    void rotate1(){
	int tmp = faces[2];
	faces[2] = faces[0];
	faces[0] = faces[3];
	faces[3] = faces[5];
	faces[5] = tmp;
    }

    void rotate2(){
	int tmp = faces[1];
	faces[1] = faces[0];
	faces[0] = faces[4];
	faces[4] = faces[5];
	faces[5] = tmp;
    }

    void rotate3(){
	int tmp = faces[2];
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

int check( Cube c1, Cube c2 ){
    int need = 0;
    for ( int i = 0; i < 6; i++ ){
	if ( c1.faces[i] != c2.faces[i] ) need++;
    }
    return need;
}

int getCost( Cube c1, Cube target ){
    int mincost = 6;
    for ( int r1 = 0; r1 < 4; r1++ ){
	for ( int r2 = 0; r2 < 4; r2++ ){
	    mincost = min( mincost, check( c1, target ) );
	    c1.rotate3();
	}
	c1.rotate1();
    }
    c1.rotate2();
    for ( int r2 = 0; r2 < 4; r2++ ){
	mincost = min( mincost, check( c1, target ) );
	c1.rotate3();
    }
    c1.rotate1();
    c1.rotate1();
    for ( int r2 = 0; r2 < 4; r2++ ){
	mincost = min( mincost, check( c1, target ) );
	c1.rotate3();
    }

    /*
    for ( int r1 = 0; r1 < 4; r1++ ){
	for ( int r2 = 0; r2 < 4; r2++ ){
	    mincost = min( mincost, check( c1, target ) );
	    c1.rotate3();
	}
	c1.rotate1();
    }
    */

    return mincost;
}

int compute(){
    int mincost = 18;

    /*
    for ( int i = 0; i < n; i++ ){
	for ( int j = 0; j < 6; j++ ) cout << cubes[i].faces[j] << " ";
	cout << endl;
	}*/

    for ( int target = 0; target < n; target++ ){
	int cost = 0;
	for ( int i = 0; i < n; i++ ){
	    if ( i != target ){
		cost += getCost( cubes[i], cubes[target] );
	    }
	}
	mincost = min( mincost, cost );
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
	    cubes[i].faces[j] = getColor(color);
	}
    }

    return true;
}

main(){
    while( initialize() ) cout << compute() << endl;
}
