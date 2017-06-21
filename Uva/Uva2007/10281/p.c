// @JUDGE_ID:  17051CA  10281  C++
// @begin_of_source_code
/* Simulation */
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

string line;
int current_speed;
double total_distance;
int hh, mm, ss;

void init(){
  current_speed = 0;
  total_distance = 0;
  hh = mm = ss = 0;
}

int read(){
  getline( cin, line );
  if ( cin.eof() ) return 0;
  return 1;
}

void work(){
  vector<string> com;
  split(com, line);

  int h, m, s;

  string elapse = com[0];
  h = atoi(elapse.substr(0, 2).c_str());
  m = atoi(elapse.substr(3, 2).c_str());
  s = atoi(elapse.substr(6, 2).c_str());
    
  total_distance += current_speed * (h - hh);
  total_distance += current_speed * (m - mm)/60.0;
  total_distance += current_speed * (s - ss)/3600.0;

  if(com.size()==1){ /* query */
    cout << com[0] << " ";
    printf("%.2f", total_distance);
    cout << " km" << endl;
  }else{ /* change speed */
    current_speed = atoi( com[1].c_str() );
  }

  hh = h; mm = m; ss = s;
}

main(){
  init();
  while ( read() ){
    work();
  }
}
// @end_of_source_code
