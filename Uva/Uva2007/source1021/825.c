// @JUDGE_ID:  17051CA  825  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

/*
 * stringオブジェクトを1文字のデリミタ(デフォルトは空白)で区切る
 * 要件: #include <string>, #include <stl.h>
 */
void split(vector<string> &d, const string &s, char c=' '){
  string t = "";

  for(int i=0; i<s.size(); i++){    
    if(s[i]==c){
      if(t!=""){ d.push_back(t); t = ""; }
    }
    else t += s[i];
  }
  if(t.size()) d.push_back(t);
}

int read();
void work();

vector<vector<int> > grid;

void work(){
  string line;
  getline(cin, line);
  getline(cin, line);
  vector<string> com;
  com.clear();
  
  split(com, line);

  int h, w;
  h = atoi(com[0].c_str());
  w = atoi(com[1].c_str());

  grid.resize(h);
  for(int i=0; i<h; i++) grid[i].resize(w);

  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      grid[i][j] = -1;
    }
  }

  for(int i=0; i<h; i++){
    getline(cin, line);
    com.clear();
    split(com, line);
    
    for(int j=1; j<com.size(); j++){
      grid[i][atoi(com[j].c_str())-1] = 0;
    }
  }
  
  grid[h-1][w-1] = 1;

  for(int i=h-1; i>=0; i--){
    for(int j=w-1; j>=0; j--){
      if(grid[i][j]==-1){
	int ii, jj, r, b;
	/* right */
	ii = i; jj = j+1;
	if(jj < w) {
	  r = grid[ii][jj];
	}else r = 0;
	/* bottom */
	ii = i+1; jj = j;
	if(ii < h) {
	  b = grid[ii][jj];
	}else b = 0;
	grid[i][j] = r + b;
      }
    }
  }

  cout << grid[0][0] << endl;
}

main(){
  char buff[1000];
  cin.getline(buff, 1000);
  int n = atoi(buff);
  for(int i=0; i<n; i++){
    if(i!=0) cout << endl;
    work();
  }
}
// @end_of_source_code
