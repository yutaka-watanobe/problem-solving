// @JUDGE_ID:  17051CA  10415  C++
// @begin_of_source_code
/* 計算 （カウント）*/
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>

map<char, vector<bool> > T;

void init(){
  vector<bool> v;
  v.clear(); v.resize(11, false);
  v[2] = 1; v[3] = 1; v[4] = 1; v[7] = 1; v[8] = 1; v[9] = 1; v[10] = 1;
  T['c'] = v;

  v.clear(); v.resize(11, false);
  v[2] = 1; v[3] = 1; v[4] = 1; v[7] = 1; v[8] = 1; v[9] = 1;
  T['d'] = v;

  v.clear(); v.resize(11, false);
  v[2] = 1; v[3] = 1; v[4] = 1; v[7] = 1; v[8] = 1;
  T['e'] = v;

  v.clear(); v.resize(11, false);
  v[2] = 1; v[3] = 1; v[4] = 1; v[7] = 1;
  T['f'] = v;

  v.clear(); v.resize(11, false);
  v[2] = 1; v[3] = 1; v[4] = 1;
  T['g'] = v;

  v.clear(); v.resize(11, false);
  v[2] = 1; v[3] = 1; 
  T['a'] = v;

  v.clear(); v.resize(11, false);
  v[2] = 1;
  T['b'] = v;

  v.clear(); v.resize(11, false);
  v[3] = 1;
  T['C'] = v;

  v.clear(); v.resize(11, false);
  v[1] = 1; v[2] = 1; v[3] = 1; v[4] = 1; v[7] = 1; v[8] = 1; v[9] = 1;
  T['D'] = v;

  v.clear(); v.resize(11, false);
  v[1] = 1; v[2] = 1; v[3] = 1; v[4] = 1; v[7] = 1; v[8] = 1;
  T['E'] = v;

  v.clear(); v.resize(11, false);
  v[1] = 1; v[2] = 1; v[3] = 1; v[4] = 1; v[7] = 1;
  T['F'] = v;

  v.clear(); v.resize(11, false);
  v[1] = 1; v[2] = 1; v[3] = 1; v[4] = 1;
  T['G'] = v;

  v.clear(); v.resize(11, false);
  v[1] = 1; v[2] = 1; v[3] = 1;
  T['A'] = v;

  v.clear(); v.resize(11, false);
  v[1] = 1; v[2] = 1;
  T['B'] = v;
}

void work(){
  vector<int> F, Fc;
  F.resize(11, 0);
  Fc.resize(11, 0);
  
  string line;
  getline(cin, line);
  
  char ch;
  for(int i=0; i<line.size(); i++){
    ch = line[i];
    
    vector<bool> f = T[ch];
    for(int i=1; i<=10; i++){
      if(f[i]){
	if(F[i]==0) Fc[i]++;
	F[i] = 1;
      }else{
	F[i] = 0;
      }
    }
  }

  for(int i=1; i<=10; i++){
    if(i!=1) cout << " ";
    cout << Fc[i];
  }
  cout << endl;
  
}

main(){
  init();
  int t;
  string line;
  getline(cin, line);
  t = atoi(line.c_str());
  for(int i=0; i<t; i++){
    work();
  }
}
// @end_of_source_code
