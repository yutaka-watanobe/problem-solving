#include<iostream>
using namespace std;

int getValue( int l, int w ){
    int L[6] = {60, 80, 100, 120, 140, 160};
    int W[6] = {2, 5, 10, 15, 20, 25};
    int V[6] = {600, 800, 1000, 1200, 1400, 1600};
    for ( int i = 0; i < 6; i++ ){
	if ( l <= L[i] && w <= W[i] ) return V[i];
    }
    return 0;
}

main(){
    int n, x, y, h, w; 
    while( cin >> n && n ){
	int sum = 0;
	for ( int i = 0; i < n; i++ ){
	    cin >> x >> y >> h >> w;
	    sum += getValue(x + y + h, w);
	}
	cout << sum << endl;
    }
}
