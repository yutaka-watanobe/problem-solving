#include<iostream>
using namespace std;
#define MAX 50

main(){
    int tcase; cin >> tcase;
    int n, h, l, p, x;

    for ( int t= 1; t <= tcase; t++ ){
	cin >> n >> p;
	h = l = 0;
	
	for ( int i = 1; i < n; i++ ) {
	    cin >> x;
	    if ( p > x ) l++;
	    else if ( p < x ) h++;
	    p = x;
	}
	
	cout << "Case " << t << ": " << h << " " << l << endl;
	
    }
}
