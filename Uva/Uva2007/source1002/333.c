// @JUDGE_ID:  17051CA  333  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

void trim(string &s){
  int l, r;
  l = s.find_first_not_of(" \n\r");
  r = s.find_last_not_of(" \n\r");
  if(l<0 || s.size()<=l) s = "";
  else s = s.substr(l, r-l+1);
}

bool isDigit(char c){
  if( 48 <= c && c <= 57 || c == 'X') return true;
  else return false;
}

void work();

void work(){
  char buf[1000];
  string line;
  vector<int> s0, s1, s2;
  while(1){
    cin.getline(buf, 1000);
    if( cin.eof() ) return;
    
    line = buf;
    trim(line);
    
    cout << line <<  " is ";

    s0.clear();
    s1.clear(); s1.resize(10);
    s2.clear(); s2.resize(10);

    for(int i=0; i<line.size(); i++){
      string c = line.substr(i, 1);
      if(isDigit(c[0])){
	if( c=="X" ) s0.push_back(10);
	else s0.push_back( atoi( c.c_str() ));
      }
    }
    
    /* check */
    for(int i=0; i<s0.size(); i++){
      if( (0 <= i && i <= 8) && s0[i] >= 10 ){
	cout << "incorrect." << endl;
	goto next;
      }
    }


    if( s0.size() != 10 ){
      cout << "incorrect." << endl;
    }else{
      s1[0] = s0[0];
      for(int i=1; i<s1.size(); i++){
	s1[i] = s1[i-1] + s0[i];
      }
      s2[0] = s1[0];
      for(int i=1; i<s2.size(); i++){
	s2[i] = s2[i-1] + s1[i];
      }
      if( s2[9]%11==0 ) cout << "correct." << endl;
      else cout << "incorrect." << endl;
    }

  next:;
  }
}

main(){
  work();
}
// @end_of_source_code
