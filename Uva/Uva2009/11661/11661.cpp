#include<iostream>
#include<string>
using namespace std;

main(){
    int n;
    string line;
    while( cin >> n && n ){
	cin >> line;
	int ans = 2000001;
	int leftR = -2000001;
	int leftD = -2000001;
	for ( int i = 0; i < n; i++ ){
	    char ch = line[i];
	    if ( ch == 'Z' ){
		ans = 0;
		leftD = leftR = i;
	    } else if ( ch == 'D' ){
		ans = min(ans, i-leftR);
		leftD = i;
	    } else if ( ch == 'R' ){
		ans = min(ans, i-leftD);
		leftR = i;
	    }
	}
	cout << ans << endl;
    }
}
