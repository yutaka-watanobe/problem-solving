// @JUDGE_ID:  17051CA  10370  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<vector>

void work(){
  int k, value;
  scanf("%d", &k);
  vector<int> score;
  int sum = 0;
  for(int i=0; i<k; i++){
    scanf("%d", &value);
    score.push_back(value);
    sum += value;
  }

  int all = sconre.size();
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
  scanf("%d", &n);
  for(int i=0; i<n; i++) work();
}
// @end_of_source_code
