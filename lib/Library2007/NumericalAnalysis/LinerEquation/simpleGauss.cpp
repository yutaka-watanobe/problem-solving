#include<stdio.h>
#include<iostream>
#include<cmath>

using namespace std;

#define MAX 100
#define EPS 0.000001

class SimpleGaussElimination{
    public:
    int N;
    double A[MAX][MAX], X[MAX], B[MAX];

  void compute(){
      forwardElimination();
      backwardSubstitution();
  }
    
  void forwardElimination(){
      double p;

      for ( int k = 0; k < N - 1; k++ ){
	  for ( int i = k + 1; i < N; i++ ){
	      p = A[i][k] / A[k][k];
	      for ( int j = k ; j < N; j++ ){
		  A[i][j] = A[i][j] - p * A[k][j];
	      }
	      B[i] = B[i] - p * B[k];
	  }
      }
  }

  void backwardSubstitution(){
      double sum;
      
      for ( int k = N - 1; k >= 0; k-- ){
	  if ( fabs( A[k][k] ) <= EPS ){
	      cout << "error" << endl;
	      return;
	  }
	  
	  sum = 0.0;
	  
	  for ( int j = k + 1; j < N; j++ ){
	      sum += A[k][j] * X[j];
	  }
	  
	  X[k] = ( B[k] - sum ) / A[k][k];
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
      printf("%.4lf\n", X[i]);
    }
  }

};

main(){

  SimpleGaussElimination SGE;
  SGE.input();
  SGE.compute();
  SGE.output();

}

