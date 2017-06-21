#include<stdio.h>
#include<algorithm>
#define MAX 80

int size;
long M[MAX][MAX];
long T[MAX][MAX][MAX +1];
long currentMax;

void initTable(){
  for ( int i = 0; i < size; i++ ){
    for ( int j = 0; j < size; j++ ){
      T[i][j][0] = M[i][j];
    }
  }

  for ( int k = 1; k < size; k++ ){
    for ( int i = 0; i < size; i++ ){
      for ( int j = 0; j < size; j++ ){
	T[i][j][k] = T[i][j][k-1] + M[i][(j + k) % size ];
      }
    }
  }
}

void compute(){
  long S[MAX];
  for ( int k = 0; k < size; k++ ){
    for ( int j = 0; j < size; j++ ){

      S[s] = T[0][j][k];
	currentMax = max( currentMax, S[s] );
	for ( int i = 1; i < size; i++ ){
	  if ( S[(i-1+s)%size] >= 0 ){
	    S[(i+s)%size] = S[(i-1+s)%size] + T[i][j][k];
	  } else {
	    S[(i+s)%size] = T[i][j][k];
	  }
	  currentMax = max( currentMax, S[i] );

	}
    }
  }
}

void rotate(){
  long tmp[MAX][MAX];
  for ( int i = 0; i < size; i++ ){
    for ( int j = 0; j < size; j++ ){
      tmp[size - j - 1][i] = M[i][j];
    }
  }
  for ( int i = 0; i < size; i++ ){
    for ( int j = 0; j < size; j++ ){
      M[i][j] = tmp[i][j];
    }
  }
}

void work(){

  currentMax = INT_MIN;
  //  currentMax = 0;

  initTable();
  compute();

  //  rotate();

  //  initTable();
  //  compute();

  printf("%ld\n", currentMax);
}

void read(){
  scanf("%d", &size);
  for ( int i = 0; i < size; i++ ){
    for ( int j = 0; j < size; j++ ){
      scanf("%ld", &M[i][j]);
    }
  }
}

main(){
  int tcase; scanf("%d", &tcase);
  for (int i = 0; i < tcase; i++ ){
    read();
    work();
  }
}
