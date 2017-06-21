// @JUDGE_ID:  17051CA  487  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<set>

void work();
void rec(int, int, string);

char grid[25][25];
set<string> word;

int n;
int m;

void work(){
  string line;
  cin >> n;

  for(int i=0; i<n; i++){
    cin >> line;
    for(int j=0; j<n; j++){
      grid[i][j] = line[j];
    }
  }

  word.clear();
  string s;
  m = 1000;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      s = "";
      s += grid[i][j];
      rec(i, j, s);
    }
  }

  vector<string> v;
  v.resize(word.size());
  copy(word.begin(), word.end(), v.begin());

  int start = m;
  while(1){
    if(v.size()==0) return;
    for(int i=0; i<v.size(); ){
      if( v[i].size()==start ){
	cout << v[i] << endl;
	v.erase(v.begin()+i);
      }else{ i++;}
    }
    start++;
  }
}

void rec(int i, int j, string str){
  char c1, c2;
  string strt;
  int ii, jj, ni, nj;
  for(int d=0; d<8; d++){
    ii = jj = 0;
    if(d==0) { ii++; jj++; }
    if(d==1) { ii--; jj--; }
    if(d==2) { ii--; jj++; }
    if(d==3) { ii++; jj--; }
    if(d==4) { ii++; }
    if(d==5) { jj++; }
    if(d==6) { ii--; }
    if(d==7) { jj--; }
    ni = ii + i; nj = jj + j;
    if( ni >=0 && nj >= 0 && ni < n && nj < n){
      c1 = str[str.size()-1];
      c2 = grid[ni][nj];
      if( c1 < c2 ){
	strt = str;
	strt += c2;
	rec(ni, nj, strt);
      }
    }
  }

  if( 3 <= str.size() && str.size() <= n*n ){
    if( m > str.size() ) m = str.size();
    word.insert(str);
  }

}

main(){
  int testCase;
  cin >> testCase;

  for(int i=0; i<testCase; i++){
    if(i!=0) cout << endl;
    work();
  }
}
// @end_of_source_code
