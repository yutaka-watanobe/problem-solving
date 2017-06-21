// BF
#include<iostream>

using namespace std;

void compute(int A, int B, int C){
    int x, y, z;
    for ( x = -100; x <= 100; x++ ){
	for ( y = -100; y <= 100; y++ ){
	    z = A - x - y;
	    if ( x == y || y == z || x == z ) continue;
	    if ( x*y*z != B ) continue;
	    if ( x*x + y*y + z*z != C ) continue;
	    cout << x << " " << y << " " << z << endl;
	    return;
	}
    }
    cout << "No solution." << endl;
}

int main(){
    int tcase; cin >> tcase;
    int A, B, C;
    for ( int i = 0; i < tcase; i++ ){
	cin >> A >> B >> C;
	compute(A, B, C);
    }
    
    return 0;
}
