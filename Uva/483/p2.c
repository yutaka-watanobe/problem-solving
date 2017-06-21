// @JUDGE_ID:  17051CA  483  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#include<vector>

void work();

void work(){
  string line, str;

  while(1){
    getline(cin, line);
    if(cin.eof()) break;
    
    if( line.size()==0 ) {cout << endl; continue;}
    str = "";
    for(int s=0; s<line.size(); s++){

      if( line[s]==' '){
	if(s==line.size()-1){
	  reverse(str.begin(), str.end());
	  cout << str;
	  str = "";
	  cout << " ";
	  cout << endl;
	}else{
	  reverse(str.begin(), str.end());
	  cout << str;
	  str = "";
	  cout << " ";
	}
      }else if(s==line.size()-1){
	str += line[s];
	reverse(str.begin(), str.end());
	cout << str;
	str = "";
	cout << endl;
      }else{
	str += line[s];
      }
    }
  }
}

main(){
  work();
}
// @end_of_source_code
