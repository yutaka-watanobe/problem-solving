// @JUDGE_ID:  17051CA  541  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

int matrix[101][101];
int n;

int read(){
  cin >> n;
  if(n==0) return 0;
  
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> matrix[i][j];
    }
  }
  return 1;
}

void work(){
  int row_cnt, col_cnt;
  int row_checked_cnt = 0;
  int col_checked_cnt = 0;
  int checked_row, checked_col;

  for(int i=0; i<n; i++){
    row_cnt = 0;
    for(int j=0; j<n; j++){
      if(matrix[i][j]==1) row_cnt++;
    }
    if(row_cnt%2!=0){
      row_checked_cnt++;
      checked_row = i;
    }
  }

  for(int j=0; j<n; j++){
    col_cnt = 0;
    for(int i=0; i<n; i++){
      if(matrix[i][j]==1) col_cnt++;
    }
    if(col_cnt%2!=0){
      col_checked_cnt++;
      checked_col = j;
    }
  }

  if(row_checked_cnt==0 && col_checked_cnt==0){
    cout << "OK" << endl;
  }else if(row_checked_cnt==1 && col_checked_cnt==1){
    cout << "Change bit (" << checked_row+1 << "," << checked_col+1 << ")" << endl;
  }else{
    cout << "Corrupt" << endl;
  }

}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
