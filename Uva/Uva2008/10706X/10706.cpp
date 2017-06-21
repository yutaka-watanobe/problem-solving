#include<iostream>
#include<cmath>
using namespace std;
typedef long long llong;

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	llong x; cin >> x;
	llong base = (int)((1+(double)sqrt(1+8*x))/2.0 - 1);
	llong baseIndex = base*(base+1)/2;
	llong diff = x - baseIndex;
	if ( diff == 0 ) cout << base << endl;
	else cout << diff << endl;
    }
}
