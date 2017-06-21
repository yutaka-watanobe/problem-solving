#include<stdio.h>
#include<iostream>
#define MAX 100

    using namespace std;

class GaussJordan{
 public:
  int N;
  double A[MAX][MAX], B[MAX];

  void compute(){

      double divisor, multiplier;

      for ( int k = 0; k < N; k++ ){
	  divisor = A[k][k];
	  B[k] = B[k] / divisor;
	  for ( int j = k; j < N; j++ ){
	      A[k][j] = A[k][j] / divisor;
	  }
	  for ( int i = 0; i < N; i++ ){
	      if ( i == k ) continue;
	      multiplier = A[i][k];
	      B[i] = B[i] - multiplier * B[k];
	      for ( int j = k; j < N; j++ ){
		  A[i][j] = A[i][j] - multiplier * A[k][j];
	      }
	  }
      }
  }

  void input(){
      cin >> N;

      for ( int i = 0; i < N; i++ ){
	  for ( int j = 0; j < N; j++ ){
	      cin >> A[i][j];
	  }
      }
      
      for ( int i = 0; i < N; i++ ){
	  cin >> B[i];
      }
  }
    
  void output(){
      for ( int i = 0; i < N; i++ ){
	  printf("%.4lf\n", B[i]);
      }
  }
    
};

main(){
    GaussJordan GJ;
    GJ.input();
    GJ.compute();
    GJ.output();
}

