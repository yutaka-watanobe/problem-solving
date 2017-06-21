#include<iostream>
#define MAX 11

using namespace std;


char M[MAX][MAX];
char C[MAX][MAX];
char R[MAX][MAX];
int n;
bool touched;

char check(int i, int j ){
  if ( C[i][j] != 'x' ) return '.';

  if ( M[i][j] == '*' ) {
    touched = true;
    return '*';
  }


  int sum = 0;
  
  int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
  int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

  int ni, nj;
  for ( int d = 0; d < 8; d++ ){
    ni = i + dx[d];
    nj = j + dy[d];

    if ( 0 <= ni && 0 <= nj && ni < n && nj < n ){
      if ( M[ni][nj] == '*' ) sum++;
    }

  }

  return (sum +'0');

}

void work(){
  touched = false;
  for ( int i = 0; i < n; i++ ){
    for ( int j = 0; j < n; j++ ){
      R[i][j] = check(i, j);
    }
  }

  for ( int i = 0; i < n; i++ ){
    for ( int j = 0; j < n; j++ ){
      if ( touched && M[i][j] == '*'){
	cout << '*';
      } else {
	cout << R[i][j];
      }
    }
    cout << endl;
  }
}


void read(){
  cin >> n;
  for ( int i = 0; i < n ; i++ ){
    for ( int j = 0; j < n; j++ ){
      cin >> M[i][j];
    }
  }

  for ( int i = 0; i < n ; i++ ){
    for ( int j = 0; j < n; j++ ){
      cin >> C[i][j];
    }
  }
}

main(){
  int tcase; cin >> tcase;
  
  for (int i = 0; i < tcase; i++ ){
    if ( i ) cout << endl;
    read();
    work();
  }
}
