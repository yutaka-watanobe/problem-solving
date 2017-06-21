// @JUDGE_ID:  17051CA  644  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

vector<string> v;

int read(){
  string line;

  v.clear();

  while(1){
    cin >> line;
    if(cin.eof()) return 0;
    if(line=="9")  return 1;
    v.push_back(line);
  }

}

void work(){
  string::size_type pos;

  for(int i=0; i<v.size(); i++){
    for(int j=0; j<v.size(); j++){
      if(i!=j){
	pos = v[j].find(v[i]);
	if(pos==0){
	  cout << " is not immediately decodable" << endl;
	  return;
	}
      }
    }
  }

  cout << " is immediately decodable" << endl;
}

main(){
  for(int i=1; read(); i++){
    cout << "Set " << i;
    work();
  }
}
// @end_of_source_code
