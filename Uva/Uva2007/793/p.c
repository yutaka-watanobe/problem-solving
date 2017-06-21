// @JUDGE_ID:  17051CA  793  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

void split(vector<string> &d, string &s, char c=' '){
  string t = "";
  for(int i=0; i<s.size(); i++){
    if(s[i]==c){
      if(t!=""){ d.push_back(t); t = "";}
    }
    else t += s[i];
  }
  if(t.size()) d.push_back(t);
}

class DisjointSet{
 public:
  vector<int> rank, p;

  DisjointSet(int size){
    rank.resize(size, 0);
    p.resize(size, 0);
  }

  void makeSet(int x){
    p[x] = x;
    rank[x] = 0;
  }

  void merge(int x, int y){
    link(findSet(x), findSet(y));
  }

  void link(int x, int y){
    if(rank[x] > rank[y]){
      p[y] = x;
    }else{   
      p[x] = y;
      if(rank[x] == rank[y]){
	rank[y] = rank[y] + 1;
      }
    }
  }

  int findSet(int x){
    if(x != p[x]){
      p[x] = findSet(p[x]);
    }
    return p[x];
  }
};

void work(){
  string line;
  int n;
  getline(cin, line);
  n = atoi(line.c_str());
  
  DisjointSet dset = DisjointSet(n);

  for(int i=0; i<n; i++){
    dset.makeSet(i);
  }

  int suc, unsuc;
  suc = unsuc = 0;

  while(1){
    getline(cin, line);
    if(line.size()==0 || cin.eof()) break;

    vector<string> com;
    com.clear();
    split(com, line);

    char c = com[0][0];
    int v1 = atoi( com[1].c_str() );
    int v2 = atoi( com[2].c_str() );
    
    v1--; v2--; /* for zero base */

    if( c=='c' ){
      dset.merge(v1, v2);
    }else{
      if(dset.findSet(v1) == dset.findSet(v2) ) suc++;
      else unsuc++;
    }
  }

  cout << suc << "," << unsuc << endl;
}


main(){
  char buf[10];
  int tcase;
  cin.getline(buf, 10);
  tcase = atoi(buf);
  cin.getline(buf, 10);
  for(int i=0; i<tcase; i++){
    if( i!=0 ) cout << endl;
    work();
  }
}
// @end_of_source_code
