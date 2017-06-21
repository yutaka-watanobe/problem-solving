#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int tcase; cin >> tcase;
    long long T[3];
    for ( int i = 0; i < tcase; i++ ){
	cin >> T[0] >> T[1] >> T[2];
	sort( T, T + 3 );
	cout << "Case " << i+1 << ": ";
	if ( T[2] >= T[0] + T[1] || T[0] <= 0 ) cout << "Invalid" << endl;
	else if ( T[0] == T[1] && T[1] == T[2] ) cout << "Equilateral" << endl;
	else if ( T[0] == T[1] || T[1] == T[2] || T[2] == T[0] ) cout << "Isosceles" << endl;
	else cout << "Scalene" << endl;
    }
    return 0;
}
