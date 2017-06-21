#include<iostream>
#include<cmath>
using namespace std;
typedef unsigned long long llong;

int main(){
    llong N;
    while( cin >> N && N ){
	llong n = N/2;
	llong rn = (llong)ceil(sqrt(n));
	llong sum = n;
	for ( int i = 1; i < rn; i++ ){
	    sum += (llong)ceil(1.0*n/i);
	}
	cout << 8*(sum*2 - rn*rn) + 8*N << endl;
    }
    return 0;
}
