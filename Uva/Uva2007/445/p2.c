// @JUDGE_ID:  17051CA  445 C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

void work();

void work(){
  string line;
  char c;
  int len;

  len = 0;
  while(1){
    getline(cin, line);
    if( cin.eof() ) return;

    if(line.size()==0) cout << endl;

    for(int i=0; i<line.size(); i++){
      c = line[i];
      if( isdigit(c) ) {
	int ic = c - '0';
	len += ic;
      }else{
	if(c=='!'){
	  cout << endl;
	}else if(c=='b'){
	  for(int j=0; j<len; j++) cout << " ";
	  len = 0;
	}else{
	  for(int j=0; j<len; j++) cout << c;
	  len = 0;
	}
      }

      if(i==line.size()-1) {
	if(line[i] != '!' ) cout << endl;
      }
    }
  }
}

main(){
  work();
}
// @end_of_source_code
