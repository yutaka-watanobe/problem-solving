// Greedy
#include<iostream>
#include<cassert>
using namespace std;
#define BIT 32

int main(){
    long long s;
    while( cin >> s ){
	int cnt = 0;
	if ( s ) cnt++;
	while(1){
	    if ( s <= 1 ) break;
	    if ( s % 2 == 0 ) s /= 2;
	    else {
		if ( ((s-1)/2)%2 == 0|| (s-1)==2 ) s--;
		else s++;
	    }
	    cnt++;
	}
	cout << cnt << endl;
    }
    return 0;
}
