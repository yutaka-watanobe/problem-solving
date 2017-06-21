#include<iostream>
#define MAX 1000
using namespace std;

int N, n;

char B[MAX][MAX];
char S[MAX][MAX];

bool read(){
  cin >> N >> n;

  if ( N == 0 && n == 0 ) return false;

  for ( int i = 0; i < N; i++ ){
    for (int j = 0; j < N; j++ ){
      cin >> B[i][j];
    }
  }

  for (int i = 0; i < n; i++ ){
    for ( int j = 0; j < n; j++ ){
      cin >> S[i][j];
    }
  }

  return true;
  
}

int compute(){
  int sum = 0;

  for ( int i = 0; i <= N-n; i++ ){
    for ( int j = 0; j <= N-n; j++ ){

      for ( int a = 0; a < n; a++ ){
	for ( int b = 0; b < n; b++ ){
	  int px = i + a;
	  int py = j + b;
	  
	  if ( B[px][py] != S[a][b] ) goto next;
	}
      }
      
      sum++;
    next:;

    }
  }

  return sum;
}



void rotate(){
  int tmp[MAX][MAX];

  for ( int i = 0; i < n; i++ ){
    for ( int j = 0; j < n; j++ ){
      tmp[i][j] = S[i][j];
    }
  }

  for ( int i = 0; i < n; i++ ){
    for ( int j = 0; j < n; j++ ){
      S[j][n-i-1] = tmp[i][j];
    }
  }

  /*
  for ( int i = 0; i < n; i++ ){
    for ( int j = 0; j < n; j++ ){
      cout << S[i][j];
    }
    cout << endl;
  }
  */
}

void work(){

  for ( int r = 0; r < 4; r++ ){
    if ( r > 0 ) cout << " ";
    cout << compute();
    rotate();
  }
  cout << endl;

}


main(){
  while ( read() ) work();
}
