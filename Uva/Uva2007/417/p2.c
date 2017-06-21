// @JUDGE_ID:  17051CA  417  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>

string line;

map<string, int> m1, m2, m3, m4, m5;

int read(){
  cin >> line;
  if(cin.eof()) return 0;
  return 1;
}

void work(){
  if(line.size()==1){
    cout << m1[line] << endl;
  }else if(line.size()==2){
    cout << m2[line] << endl;
  }else if(line.size()==3){
    cout << m3[line] << endl;
  }else if(line.size()==4){
    cout << m4[line] << endl;
  }else if(line.size()==5){
    cout << m5[line] << endl;
  }
}

main(){
  vector<string> v;
  int index = 1;
  string s = "";

  map<string, int>::iterator pos;

  string ss;
  char sc;
  int size;
  for(char c='a'; c<='z'; c++){
    m1[s+c] = index++;
  }

  for(pos = m1.begin(); pos != m1.end(); ++pos){
    ss = pos->first;
    sc = ss[0] + 1;
    for(char c= sc; c<='z'; c++){
      m2[ ss + c ] = index++;
    }
  }

  for(pos = m2.begin(); pos != m2.end(); ++pos){
    ss = pos->first;
    sc = ss[1] + 1;
    for(char c= sc; c<='z'; c++){
      m3[ ss + c ] = index++;
    }
  }

  for(pos = m3.begin(); pos != m3.end(); ++pos){
    ss = pos->first;
    sc = ss[2] + 1;
    for(char c= sc; c<='z'; c++){
      m4[ ss + c ] = index++;
    }
  }

  for(pos = m4.begin(); pos != m4.end(); ++pos){
    ss = pos->first;
    sc = ss[3] + 1;
    for(char c= sc; c<='z'; c++){
      m5[ ss + c ] = index++;
    }
  }

  while(read()){
    work();
  }
}
// @end_of_source_code
