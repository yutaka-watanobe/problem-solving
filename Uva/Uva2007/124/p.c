// @JUDGE_ID:  17051CA  124  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

void split(vector<char> &v, string line){
  v.clear();
  for(int i=0; i<line.size(); i++){
    if(isalpha(line[i])){
      v.push_back(line[i]);
    }
  }
}

vector<char> v;
vector<vector<int> > adj;
vector<bool> used;

map<char, int> mp;
map<int, char> mp2;

int read(){
  string line;
  char c;
  mp = map<char, int>();
  
  getline(cin, line);
  if(cin.eof()) return 0;
  split(v, line);
  sort(v.begin(), v.end());

  for(int i=0; i<v.size(); i++){
    mp[v[i]] = i;
    mp2[i] = v[i];
  }

  adj.clear();
  adj.resize(v.size());

  getline(cin, line);
  vector<char> link;
  split(link, line);
  int source, target;
  for(int i=0; i<link.size()-1; i+=2){
    source = mp[link[i]];
    target = mp[link[i+1]];
    adj[target].push_back(source);
  }

  return 1;
}

void dfs(int s, vector<bool> used, vector<char> path);

void work(){
  used.resize(v.size(), false);
  vector<char> path;
  for(int i=0; i<v.size(); i++){
    dfs(i, used, path);
  }

}

void dfs(int s, vector<bool> used, vector<char> path){
  used[s] = true;
  path.push_back(mp2[s]);

  for(int j=0; j<adj[s].size(); j++){
    if(used[adj[s][j]]==false) return;
  }

  if(path.size()==v.size()){
  for(int i=0; i<v.size(); i++) cout << path[i];
    cout << endl;
    return;
  }

  for(int i=0; i<v.size(); i++){
    if(!used[i]) dfs(i, used, path);
  }
}

main(){
  for(int i=0; read(); i++){
    if(i!=0) cout << endl;
    work();
  }
}
// @end_of_source_code
