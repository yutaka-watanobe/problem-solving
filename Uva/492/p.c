// @JUDGE_ID:  17051CA  492  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

void doPig(string &s){
  if(s.size()==0) return;
  char c;
  c = s[0];
  if(!isalpha(c) ) return;
  if(c=='a' || c=='i' || c=='u' || c=='e' || c=='o' ||
     c=='A' || c=='I' || c=='U' || c=='E' || c=='O' ){
    s += "ay";
  } else {
    char f = s[0];
    s.erase(s.begin()+0);
    s = s + f + "ay";
  }
}

void work(){
  string line;
  string str;
  char ch;
  while(1){
    getline(cin, line);
    if(cin.eof()) return ;
    str = "";

    for(int i=0; i<line.size(); i++){
      ch = line[i];
      if(!isalpha(ch) || i==line.size()-1 ){
	if(i==line.size()-1){
	  if(!isalpha(ch)){
	    doPig(str);
	    cout << str + ch;
	    cout << endl;
	  }else{
	    str += ch;
	    doPig(str);
	    cout << str;
	    cout << endl;
	  }
	}else{
	  doPig(str);
	  cout << str + ch;
	}
	str = "";
      }else{
	str += ch;
      }
    }
    
  }


}

main(){
  work();
}
// @end_of_source_code
