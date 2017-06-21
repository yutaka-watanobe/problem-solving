#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
typedef long long llong;
#define LIMIT 1000000

int gcd( int x, int y ){
    int r;
    if ( x < y ) swap( x, y );
    
    while ( y > 0 ){
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

void compute(int k){
    llong x, y;
    vector<pair<llong, llong> > ans;

    for ( y = k+1; y <= LIMIT; y++ ){
	if ( y*k % (y-k) != 0 ) continue;
	x = (y*k)/(y-k);
	if ( x < y ) break;
	ans.push_back(make_pair(x, y));
    }

    cout << ans.size() << endl;
    for ( int i = 0; i < ans.size(); i++ ){
	cout << "1/" << k << " = 1/" << ans[i].first << " + 1/" << ans[i].second << endl;
    }
    
}

main(){
    int k;
    while( cin >> k ){
	compute(k);
    }
}
