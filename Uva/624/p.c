// @JUDGE_ID:  17051CA  624  C++
// @begin_of_source_code
/* DP Knapsack */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#define DIAGONAL 1
#define LEFT 0

/**
 * Solved 10130, 
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

int N;
int cap;
vector<int> W, V;
int read(){
  cin >> cap;
  if ( cin.eof() ) return 0;

  cin >> N;
  
  W.clear();
  V.clear();
  W.resize( N + 1);
  V.resize( N + 1);
  int k;
  for ( int i = 1; i <= N; i++ ){
    cin >> k;
    V[i] = k;
    W[i] = k;
  }

  return 1;
}

void work(){
  Knapsack nap = Knapsack( N, cap, W, V );
  int sum;
  vector<int> p;

  sum = nap.getMaxValue();

  p = nap.getPath();

  for ( int i = 0; i < p.size(); i++ ){
    cout << V[ p[i] ] << " ";
  }
  cout << "sum:" << sum << endl;
}

main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code
