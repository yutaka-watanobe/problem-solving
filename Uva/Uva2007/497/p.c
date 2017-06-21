// @JUDGE_ID:  17051CA  497  C++
// @begin_of_source_code
#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

string line;

int lis(vector<int> &v, vector<int> &p, int &e){

  vector<int> l;
  l.resize(v.size());
  p.resize(v.size());
  l[0] = 0;
  p[0] = -1;
  for(int i=0; i<v.size(); i++){
    int m = 0;
    p[i] = -1;
    for(int j=0; j<i; j++){
      if(v[j]<v[i] && m<l[j]){
        m = l[j];
	p[i] = j;
      }
    }
    l[i] = m + 1;
  }
  int me = 0;
  for(int i=0; i<l.size(); i++){
    if(me<l[i]){ me = l[i]; e = i;}
  }

  return me;
}

void work(){
  vector<int> v;
  
  while(1){
    getline(cin, line);
    if(line.size()==0 || cin.eof()) break;
    v.push_back(atoi(line.c_str()));
  }

  vector<int> p;
  int e;
  cout << "Max hits: " << lis(v, p, e) << endl;

  vector<int> path;

  while(1){
    if(e==-1) break;
    path.push_back(v[e]);
    e = p[e];
  }

  reverse(path.begin(), path.end());
  for(int i=0; i<path.size(); i++) cout << path[i] << endl;
}

main(){
  int testCase;
  getline(cin , line);
  testCase = atoi(line.c_str());
  getline(cin , line);
  for(int i=0; i<testCase; i++){
    if(i!=0) cout << endl;
    work();
  }
}
// @end_of_source_code
