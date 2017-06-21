/******************
 * 0 - 1 Knapsack *
 ******************/
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>
#define DIAGONAL 1
#define LEFT 0

/**
 * Solved 624, 10130, 
 */
class Knapsack{
 public:
  int n;
  int weight;
  vector<int> W, V;
  vector<vector<int> > C, G;
  
  Knapsack(){}
  Knapsack(int n, int weight, vector<int> W, vector<int> V):
    n(n), weight(weight), W(W), V(V){
    
    C.resize( n + 1 );
    G.resize( n + 1 );

    for ( int i = 0; i <= n; i++ ) C[i].resize( weight + 1 );
    for ( int i = 0; i <= n; i++ ) G[i].resize( weight + 1 );
    for ( int w = 0; w <= weight; w++ ) {
      C[0][w] = 0;
      G[0][w] = DIAGONAL;
    }

    for ( int i = 1; i <= n; i++ ){
      C[i][0] = 0;
      for ( int w = 1; w <= weight; w++ ){
	if ( W[i] <= w ){
	  if ( V[i] + C[i-1][w-W[i]] > C[i-1][w] ){
	    C[i][w] = V[i] + C[i-1][w-W[i]];
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
  }

  int getMaxValue(){
    return C[n][weight];
  }

  /**
   * use given person's list
   */
  int getMaxValue(vector<int> &l){
    int sum = 0;
    for ( int i = 0; i < l.size(); i++ ){
      sum += C[n][ l[i] ];
    }
    return sum;
  }

  /**
   * Solved 624,
   */
  vector<int> getPath(){
    vector<int> p;
    int w = weight;

    for ( int i = n; i >=1; i-- ){
      if ( G[i][w] == DIAGONAL ){
	p.push_back( i );
	w -= W[i];
      }
    }

    reverse( p.begin(), p.end() );
    return p;
  }

};

main(){
  vector<int> W, V;

  W.push_back(-1);
  W.push_back(2);
  W.push_back(3);
  W.push_back(4);
  W.push_back(5);

  V.push_back(-1);
  V.push_back(3);
  V.push_back(4);
  V.push_back(5);
  V.push_back(6);

  Knapsack nap = Knapsack(4, 50, W, V);

  cout << nap.getMaxValue() << endl;

  vector<int> p;
  p = nap.getPath();

  for ( int i = 0; i < p.size(); i++ ){
    cout << p[i] << " ";
  }
  cout << endl;
}
