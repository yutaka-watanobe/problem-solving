#include<iostream>
using namespace std;
#define MAX 100

int main(){
    int tcase; cin >> tcase;
    int up, down, n, D[MAX];
    for ( int t= 0; t < tcase; t++ ){
	up = down = 0;
	cin >> n;
	for ( int i = 0; i < n; i++ ) cin >> D[i];

	for ( int i = 0; i < n-1; i++ ){
	    if ( D[i+1] > D[i] ) up = max( up, D[i+1]-D[i] );
	    else if ( D[i+1] < D[i] ) down = max(down, D[i]-D[i+1]);
	}
	cout << up << " " << down << endl;

    }
}
