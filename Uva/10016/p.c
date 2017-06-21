// @JUDGE_ID:  17051CA  10016  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#define MAX 105

int grid[MAX][MAX];
int temp[MAX][MAX];
int N;
int ring;

void work(int i);
void read(){
  int k;
  cin >> N;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin >> k;
      grid[i][j] = k;
    }
  }

  if(N%2==0) ring = N/2;
  else ring = N/2+1;

  for(int i=0; i<ring; i++){
    /*    cout << "work " << i+1 << endl;*/
    work(i);
  }
  
}

int n, sp;

void createTemp(int r){
  n = N - 2*r;
  int i, j;
  i = j = r;
  for(j=r; j<r+n; j++){
    temp[i][j] = grid[i][j];
    temp[i+n-1][j] = grid[i+n-1][j];
  }
  i = j = r;
  for(i=r; i<r+n; i++){
    temp[i][j] = grid[i][j];
    temp[i][j+n-1] = grid[i][j+n-1];
  }
}

void upsideDown(int r){
  n = N - 2*r;
  if(n<=1) return;
  int i, j;
  i = j = r;
  for(int s=0; s<n; s++){
    grid[i][j] = temp[r+n-1-s][j];
    grid[i][j+n-1] = temp[r+n-1-s][j+n-1];
    i++;
  }
  i = j = r;
  for(j=r; j<r+n; j++){
    grid[i][j] = temp[i+n-1][j];
    grid[i+n-1][j] = temp[i][j];
  }
}

void leftRight(int r){
  n = N - 2*r;
  if(n<=1) return;
  int i, j;
  i = j = r;
  for(i=r; i<r+n; i++){
    grid[i][j] = temp[i][j+n-1];
    grid[i][j+n-1] = temp[i][j];
  }
  i = j = r;
  for(int s=0; s<n; s++){
    grid[i][j] = temp[i][r+n-1-s];
    grid[i+n-1][j] = temp[i+n-1][r+n-1-s];
    j++;
  }
}

void mainDiagonal(int r){
  n = N - 2*r;
  if(n<=1) return;
  int i, j;
  i = j = r;
  for(int s=0; s<n; s++){
    grid[i][j] = temp[j][i];
    i++;
  }
  i = j = r;
  for(int s=0; s<n; s++){
    grid[i][j] = temp[j][i];
    j++;
  }

  i = j = r + n - 1;
  for(int s=0; s<n-1; s++){
    grid[i][j] = temp[j][i];
    i--;
  }
  i = j = r + n - 1;
  for(int s=0; s<n-1; s++){
    grid[i][j] = temp[j][i];
    j--;
  }
}

void inverseDiagonal(int r){
  n = N - 2*r;
  if(n<=1) return;
  int i, j;
  i = r;
  j = r + n - 1;
  for(int s=0; s<n; s++){
    grid[i-s][j-s] = temp[i][j];
    i++;
  }
  i = r;
  j = r + n - 1;
  for(int s=0; s<n; s++){
    grid[i+s][j+s] = temp[i][j];
    j--;
  }
  i = r + n - 1;
  j = r;
  for(int s=0; s<n-1; s++){
    grid[i+s][j+s] = temp[i][j];
    i--;
  }
  i = r + n - 1;
  j = r;
  for(int s=0; s<n-1; s++){
    grid[i-s][j-s] = temp[i][j];
    j++;
  }
}

void work(int r){
  int C, M;
  cin >> C;
  for(int i=0; i<C; i++){
    cin >> M;
    createTemp(r);
    if(M==1) upsideDown(r);
    else if(M==2) leftRight(r);
    else if(M==3) mainDiagonal(r);
    else if(M==4) inverseDiagonal(r);
    /*
    cout << "trase after " << M << endl;
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
	if(j!=0) cout << " ";
	cout << grid[i][j];
      }
      cout << endl;
    }
    */
  }

}

main(){
  int testCase;
  cin >> testCase;
  for(int i=0; i<testCase; i++){
    read();
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
	if(j!=0) cout << " ";
	cout << grid[i][j];
      }
      cout << endl;
    }
  }
}
// @end_of_source_code
