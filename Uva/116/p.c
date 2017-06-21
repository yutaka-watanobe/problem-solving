// @JUDGE_ID:  17051CA  116  C++
// @begin_of_source_code
/* Dynamic Programming */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
int M[11][101];
int P[11][101];
int m, n;

int read(){
  if(cin >> m >> n){
    for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
	cin >> M[i][j];
      }
    }
    return 1;
  }
  return 0;
}

void work(){
  int minimum;
  int index;
  for(int j=n-2; j>=0; j--){
    for(int i=0; i<m; i++){
      
      minimum = INT_MAX;
      index = 0;
      int ni;
      for(int d=-1; d<=1; d++){
	ni = i + d;
	if(ni<0) ni = m-1;
	else if(ni>=m) ni = 0;

	if(minimum > M[ni][j+1]){
	  minimum = M[ni][j+1];
	  index = ni;
	}else if( minimum == M[ni][j+1] ){
	  if(index > ni){
	    minimum = M[ni][j+1];
	    index = ni;
	  }
	}
      }

      M[i][j] = M[i][j] + minimum;
      P[i][j] = index;
    }
  }

  minimum = INT_MAX;
  index = 0;
  for(int i=0; i<m; i++){
    if(minimum > M[i][0]){
      minimum = M[i][0];
      index = i;
    }
  }

  cout << index+1;
  int i = index;
  int p;
  for(int j=0; j<n-1; j++){
    p = P[i][j];
    i = p;
    cout << " " << p+1;
  }
  cout << endl;
  cout << minimum << endl;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
