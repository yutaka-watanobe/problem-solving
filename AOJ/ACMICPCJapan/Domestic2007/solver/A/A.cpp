#include<iostream>
#include<algorithm>
using namespace std;

main(){
    int N, maxv, minv, total, score;
    while(1){
	cin >> N;
	if ( N == 0 ) break;
	total = 0;
	maxv = 0, minv = INT_MAX;
	for ( int i = 0; i < N; i++ ){
	    cin >> score;
	    maxv = max( maxv, score);
	    minv = min( minv, score);
	    total += score;
	}
	cout << (total - minv - maxv)/(N-2) << endl;
    }
}