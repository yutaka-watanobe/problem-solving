#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

typedef unsigned long long ullong;

ullong gcd( ullong x, ullong y ){
    ullong r;
    if ( x < y ) swap( x, y );
    while ( y > 0 ){
	r = x % y;
	x = y;
	y = r;
    }
    return x;
}

ullong lcm( ullong x, ullong y ){
    return x*y/gcd(x,y);
}

ullong getLength( ullong a, ullong m ){
    ullong x = (a*1)%m;
    ullong cnt = 1;
    while( x != 1 ){
	x = (a*x)%m;
	cnt++;
    }
    return cnt;
}

int main(){
    ullong a1, m1, a2, m2, a3, m3;
    
    while( cin >> a1 >> m1 >> a2 >> m2 >> a3 >> m3 ){
	if ( a1 == 0 ) break;
	assert( gcd(a1, m1) == 1 &&
		gcd(a2, m2) == 1 &&
		gcd(a3, m3) == 1 );
	ullong r1 = getLength(a1, m1); 
	ullong r2 = getLength(a2, m2);
	ullong r3 = getLength(a3, m3);
	//	cout << r1 << " " << r2 << " " << r3 << endl;
	cout << lcm(r1, lcm(r2, r3)) << endl;
    }
    return 0;
}
