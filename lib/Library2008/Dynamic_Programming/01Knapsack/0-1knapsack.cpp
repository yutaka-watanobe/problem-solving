#include<iostream>
#include<vector>
#define MAX 1000
#define DIAGONAL 1
#define TOP 0

using namespace std;

struct Item{
    int value, weight;
};

int N, W;
Item items[MAX];
int C[MAX+1][MAX+1], G[MAX+1][MAX+1];

void compute( int &maxValue, vector<int> &selection ){
    for ( int w = 0; w <= W; w++ ) {
	C[0][w] = 0;
	G[0][w] = DIAGONAL;
    }

    for ( int i = 1; i <= N; i++ ) C[i][0] = 0;

    for ( int i = 1; i <= N; i++ ){
	for ( int w = 1; w <= W; w++ ){
	    if ( items[i].weight <= w ){
		if ( items[i].value + C[i-1][w - items[i].weight] > C[i-1][w] ){
		    C[i][w] = items[i].value + C[i-1][w - items[i].weight];
		    G[i][w] = DIAGONAL;
		}else{
		    C[i][w] = C[i-1][w];
		    G[i][w] = TOP;
		}
	    }else {
		C[i][w] = C[i-1][w];
		G[i][w] = TOP;
	    }
	}
    }
    
    maxValue = C[N][W];
    selection.clear();
    for ( int i = N, w = W; i >=1; i-- ){
	if ( G[i][w] == DIAGONAL ){
	    selection.push_back( i );
	    w -= items[i].weight;
	}
    }
    
    reverse( selection.begin(), selection.end() );
}

void input(){
    cin >> N >> W;
    for ( int i = 1; i <= N; i++ ){
	cin >> items[i].value >> items[i].weight;
    }
}

int main(){
    int maxValue;
    vector<int> selection;
    input();
    compute( maxValue, selection);
    
    cout << "max " << maxValue << endl;
    for ( int i = 0; i < selection.size(); i++ ) cout << selection[i] << endl;

    return 0;
}
