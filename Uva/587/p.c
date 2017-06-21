// @JUDGE_ID:  17051CA  587  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>

string line;

double px, py;

int read(){
  cin >> line;
  if(line=="END") return 0;
  return 1;
}

void put(string s){
  //cout << "put " << s << endl;
  string sv, dir;
  sv = dir = "";
  for(int i=0; i<s.size(); i++){
    if(isalpha(s[i])) dir += s[i];
    else sv += s[i];
  }

  int val = atoi(sv.c_str());
  double dig = val/(sqrt(2.0));

  if(dir=="E"){
    px += val;
  }else if(dir=="N"){
    py += val;
  }else if(dir=="W"){
    px -= val;
  }else if(dir=="S"){
    py -= val;
  }else if(dir=="NE"){
    px += dig;
    py += dig;
  }else if(dir=="NW"){
    px -= dig;
    py += dig;
  }else if(dir=="SW"){
    px -= dig;
    py -= dig;
  }else if(dir=="SE"){
    px += dig;
    py -= dig;
  }

}

void work(){
  px = py = 0;
  int i = 0;
  char c;
  string s = "";
  while(1){
    c = line[i];
    if(c=='.'){
      put(s);
      break;
    }else if(c==','){
      put(s);
      s = "";
    }else{
      s += c;
    }
    i++;
  }

  printf("The treasure is located at (%.3f,%.3f).\n", px, py);
  double d = sqrt(px*px + py*py);
  printf("The distance to the treasure is %.3f.\n", d);
}

main(){
  for(int i=1; read(); i++){
    cout << "Map #" << i << endl;
    work();
    cout << endl;
  }
}
// @end_of_source_code
