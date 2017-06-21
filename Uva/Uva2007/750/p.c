// @JUDGE_ID:  17051CA  750  C++
// @begin_of_source_code
/* 8 Queen Problem */
/* 0.006 sec */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#define N 8
#define SUCCESS 1
#define FAIL 0
#define FREE 1
#define NOT_FREE 0

int row[N], col[N], pos[2*N-1], neg[2*N-1];
vector<vector<int> > pattern;

void print(){
  vector<int> q;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(row[i]==j) q.push_back(j+1);
//      else q.push_back(0);
    }
  }
  pattern.push_back(q);
}

void tryqueen(int i, int j){

  if(!(col[j]==FREE && pos[i+j]==FREE && neg[i-j+N-1]==FREE))
    return;
  
  row[i] = j; 
  col[j] = NOT_FREE;
  pos[i+j] = NOT_FREE;
  neg[i-j+N-1] = NOT_FREE;
  
  if(i==N-1) print();
  else{
    for(int z=0; z<N; z++){
      tryqueen(i+1, z);
    }
  }
  row[i] = -1;
  col[j] = FREE;
  pos[i+j] = FREE;
  neg[i-j+N-1] = FREE;
}

void init(){
  for(int i=0; i<N; i++) {row[i] = -1; col[i] = FREE;}
  for(int i=0; i<2*N-1; i++){pos[i] = FREE; neg[i] = FREE;}
  for(int j=0; j<N; j++){
    tryqueen(0, j);
  }
}

void work(){
  int x, y;
  cin >> x >> y;
  cout << "SOLN       COLUMN" << endl;
  cout << " #      1 2 3 4 5 6 7 8" << endl;
  cout << endl;
  int index = 1;
  for(int i=0; i<pattern.size(); i++){
    if(pattern[i][y-1]==x){
      cout << " " << index << "      ";
      for(int j=0; j<8; j++){
	if(j) cout << " ";
	cout << pattern[i][j];
      }
      cout << endl;
      index++;
    }
  }

}

main(){
  init();
  int t;
  cin >> t;
  for(int i=0; i<t; i++){
    work();
    cout << endl;
  }
}
// @end_of_source_code
