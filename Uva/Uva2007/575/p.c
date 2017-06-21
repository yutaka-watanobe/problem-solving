// @JUDGE_ID:  17051CA  575  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>

string line;

int read(){
  cin >> line;
  if(line=="0") return 0;
  return 1;
}

void work(){
  vector<int> v;
  v.resize(line.size());

  for(int i=0; i<line.size(); i++){
    char c = line[i];
    if(c=='0') v[i] = 0;
    else if(c=='1') v[i] = 1;
    else v[i] = 2;
  }

  long sum = 0;
  int size = v.size();
  unsigned int p = 2;
  for(int i=size-1; i>=0; i--, p *= 2){
    sum += v[i] * (p-1);
  }

  cout << sum << endl;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
