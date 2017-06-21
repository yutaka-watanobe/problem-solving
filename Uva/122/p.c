// @JUDGE_ID:  17051CA  122  C++
// @begin_of_source_code
/* Tree */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#include<map>

map<int, int> T;
map<int, bool>  U;

int maxNode;
bool completed;

void init(){
  completed = true;
  maxNode = 0;
  T = map<int, int>();
  U = map<int, bool>();
}

void parse(int v, string path){

  int index = 1;
  for(int i=0; i<path.size(); i++){
    if(path[i]=='L'){
      index = index*2;
    }else{
      index = index*2 + 1;
    }
  }

  maxNode = max(maxNode, index);
  
  if(U[index]) completed = false;
  U[index] = true;
  T[index] = v;
}

int read(){
  char ch, pre;
  pre = ' ';
  string str = "";
  int value = 0;

  init();
  
  while(1){
    cin >> ch;  if(cin.eof()) return 0;
    if(ch==','){
      value = atoi(str.c_str());
      str = "";
    }else if(ch==')'){
      if(pre=='(') return 1;
      parse(value, str);
      str = "";
    }else if(isdigit(ch) || isalpha(ch)){
      str += ch;
    }

    pre = ch;
  }

}

bool parse(){
  for(int i=maxNode; i>=2; i--){
    if(U[i] && !U[i/2]) return true;
  }
  return false;
}

void work(){

  if(parse()){
    completed = false;
  }

  if(completed){
    for(int i=1; i<=maxNode; i++){
      if(!U[i]) continue;
      if(i!=1) cout << " ";
      cout << T[i];
    }
    cout << endl;
  }else{
    cout << "not complete" << endl;
  }
}

main(){
  while(read()) work();
}
// @end_of_source_code
