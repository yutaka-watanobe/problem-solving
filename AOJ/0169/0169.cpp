#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

main(){
    string line;
    while(1){
	getline(cin, line);
	if ( line == "0" ) break;
	stringstream sin(line);
	int x, one = 0, sum = 0;
	while( sin >> x ){
	    if ( 10 <= x ) x = 10;
	    if ( x == 1 ) one++;
	    sum += x;
	}

	for ( int i = 0; i < one; i++ ){
	    if ( sum + 10 <= 21 ) sum += 10;
	}
	if ( sum > 21 ) sum = 0;
	cout << sum << endl;
    }
}
