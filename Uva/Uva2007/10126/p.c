// @JUDGE_ID:  17051CA  10126  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
void tolower(string &s){
  for(int i=0; i<s.size(); i++){
    s[i] =tolower(s[i]);
  }
}

int read();
void work();

int n;

int read(){
  cin >> n;
  if(cin.eof()) return 0;
  return 1;
}

void work(){
  string line;
  map<string, int> mp;
  vector<string> v;
  set<string> goal;
  vector<string> g;
  v.clear();
  goal.clear();

  while(1){
    cin >> line;
    if(line=="EndOfText") break;
    tolower(line);
    string tmp = "";
    for(int k=0; k<line.size(); k++){
      if( isalpha(line[k]) &&  k!=line.size()-1){
	tmp = tmp+line[k];
      }else if(k==line.size()-1 && isalpha(line[k])){
	tmp = tmp+line[k];
	v.push_back(tmp);
	mp[tmp]++;
      }else if(!isalpha(line[k]) ){
	v.push_back(tmp);
	mp[tmp]++;
	tmp = "";
      }
    }

  }

  for(int i=0; i<v.size(); i++){
    bool isA = true;
    if( mp[ v[i] ] == n ){
      string s = v[i];
      for(int b=0; b<s.size(); b++){
	if( !isalpha(s[b]) ) isA = false;
      }
      if(isA && v[i].size() > 0) goal.insert( v[i] );
    }
  }

  if( goal.size()==0 ){
    cout << "There is no such word." << endl;
  }else{
    g.resize(goal.size());
    copy(goal.begin(), goal.end(), g.begin());
    for(int i=0; i<g.size(); i++){
      cout << g[i] << endl;
    }
  }
}

main(){
  for(int i=0; read(); i++){
    if( i!=0 ) cout << endl;
    work();
  }
}
// @end_of_source_code

