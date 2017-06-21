#include<iostream>
#include<algorithm>
using namespace std;

main(){
    int x, y;
    while ( cin >> x >> y && x && y){
	if ( y > x ) swap(x, y);
	int step = 0;
	while(y){
	    int t = x % y;
	    x = y;
	    y = t;
	    step++;
	}
	cout << x << " " << step << endl;
    }
}
