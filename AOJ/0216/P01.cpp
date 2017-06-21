#include<iostream>
#include<cassert>
using namespace std;

int getCost(int w){
    int cost = 0;
    for (int i = 0; i <= w; i++ ){
	if ( 10 < i && i <= 20 ) cost += 125;
	else if ( 20 < i && i <= 30 ) cost += 140;
	else if ( 30 < i ) cost += 160;
    }
    return 1150 + cost;
}

main(){
    int w;
    while(1){
	cin >> w;
	if ( w == -1 ) break;
	assert( 0 <= w && w <= 100);
	cout << 4280 - getCost(w) << endl;
    }
}
