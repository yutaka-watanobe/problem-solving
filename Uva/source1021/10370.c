// @JUDGE_ID:  17051CA  10370  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

void work();

void work(){
  int n, k;
  cin >> n;
  vector<int> score;
  score.clear();
  int sum = 0;
  for(int i=0; i<n; i++){
    cin >> k;
    score.push_back(k);
    sum+=k;
  }

  int all = score.size();
  float ave = sum/all;
  
  int abo = 0;
  for(int i=0; i<score.size(); i++){
    if( score[i] > ave ) abo++;
  }
  
  printf("%.3f", (float)abo/all*100 );
  cout << "%" << endl;
  
}

main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++) work();
}
// @end_of_source_code
