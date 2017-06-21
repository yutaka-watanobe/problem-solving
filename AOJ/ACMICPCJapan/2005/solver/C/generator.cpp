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
    
    void print(){
	cout << "{";
	for ( int i = 0; i < 6; i++ ) {
	    if ( i ) cout << ", ";
	    cout << faces[i];
	}
	cout << "},";
	cout << endl;
    }
};

void simulate(Cube c1){
    for ( int r1 = 0; r1 < 4; r1++ ){
	for ( int r2 = 0; r2 < 4; r2++ ){
	    c1.print();
	    c1.rotate3();
	}
	c1.rotate1();
    }
    c1.rotate2();
    for ( int r2 = 0; r2 < 4; r2++ ){
	c1.print();
	c1.rotate3();
    }
    c1.rotate1();
    c1.rotate1();
    for ( int r2 = 0; r2 < 4; r2++ ){
	c1.print();
	c1.rotate3();
    }
}
main(){
  Cube cube;
  for ( int i = 0; i < 6; i++ ) cube.faces[i] = i;

  simulate(cube);

}