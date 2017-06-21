#include<iostream>
using namespace std;

void compute(){
    int x, y, w, h, n, px, py;
    int sum = 0;
    cin >> x >> y >> w >> h >> n;
    for ( int i = 0; i < n; i++ ){
	cin >> px >> py;
	if ( x <= px && px <= x + w &&
	     y <= py && py <= y + h ) sum++;
    }
    cout << sum << endl;
}
main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ) compute();
}
