// @JUDGE_ID:  17051CA  400  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<stl.h>
#include<stdlib.h>

int n;

int read(){
  cin >> n;
  if(cin.eof()) return 0;
  return 1;
}

void work(){
  int maxL, row, col, size;
  string line;
  set<string> list;
  vector<string> v;

  maxL = 0;
  for(int i=0; i<n; i++){
    cin >> line;
    int s = line.size();
    maxL = max(maxL, s);
    list.insert(line);
  }
  v.resize(list.size());
  copy(list.begin(), list.end(), v.begin());

  size = v.size();

  for(int i=0; i<size; i++){
    while(v[i].size()<maxL+2){
      v[i] += " ";
    }
  }

  col = 60/(maxL + 2);
  if(col==0) col = 1;
  row = size/col;
  if(size%col > 0 ) row++;
  cout << "------------------------------------------------------------" << endl;
  int j;
  for(int i=0; i<row; i++){
    j = i;
    while(1){
      if(j>=size) goto next;
      cout << v[j];
      j+=row;
    }
  next:;
    cout << endl;
  }

}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
