#include<iostream>
#include<string>
using namespace std;

class Dice{
    public:
    int face[6];
    Dice(){}
    void rotateV(){
	int tmp = face[0];
	face[0] = face[4];
	face[4] = face[3];
	face[3] = face[1];
	face[1] = tmp;
    }

    void rotateH(){
	int tmp = face[0];
	face[0] = face[2];
	face[2] = face[3];
	face[3] = face[5];
	face[5] = tmp;
    }
};

Dice dice;
int n;

void simulate(){
    string com;
    for ( int i = 0; i < n; i++ ){
	cin >> com;
	if ( com == "north" ) dice.rotateV();
	else if ( com == "south" ) for ( int i = 0; i < 3; i++ ) dice.rotateV();
	else if ( com == "east" ) dice.rotateH();
	else if ( com == "west" ) for ( int i = 0; i < 3; i++ ) dice.rotateH();
    }
}

void init(){
    for ( int i = 0; i < 3; i++ ) { 
	dice.face[i] = i+1;
	dice.face[i+3] = 7 - (i+1);
    }
}

main(){
    while( cin >> n && n ){
	init();
	simulate();
	cout << dice.face[0] << endl;
    }
}
