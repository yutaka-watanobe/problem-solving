#include<iostream>
using namespace std;
#define MAX 100
#define INFTY (1<<24)

struct Card{ int top, bottom; };

Card C[MAX+1];
int N;

int getCost(){
    int cost[MAX+1][MAX+1];
    for ( int i = 1; i <= N; i++ ){
	for ( int j = 1; j <= N; j++ ) cost[i][j] = INFTY;
    }
    for ( int i = 1; i <= N; i++ ) cost[i][i] = 0;

    for ( int j = 1; j <= N-1; j++ ){
	for ( int i = 1; i <= N-j; i++ ){
	    for ( int k = i+1; k <= i+j; k++ ){
		int mul = C[i].top * C[k-1].bottom * C[k].top * C[i+j].bottom;
		cost[i][i+j] = min( cost[i][i+j], cost[i][k-1] + cost[k][i+j] + mul );
	    }
	}
    }

    return cost[1][N];
}

main(){
    cin >> N;
    for ( int i = 1; i <= N; i++ ) cin >> C[i].top >> C[i].bottom;
    cout << getCost() << endl;
}
