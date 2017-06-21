#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int z;
    while( cin >> z && z ){
	int maxv = 0;
	for ( int x = 1; x <= z; x++ ){
	    if ( x*x*x >= z*z*z ) continue;
	    for ( int y = 1; y <= z; y++ ){
		if ( x*x*x + y*y*y >= z*z*z ) continue;
		maxv = max( maxv, x*x*x + y*y*y );
	    }
	}
	cout << z*z*z - maxv << endl;

    }
    return 0;
}
