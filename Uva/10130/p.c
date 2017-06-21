// @JUDGE_ID:  17051CA  10130  C++
// @begin_of_source_code
/* DP Knapsack */
/* Knapsack アルゴリズムをよく理解してなければ */
/* C[i, w] に何が入ってるか知らないとダメ */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#define DIAGONAL 0
#define LEFT 1

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
    for ( int w = 0; w <= weight; w++ ) C[0][w] = 0;

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
      if ( G[i][w] == LEFT ){
	w = w;
      }else if ( G[i][w] == DIAGONAL ){
	p.push_back( i );
	w = w - W[i];
      }
    }

    reverse( p.begin(), p.end() );
    return p;
  }

};

int N, M;
vector<int> W, V;

int read(){
  W.clear();
  V.clear();

  cin >> N;
  W.resize( N + 1 );
  V.resize( N + 1 );
  for ( int i = 1; i <= N; i++ ){
    cin >> V[i];
    cin >> W[i];
  }

}

void work(){
  cin >> M;

  int sum = 0;
  int cap;

  vector<int> persons;
  persons.resize(M);

  for ( int i = 0; i < M; i++ ){
    cin >> persons[i];
  }

  cap = *max_element( persons.begin(), persons.end() );
  Knapsack nap = Knapsack(N, cap, W, V);

  cout << nap.getMaxValue( persons ) << endl;
}

main(){
  int t;
  cin >> t;
  for ( int i = 0; i < t; i++ ){
    read();
    work();
  }
}
// @end_of_source_code
