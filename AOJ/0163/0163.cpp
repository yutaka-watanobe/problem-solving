#include<iostream>
using namespace std;

struct Point{ int t, p;};

int T[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
	       {0, 0, 300, 500, 600, 700, 1350, 1650},
	       {0, 6, 0, 350, 450, 600, 1150, 1500},
	       {0, 13, 7, 0, 250, 400, 1000, 1350},
	       {0, 18, 12, 5, 0, 250, 850, 1300},
	       {0, 23, 17, 10, 5, 0, 600, 1150},
	       {0, 43, 37, 30, 25, 20, 0, 500},
	       {0, 58, 52, 45, 40, 35, 15,0}};

main(){
    Point s, d;
    int cost, h, m;
    while(1){
	cin >> s.p;
	if ( s.p == 0 ) break;
	cin >> h >> m; s.t = h*60 + m;
	cin >> d.p;
	cin >> h >> m; d.t = h*60 + m;
	cost = T[s.p][d.p];
	if ( 1050 <= s.t && s.t <= 1170 || 1050 <= d.t && d.t <= 1170 ){
	    if ( T[d.p][s.p] <= 40 ) cost /=  2;
	}
	if ( cost % 50 ) cost += 25;
	cout << cost << endl;
    }
}





