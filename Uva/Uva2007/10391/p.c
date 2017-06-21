// @JUDGE_ID:  17051CA  10391  C++
// @begin_of_source_code
/* Search */
/* binary search ¤ò¶î»È */

#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

vector<string> dic;

int read(){
  string line;

  while(1){
    cin >> line;
    if(cin.eof()) break;
    dic.push_back(line);
  }
  return 1;
}

void work(){
  vector<string> g;
  vector<bool> used;

  string::size_type index;
  used.resize(dic.size(), false);

  for(int i=0; i<dic.size(); i++){
    for(int j=i+1; j<dic.size(); j++){
      index = dic[j].find(dic[i]);
      if(index==string::npos ) goto next;
      if(binary_search(dic.begin(), dic.end(), dic[j].substr(dic[i].size()) )){
	if(!used[j]) g.push_back(dic[j]);
	used[j] = true;
      }
    }
  next:;
  }

  sort(g.begin(), g.end());
  for(int i=0; i<g.size(); i++){
    cout << g[i] << endl;
  }

}

main(){
  read();
  work();
}
// @end_of_source_code
