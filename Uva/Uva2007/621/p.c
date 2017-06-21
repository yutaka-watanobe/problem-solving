// @JUDGE_ID:  17051CA  621  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

void work(){
  string line;
  cin >> line;
  if(line=="1"||line=="4"||line=="78"){
    cout << "+" << endl;
  }else if(line.substr(line.size()-2)=="35"){
    cout << "-" << endl;
  }else if(line[0]=='9' && line[line.size()-1]=='4'){
    cout << "*" << endl;
  }else if(line.substr(0,3)=="190"){
    cout << "?" << endl;
  }
}

main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    work();
  }
}
// @end_of_source_code
