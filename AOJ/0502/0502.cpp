#include<iostream>
#include<string>
using namespace std;

class Cube{
    public:
    int face[6];

    Cube(){
	for ( int i = 0; i < 6; i++ ) face[i] = i+1;
    }

    void rotateEW(){
	int tmp = face[0];
	face[0] = face[3];
	face[3] = face[5];
	face[5] = face[2];
	face[2] = tmp;
    }

    void rotateNS(){
	int tmp = face[0];
	face[0] = face[1];
	face[1] = face[5];
	face[5] = face[4];
	face[4] = tmp;
    }

    void rotateP(){
	int tmp = face[2];
	face[2] = face[1];
	face[1] = face[3];
	face[3] = face[4];
	face[4] = tmp;
    }
};

int main(){
    int n, sum;
    string com;
    while( cin >> n && n ){
	Cube cube;
	sum = 1;
	for ( int i = 0; i < n; i++ ){
	    cin >> com;
	    if ( com == "East" ) cube.rotateEW();
	    else if ( com == "West" ) for ( int k = 0; k < 3; k++ ) cube.rotateEW();
	    else if ( com == "North" ) cube.rotateNS();
	    else if ( com == "South" ) for ( int k = 0; k < 3; k++ ) cube.rotateNS();
	    else if ( com == "Left" ) cube.rotateP();
	    else if ( com == "Right" ) for ( int k = 0; k < 3; k++ ) cube.rotateP();
	    sum += cube.face[0];
	}
	cout << sum<< endl;
    }
    return 0;
}
