// @JUDGE_ID:  17051CA  673  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

void work(){
  string line;
  getline(cin, line);

  if(line.size()==0){
    cout << "Yes" << endl;
    return;
  }

  while(1){
    for(int s=0; s<line.size()-1; s++){
      if( (line[s]=='(' && line[s+1]==')') || (line[s]=='[' && line[s+1]==']')){
	line.erase(line.begin()+s);
	line.erase(line.begin()+s);
	if(line.size()==0){
	  cout << "Yes" << endl;
	  return;
	}
	goto next;
      } 
    }
    cout << "No" << endl;
    return;
  next:;
  }

}

main(){
  string str;
  getline(cin, str);
  int n;
  n = atoi(str.c_str());
  for(int i=0; i<n; i++){
    work();
  }
}
// @end_of_source_code
