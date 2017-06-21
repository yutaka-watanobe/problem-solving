// @JUDGE_ID:  17051CA  499  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<stl.h>
#include<map>

void work();

void work(){
  string line;
  set<char> all;
  vector<char> v;
  vector<char> g;

  while(1){
    getline(cin, line);
    if(cin.eof()) return;
    map<char,int> mp;
    all.clear();
    for(int i=0; i<line.size(); i++){
      char c = line[i];
      if( isalpha(c) ){
	mp[c]++;
	all.insert(c);
      }
    }
    
    v.clear();
    g.clear();
    v.resize(all.size());
    copy(all.begin(), all.end(), v.begin());
    int max = 0;
    for(int i=0; i<v.size(); i++){
      if( max < mp[ v[i] ] ) max = mp[ v[i] ];
    }

    for(int i=0; i<v.size(); i++){
      if( mp[v[i]] == max ){
	g.push_back(v[i]);
      }
    }

    sort(g.begin(), g.end());
    
    for(int i=0; i<g.size(); i++) cout << g[i];
    cout << " " << max << endl;
  }
}

main(){
  work();
}
// @end_of_source_code
