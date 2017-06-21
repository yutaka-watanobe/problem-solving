#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#define MAX 1000
#define DIAGONAL 1
#define TOP 0

using namespace std;

struct Item{ int value, weight; };

int N, W;
Item items[MAX];
int C[MAX+1][MAX+1];

int knapsack(){
    for ( int w = 0; w <= W; w++ ) C[0][w] = 0;
    for ( int i = 1; i <= N; i++ ) C[i][0] = 0;
    for ( int i = 1; i <= N; i++ ){
	for ( int w = 1; w <= W; w++ ){
	    C[i][w] = C[i-1][w];
	    for ( int j = 1; j*items[i].weight <= w; j++ ){
		if ( j*items[i].value + C[i-1][w - j*items[i].weight] > C[i][w] ){
		    C[i][w] = j*items[i].value + C[i-1][w - j*items[i].weight];
		}
	    }
	}
    }
    return C[N][W];
}

int main(){
    int C[MAX], V[MAX], D[MAX], L[MAX];
    string line;
    while(cin >> N >> W){
	int maxv = 0;
	for ( int i = 0; i < N; i++ ){
	    getline(cin, line);
	    getline(cin, line);
	    cin >> C[i] >>  V[i] >> D[i] >> L[i];
	}
	for ( int i = 0; i < N; i++ )  items[i+1].weight = C[i];

	for ( int i = 0; i < N; i++ )  items[i+1].value = V[i];
	maxv = max(maxv, knapsack());
	for ( int i = 0; i < N; i++ )  items[i+1].value = D[i];
	maxv = max(maxv, knapsack());
	for ( int i = 0; i < N; i++ )  items[i+1].value = L[i];
	maxv = max(maxv, knapsack());
	cout << maxv << endl;
    }
    return 0;
}
