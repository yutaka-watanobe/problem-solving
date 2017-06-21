#include<stdio.h>
#include<iostream>
#define MAX 100

class LUDecomposition{
 public:
  int N;
  double A[MAX][MAX], L[MAX][MAX], U[MAX][MAX];

  void read(){
    cin >> N;
    for ( int i = 0; i < N; i++ ){
      for ( int j = 0; j < N; j++ ){
	cin >> A[i][j];
      }
    }
  }

  void init(){
    for ( int i = 0; i < N; i++ ){
      for ( int j = 0; j < N; j++ ){
	L[i][j] = U[i][j] = 0;
	if ( i == j ) L[i][j] = 1;
      }
    }
  }

  void compute(){
    init();
    for ( int j = 0; j < N; j++ ){

      for ( int i = 0; i <= j; i++ ){
	double sum = 0.0;
	for ( int k = 0; k <= i - 1 ; k++ ){
	  sum += L[i][k] * U[k][j];
	}
	U[i][j] = A[i][j] - sum;
      }

      for ( int i = j + 1; i < N; i++ ){
	double sum = 0.0;
	for ( int k = 0; k <= j - 1; k++ ){
	  sum += L[i][k] * U[k][j];
	}
	L[i][j] = (A[i][j] - sum) / U[j][j];
      }
    }
  }

  void printResult(){
    cout << "L" << endl;
    for ( int i = 0; i < N; i++ ){				    
      for ( int j = 0; j < N; j++ ){
	cout << L[i][j];
      }
      cout << endl;
    }

    cout << "U" << endl;
    for ( int i = 0; i < N; i++ ){				    
      for ( int j = 0; j < N; j++ ){
	cout << U[i][j];
      }
      cout << endl;
    }
  }

  void work(){
    compute();
    printResult();
  }

};

main(){
  LUDecomposition LUD;
  LUD.read();
  LUD.work();
}
