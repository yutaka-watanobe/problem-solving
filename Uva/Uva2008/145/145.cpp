#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

static const int T[5][3] = {{10, 6, 2},
			    {25, 15, 5},
			    {53, 33, 13},
			    {87, 47, 17},
			    {144, 80, 30}};
int main(){
    
    char id;
    string number;
    int begin, end;
    int h, m;

    while(1){
	cin >> id;
	if ( id == '#' ) break;
	cin >> number;
	cin >> h >> m; begin = h*60 + m;
	cin >> h >> m; end = h*60 + m;
	
	int t = begin;
	int cost = 0;
	int r1, r2, r3;
	r1 = r2 = r3 = 0;
	while(1){
	    if ( 480 <= t && t < 1080 ) r1++;
	    else if ( 1080 <= t && t < 1320 ) r2++;
	    else r3++;
	    t++;
	    if ( t == 1440 ) t = 0;
	    if ( t == end ) break;
	}
	cost = r1*T[id-'A'][0] + r2*T[id-'A'][1] + r3*T[id-'A'][2];
	number = "  " + number;
	cout << number;
	printf("%6d%6d%6d%3c%5d.%.2d\n", r1, r2, r3, id, cost/100, cost%100);
    }
    return 0;
}
