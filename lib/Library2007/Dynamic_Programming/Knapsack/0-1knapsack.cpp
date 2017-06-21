/******************
 * 0 - 1 Knapsack *
 ******************/
#include<iostream>
#include<vector>
#define MAX 100
#define DIAGONAL 1
#define LEFT 0

using namespace std;
/**
 * Target 624, 10130, 
 * 
 */

struct Item{
    int value, weight;
};

int n;
Item items[MAX];
int C[MAX+1][MAX+1], G[MAX+1][MAX+1];
int weight;

void compute( int &maxValue, vector<int> &path ){
    for ( int w = 0; w <= weight; w++ ) {
	C[0][w] = 0;
	G[0][w] = DIAGONAL;
    }

    for ( int i = 1; i <= n; i++ ) C[i][0] = 0;

    for ( int i = 1; i <= n; i++ ){
	for ( int w = 1; w <= weight; w++ ){
	    if ( items[i].weight <= w ){
		if ( items[i].value + C[i-1][w - items[i].weight] > C[i-1][w] ){
		    C[i][w] = items[i].value + C[i-1][w - items[i].weight];
		    G[i][w] = DIAGONAL;
		}else{
		    C[i][w] = C[i-1][w];
		    G[i][w] = LEFT;
		}
	    }else {
		C[i][w] = C[i-1][w];
		G[i][w] = LEFT;
	    }
	}
    }
    
    maxValue = C[n][weight];
    
    path.clear();
    int w = weight;
    
    for ( int i = n; i >=1; i-- ){
	if ( G[i][w] == DIAGONAL ){
	    path.push_back( i );
	    w -= items[i].weight;
	}
    }
    
    reverse( path.begin(), path.end() );
}

void input(){
  cin >> n >> weight;
    for ( int i = 1; i <= n; i++ ){
	cin >> items[i].value >> items[i].weight;
    }
}

main(){
    int maxValue;
    vector<int> path;
    input();
    compute( maxValue, path);
    
    cout << "max " << maxValue << endl;
    for ( int i = 0; i < path.size(); i++ ) cout << path[i] << endl;

    for ( int i = 1; i <= n; i++ ){
      for ( int j = 1; j <= weight; j++ ) {
	  printf("%5d", C[i][j]);
      }
      cout << endl;
    }

}
