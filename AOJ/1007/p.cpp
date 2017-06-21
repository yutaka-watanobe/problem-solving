#include<stdio.h>
#include<iostream>
#define MAX 10

using namespace std;

int N;
int T[MAX][MAX];

int i, j;
int current;

void right(){
  if ( j + 1 < N ){
    j++;
  } else {
    i++;
  }
  T[i][j] = current++;
}

void lowerleft(){
  while ( i + 1< N && 0 <= j - 1){
    j--;
    i++;
    T[i][j] = current++;
  }
}

void bottom(){
  if ( i + 1 < N ){
    i++;
  } else {
    j++;
  }
  T[i][j] = current++;
}

void upperright(){
  while ( 0 <= i - 1 && j + 1 < N ){
    i--;
    j++;
    T[i][j] = current++;
  }
}

void work(){
  i = 0; j = 0;

  current = 1;
  T[i][j] = current++;
  if ( i == N-1 && j == N-1 ) return;

  while ( 1 ){
    right();
    if ( i == N-1 && j == N-1 ) break;
    lowerleft();
    bottom();
    if ( i == N-1 && j == N-1 ) break;
    upperright();
  }

}

void output(){
  for ( int i = 0; i < N; i++ ){
    for ( int j = 0; j < N; j++ ){
      printf("%3d", T[i][j]);
    }
    cout << endl;
  }
}

bool read(){
  cin >> N;
  if ( N == 0 ) return false;
  return true;
}

main(){
  for ( int tcase = 1; read(); tcase++ ){
    cout << "Case " << tcase << ":" << endl;
    work();
    output();
  }
}

