// @JUDGE_ID:  17051CA  414  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

int read();
void work();

int n;
string s;
vector<string> v;

int read(){
  cin >> n;
  if( n==0 ) return 0;
  return 1;
}

void work(){
  v.clear();
  int max;
  char nn;
  char buf[30];
  int c;
  cin.getline(buf, 30);
  max = 0;
  for(int i=0; i<n; i++){
    cin.getline(buf, 30);
    s = buf;
    v.push_back(s);
    c = count(s.begin(), s.end(), 'X');
    if( max < c ) max = c;
  }
  
  int remove;
  string line;
  int cs = 0;
  for(int i=0; i<v.size(); i++){
    line = v[i];
    remove = 25 - max;
    for(int j=0; j<25; j++){
      if( line[j] == ' ' ){
	if( remove <= 0 ) cs++;
	remove--;
      }
    }
  }

  cout << cs << endl;
}

main(){
  while( read() ){
    work();
  }
}
// @end_of_source_code
