#include<iostream>
#include<algorithm>
using namespace std;

main(){
    int n, v[3];
    cin >> n;
    for ( int i = 0; i < n; i++ ){
	cin >> v[0] >> v[1] >> v[2]; sort( v, v+3);
	if ( v[0]*v[0] + v[1]*v[1] == v[2]*v[2] ) cout << "YES" << endl;
	else cout << "NO" << endl;
    }
}
